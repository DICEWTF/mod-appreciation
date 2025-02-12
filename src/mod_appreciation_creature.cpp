#include "mod_appreciation.h"

#include "Config.h"
#include "CreatureScript.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "Boost.h"

class AppreciationCreature : public CreatureScript
{
public:
    AppreciationCreature() : CreatureScript("npc_appreciation") {}

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);

        // Check if enable
        uint32 boostAvailable = sConfigMgr->GetOption<uint32>("Boost.Enabled", 1);
        if (boostAvailable <= 0)
        {
            SendGossipMenuFor(player, GOSSIP_BOOST_TEXT_DISABLE, creature->GetGUID());
            return true;
        }

        // Get level
        uint32 targetLevel = sConfigMgr->GetOption<uint32>("Boost.Level", 80);
        if (targetLevel != 60 && targetLevel != 70 && targetLevel != 80)
        {
            targetLevel = 80;
        }

        // Check player is below level
        if (player->GetLevel() > targetLevel)
        {
            SendGossipMenuFor(player, GOSSIP_BOOST_TEXT_LEVEL_TOO_HIGH, creature->GetGUID());
            return true;
        }
        
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want a character boost", GOSSIP_SENDER_MAIN, GOSSIP_MENU_CHOOSE_SPECIALIZATION);
        SendGossipMenuFor(player, GOSSIP_BOOST_TEXT_DEFAULT, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if (sender != GOSSIP_SENDER_MAIN)
        {
            return false;
        }

        if (action == GOSSIP_MENU_CHOOSE_SPECIALIZATION)
        {
            ClearGossipMenuFor(player);

            switch (player->getClass())
            {
            case CLASS_WARRIOR:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Arms Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Fury Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Protection Warrior", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_PALADIN:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Holy Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Protection Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Retribution Paladin", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_HUNTER:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Beast Mastery Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Marksmanship Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Survival Hunter", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_ROGUE:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Assassination Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Combat Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Subtlety Rogue", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_PRIEST:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Discipline Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Holy Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Shadow Priest", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_DEATH_KNIGHT:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Blood Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Frost Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Unholy Death Knight", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_SHAMAN:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Elemental Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Enhancement Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Restoration Shaman", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_MAGE:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Arcane Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Fire Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Frost Mage", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_WARLOCK:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be an Affliction Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Demonology Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Destruction Warlock", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            case CLASS_DRUID:
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Balance Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_1);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Feral Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_2);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I want to be a Restoration Druid", GOSSIP_SENDER_MAIN, GOSSIP_MENU_SPECIALIZATION_3);
                break;
            }

            SendGossipMenuFor(player, GOSSIP_BOOST_TEXT_CHOOSE_SPECIALIZATION, creature->GetGUID());
        }
        else if (action == GOSSIP_MENU_SPECIALIZATION_1 || action == GOSSIP_MENU_SPECIALIZATION_2 || action == GOSSIP_MENU_SPECIALIZATION_3)
        {
            ClearGossipMenuFor(player);
            AddGossipItemFor(player, GOSSIP_ICON_CHAT, "I'm sure!", GOSSIP_SENDER_MAIN, action + 100);
            SendGossipMenuFor(player, GOSSIP_BOOST_TEXT_CONFIRM_SPECIALIZATION, creature->GetGUID());
        }
        else if (action == GOSSIP_MENU_SPECIALIZATION_1 + 100 || action == GOSSIP_MENU_SPECIALIZATION_2 + 100 || action == GOSSIP_MENU_SPECIALIZATION_3 + 100)
        {
            CloseGossipMenuFor(player);
            Boost::BoostPlayer(player, action - 300);
        }

        return true;
    } 
};

void AddSC_appreciation_creature()
{
    new AppreciationCreature();
}