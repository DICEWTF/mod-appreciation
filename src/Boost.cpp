#include "Boost.h"

#include "Config.h"
#include "BoostFlightPaths.h"
#include "BoostSkills.h"
#include "BoostSpells.h"
#include "BoostEquipment.h"

void Boost::BoostPlayer(Player *player, uint8 specialization)
{
  // Get level
  uint32 targetLevel = sConfigMgr->GetOption<uint32>("Boost.Level", 80);
  if (targetLevel != 60 && targetLevel != 70 && targetLevel != 80)
  {
    targetLevel = 80;
  }

  // Log
  LOG_INFO("module.appreciation", "Applying boost on character '{}' from account #{}.", player->GetName(), player->GetSession()->GetAccountId());

  // Boost
  Boost::GiveLevel(player, targetLevel);
  Boost::GiveGold(player);
  Boost::GiveEquipment(player, specialization, targetLevel);
  Boost::GiveBags(player);
  Boost::ResetTalents(player);
  Boost::GiveProficiencies(player);
  Boost::GiveRiding(player);
  Boost::GiveMounts(player);
  Boost::GiveSpells(player);
  Boost::GiveDualSpec(player);
  Boost::UnlockFlightPaths(player);
  Boost::GiveReputation(player);
  Boost::BindHeartstone(player);
  Boost::Teleport(player);
}

void Boost::GiveLevel(Player *player, uint32 targetLevel)
{
  if (player->GetLevel() >= targetLevel)
  {
    return;
  }

  player->GiveLevel(targetLevel);
  player->SetUInt32Value(PLAYER_XP, 0);
}

void Boost::GiveGold(Player *player)
{
  uint32 gold = sConfigMgr->GetOption<uint32>("Boost.Gold", 250);

  if (gold <= 0)
  {
    return;
  }

  player->ModifyMoney(gold * 10000);
}

void Boost::GiveEquipment(Player *player, uint8 specialization, uint32 targetLevel)
{
  uint32 giveEquipment = sConfigMgr->GetOption<uint32>("Boost.Equipment", 1);

  if (giveEquipment <= 0)
  {
    return;
  }
  BoostEquipment::EquipPlayer(player, specialization, targetLevel);
}

void Boost::GiveBags(Player *player)
{
  uint32 guid = player->GetGUID().GetCounter();

  CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
  MailDraft *mail = new MailDraft("Some bags to help you", "Here are some bags to help you with your character boost.");
  ItemTemplate const *pProto = sObjectMgr->GetItemTemplate(21843);

  if (pProto)
  {
    for (uint8 i = 0; i < 4; ++i)
    {
      Item *mailItem = Item::CreateItem(21843, 1);
      if (mailItem)
      {
        mailItem->SaveToDB(trans);
        mail->AddItem(mailItem);
      }
    }
  }

  mail->SendMailTo(trans, player ? player : MailReceiver(guid), MailSender(MAIL_NORMAL, 0, MAIL_STATIONERY_GM), MAIL_CHECK_MASK_RETURNED);
  delete mail;
  CharacterDatabase.CommitTransaction(trans);
}

void Boost::ResetTalents(Player *player)
{
  // Player talents
  player->resetTalents(true);
  player->SendTalentsInfoData(false);

  // Client-side popup
  WorldPacket data(SMSG_TALENTS_INVOLUNTARILY_RESET, 1);
  data << uint8(0);
  player->SendMessageToSet(&data, true);
}

void Boost::GiveProficiencies(Player *player)
{
  uint32 giveProficiencies = sConfigMgr->GetOption<uint32>("Boost.Proficiencies", 1);

  if (giveProficiencies <= 0)
  {
    return;
  }
  BoostSkills::UpdateSkills(player);
}

void Boost::GiveSpells(Player *player)
{
  uint32 giveSpells = sConfigMgr->GetOption<uint32>("Boost.Spells", 1);

  if (giveSpells <= 0)
  {
    return;
  }
  BoostSpells::LearnSpells(player);
}

void Boost::GiveDualSpec(Player *player)
{
  uint32 giveDualSpec = sConfigMgr->GetOption<uint32>("Boost.DualSpec", 1);

  if (giveDualSpec <= 0)
  {
    return;
  }
  player->CastSpell(player, 63680, true, nullptr, nullptr, player->GetGUID());
  player->CastSpell(player, 63624, true, nullptr, nullptr, player->GetGUID());
  player->UpdateSpecCount(2);
}

