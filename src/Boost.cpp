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

  // Boost
  Boost::GiveLevel(player, targetLevel);
  Boost::GiveGold(player);
  Boost::GiveEquipment(player, specialization, targetLevel);
  Boost::GiveProficiencies(player);
  Boost::GiveSpells(player);
  Boost::GiveDualSpec(player);
  Boost::GiveRiding(player);
  Boost::GiveMounts(player);
  Boost::UnlockFlightPaths(player);
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
  uint32 gold = sConfigMgr->GetOption<uint32>("Boost.Gold", 5000);

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
  uint32 mountHordeGround = sConfigMgr->GetOption<uint32>("Boost.Mounts.Horde.Ground", 580);
  uint32 mountHordeFly = sConfigMgr->GetOption<uint32>("Boost.Mounts.Horde.Fly", 32243);
  uint32 mountAllianceGround = sConfigMgr->GetOption<uint32>("Boost.Mounts.Alliance.Ground", 472);
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

void Boost::BindHeartstone(Player *player)
{
  uint32 bind = sConfigMgr->GetOption<uint32>("Boost.Heartstone", 1);

  if (bind <= 0)
  {
    return;
  }

  // TODO
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

// TODO: reputation
// TODO: bags