void Boost::GiveRiding(Player *player)
{
  uint32 ridingLevel = sConfigMgr->GetOption<uint32>("Boost.Riding", 3);

  if (ridingLevel <= 0)
  {
    return;
  }
  if (ridingLevel >= 1)
  {
    player->learnSpell(33388); // Apprentice Riding (60% ground)
  }
  if (ridingLevel >= 2)
  {
    player->learnSpell(33391); // Journeyman Riding (100% ground)
  }
  if (ridingLevel >= 3)
  {
    player->learnSpell(34090); // Expert Riding (150% fly)
  }
  if (ridingLevel >= 4)
  {
    player->learnSpell(34091); // Artisan Riding (280/310% fly)
  }

  uint32 coldFlying = sConfigMgr->GetOption<uint32>("Boost.ColdFlying", 1);
  if (coldFlying >= 1)
  {
    player->learnSpell(54197); // Northend flying
  }
}

void Boost::GiveMounts(Player *player)
{
  uint32 mountHordeGround = sConfigMgr->GetOption<uint32>("Boost.Mounts.Horde.Ground", 23251);
  uint32 mountHordeFly = sConfigMgr->GetOption<uint32>("Boost.Mounts.Horde.Fly", 32243);
  uint32 mountAllianceGround = sConfigMgr->GetOption<uint32>("Boost.Mounts.Alliance.Ground", 23229);
  uint32 mountAllianceFly = sConfigMgr->GetOption<uint32>("Boost.Mounts.Alliance.Fly", 32240);

  if (player->GetTeamId() == TEAM_HORDE)
  {
    if (mountHordeGround > 0)
    {
      player->learnSpell(mountHordeGround);
    }
    if (mountHordeFly > 0)
    {
      player->learnSpell(mountHordeFly);
    }
  }
  else
  {
    if (mountAllianceGround > 0)
    {
      player->learnSpell(mountAllianceGround);
    }
    if (mountAllianceFly > 0)
    {
      player->learnSpell(mountAllianceFly);
    }
  }
}

void Boost::UnlockFlightPaths(Player *player)
{
  uint32 flightEasternKingdoms = sConfigMgr->GetOption<uint32>("Boost.FlightPaths.EasternKingdoms", 1);
  uint32 flightKalimdor = sConfigMgr->GetOption<uint32>("Boost.FlightPaths.Kalimdor", 1);
  uint32 flightOutland = sConfigMgr->GetOption<uint32>("Boost.FlightPaths.Outland", 1);
  uint32 flightNorthend = sConfigMgr->GetOption<uint32>("Boost.FlightPaths.Northend", 1);

  if (flightEasternKingdoms > 0)
  {
    BoostFlightPaths::UnlockFlightPaths(player, BOOST_FLIGHTPATHS_EASTERN_KINGDOMS);
  }
  if (flightKalimdor > 0)
  {
    BoostFlightPaths::UnlockFlightPaths(player, BOOST_FLIGHTPATHS_KALIMDOR);
  }
  if (flightOutland > 0)
  {
    BoostFlightPaths::UnlockFlightPaths(player, BOOST_FLIGHTPATHS_OUTLAND);
  }
  if (flightNorthend > 0)
  {
    BoostFlightPaths::UnlockFlightPaths(player, BOOST_FLIGHTPATHS_NORTHEND);
  }
}

void Boost::GiveReputation(Player *player)
{
  if (player->GetReputation(1090) < 3000)
  {
    player->SetReputation(1090, 3000);
  }
}

void Boost::BindHeartstone(Player *player)
{
  uint32 bind = sConfigMgr->GetOption<uint32>("Boost.Heartstone", 1);

  if (bind <= 0)
  {
    return;
  }

  WorldLocation homebinding;
  if (player->GetTeamId() == TEAM_HORDE)
  {
    homebinding = WorldLocation(571, 5888.15, 510.102, 641.57, 4.9057107);
  }
  else
  {
    homebinding = WorldLocation(571, 5719.0337, 682.09784, 645.7523, 3.2493033);
  }

  // Bind on server
  player->SetHomebind(homebinding, 4395);

  // Notify client
  WorldPacket data(SMSG_BINDPOINTUPDATE, 4 + 4 + 4 + 4 + 4);
  data << float(homebinding.GetPositionX());
  data << float(homebinding.GetPositionY());
  data << float(homebinding.GetPositionZ());
  data << uint32(homebinding.GetMapId());
  data << uint32(4395);
  player->SendDirectMessage(&data);

  // ???
  data.Initialize(SMSG_PLAYERBOUND, 8 + 4);
  data << player->GetGUID();
  data << uint32(4395);
  player->SendDirectMessage(&data);
}

void Boost::Teleport(Player *player)
{
  uint32 teleport = sConfigMgr->GetOption<uint32>("Boost.Teleport", 1);

  if (teleport <= 0)
  {
    return;
  }

  player->TeleportTo(571, 5807.786, 588.1629, 660.94, 1.66594);
}