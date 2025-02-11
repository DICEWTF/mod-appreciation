#include "BoostEquipment.h"

class BoostEquipment
{
public:
  static void EquipPlayer(Player *player, uint8 specialization, uint32 targetLevel)
  {
    std::vector<std::vector<int>> itemList = BoostEquipment::GetItemList(player->getClass(), specialization, targetLevel);

    if (itemList.empty())
    {
      return;
    }

    for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_TABARD; slot++)
    {
      player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

      uint32 itemId = itemList[slot][0];
      uint32 randomProperty = itemList[slot][1];

      if (itemId > 0)
      {
        if (sObjectMgr->GetItemTemplate(itemId))
        {
          if (Item *item = Item::CreateItem(itemId, 1, player, false, randomProperty > 0 ? randomProperty : 0))
          {
            if (randomProperty < 0)
            {
              item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, std::abs((int)randomProperty));
            }

            player->EquipItem(slot, item, true);

            if (player->getClass() == CLASS_SHAMAN && specialization == BOOST_SPEC_2 && slot == SLOT_MAIN_HAND)
            {
              ItemPosCountVec dest;
              InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, 1);

              if (msg == EQUIP_ERR_OK)
              {
                Item *item = player->StoreNewItem(dest, itemId, true, randomProperty > 0 ? randomProperty : 0);

                if (randomProperty < 0)
                {
                  item->SetUInt32Value(ITEM_FIELD_PROPERTY_SEED, std::abs((int)randomProperty));
                }

                player->SendNewItem(item, 1, true, false);
              }
            }
          }
        }
      }
    }
  }

private:
  static std::vector<std::vector<int>> GetItemList(uint32 classId, uint8 specialization, uint32 TargetLevel)
  {
    if (TargetLevel != 60 && TargetLevel != 70 && TargetLevel != 80)
    {
      TargetLevel = 60;
    }

    std::vector<std::vector<int>> itemList;
    std::vector<int> item;

    switch (classId)
    {
    case CLASS_WARRIOR:
      // Head
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14979, 1232};
        }
        else // Protection
        {
          item = {14979, 1231};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25018, -41};
        }
        else // Protection
        {
          item = {25018, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {39108, 0};
        }
        else // Protection
        {
          item = {43846, 0};
        }
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {12048, 1208};
        }
        else // Protection
        {
          item = {12048, 1207};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25070, -41};
        }
        else // Protection
        {
          item = {25070, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {42808, 0};
        }
        else // Protection
        {
          item = {43849, 0};
        }
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14981, 2151};
        }
        else // Protection
        {
          item = {14981, 338};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25028, -41};
        }
        else // Protection
        {
          item = {25028, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {39888, 0};
        }
        else // Protection
        {
          item = {43844, 0};
        }
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14975, 1232};
        }
        else // Protection
        {
          item = {14975, 346};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25008, -41};
        }
        else // Protection
        {
          item = {25008, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {43945, 0};
        }
        else // Protection
        {
          item = {42827, 0};
        }
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14977, 2151};
        }
        else // Protection
        {
          item = {14977, 1213};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25014, -41};
        }
        else // Protection
        {
          item = {25014, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {42882, 0};
        }
        else // Protection
        {
          item = {39471, 0};
        }
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14980, 2158};
        }
        else // Protection
        {
          item = {14980, 1228};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25019, -41};
        }
        else // Protection
        {
          item = {25019, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {43940, 0};
        }
        else // Protection
        {
          item = {43845, 0};
        }
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14978, 2154};
        }
        else // Protection
        {
          item = {14978, 338};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25015, -41};
        }
        else // Protection
        {
          item = {25015, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {39102, 0};
        }
        else // Protection
        {
          item = {42884, 0};
        }
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14983, 1205};
        }
        else // Protection
        {
          item = {14983, 287};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25021, -41};
        }
        else // Protection
        {
          item = {25021, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {39100, 0};
        }
        else // Protection
        {
          item = {42825, 0};
        }
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {14976, 1217};
        }
        else // Protection
        {
          item = {14976, 1216};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25017, -41};
        }
        else // Protection
        {
          item = {25017, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {42835, 0};
        }
        else // Protection
        {
          item = {43842, 0};
        }
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {12017, 1208};
        }
        else // Protection
        {
          item = {12017, 333};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25056, -41};
        }
        else // Protection
        {
          item = {25056, -16};
        }
      }
      else
      {
        item = {42812, 0};
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {11980, 1206};
        }
        else // Protection
        {
          item = {11980, 333};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25056, -41};
        }
        else // Protection
        {
          item = {25056, -16};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {42864, 0};
        }
        else // Protection
        {
          item = {43926, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {17774, 0};
        }
        else // Protection
        {
          item = {1490, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {29776, 0};
        }
        else // Protection
        {
          item = {25787, 0};
        }
      }
      else
      {
        item = {43838, 0};
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {5079, 0};
        }
        else // Protection
        {
          item = {4130, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25937, 0};
        }
        else // Protection
        {
          item = {25996, 0};
        }
      }
      else
      {
        item = {43829, 0};
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {15437, 1205};
        }
        else // Protection
        {
          item = {15437, 287};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25042, -41};
        }
        else // Protection
        {
          item = {25042, -16};
        }
      }
      else
      {
        item = {43924, 0};
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {15221, 1199};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {15256, 1226};
        }
        else // Protection
        {
          item = {15221, 1199};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {25154, -41};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {25168, -41};
        }
        else // Protection
        {
          item = {25154, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {42786, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {43883, 0};
        }
        else // Protection
        {
          item = {43923, 0};
        }
      }
      itemList.push_back(item);

      // Off hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {15219, 1197};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {0, 0};
        }
        else // Protection
        {
          item = {14982, 1197};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {25153, -41};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {0, 0};
        }
        else // Protection
        {
          item = {25084, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Arms
        {
          item = {42807, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Fury
        {
          item = {0, 0};
        }
        else // Protection
        {
          item = {43843, 0};
        }
      }
      itemList.push_back(item);

      // Ranged
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {15289, 683};
        }
        else // Protection
        {
          item = {15289, 185};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_2) // Arms, Fury
        {
          item = {25252, -41};
        }
        else // Protection
        {
          item = {25252, -16};
        }
      }
      else
      {
        item = {39134, 0};
      }
      itemList.push_back(item);
      break;
    case CLASS_PALADIN:
      // Head
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14979, 891};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14979, 1231};
        }
        else // Retribution
        {
          item = {14979, 1232};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25018, -9};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25018, -16};
        }
        else // Retribution
        {
          item = {25018, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42829, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43846, 0};
        }
        else // Retribution
        {
          item = {39108, 0};
        }
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {12048, 784};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {12048, 1207};
        }
        else // Retribution
        {
          item = {12048, 1208};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25070, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25070, -16};
        }
        else // Retribution
        {
          item = {25070, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42793, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43849, 0};
        }
        else // Retribution
        {
          item = {42808, 0};
        }
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14981, 876};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14981, 338};
        }
        else // Retribution
        {
          item = {14981, 2151};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25028, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25028, -16};
        }
        else // Retribution
        {
          item = {25028, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42876, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43844, 0};
        }
        else // Retribution
        {
          item = {39888, 0};
        }
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14975, 891};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14975, 346};
        }
        else // Retribution
        {
          item = {14975, 1232};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25008, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25008, -16};
        }
        else // Retribution
        {
          item = {25008, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42877, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {42827, 0};
        }
        else // Retribution
        {
          item = {43945, 0};
        }
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14977, 873};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14977, 1213};
        }
        else // Retribution
        {
          item = {14977, 2151};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25014, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25014, -16};
        }
        else // Retribution
        {
          item = {25014, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {43831, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {39471, 0};
        }
        else // Retribution
        {
          item = {42882, 0};
        }
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14980, 888};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14980, 1228};
        }
        else // Retribution
        {
          item = {14980, 2158};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25019, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25019, -16};
        }
        else // Retribution
        {
          item = {25019, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42881, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43845, 0};
        }
        else // Retribution
        {
          item = {43940, 0};
        }
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14978, 876};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14978, 338};
        }
        else // Retribution
        {
          item = {14978, 2154};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25015, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25015, -16};
        }
        else // Retribution
        {
          item = {25015, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42883, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {42884, 0};
        }
        else // Retribution
        {
          item = {39102, 0};
        }
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14983, 864};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14983, 287};
        }
        else // Retribution
        {
          item = {14983, 1205};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25021, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25021, -16};
        }
        else // Retribution
        {
          item = {25021, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42830, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {42825, 0};
        }
        else // Retribution
        {
          item = {39100, 0};
        }
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14976, 876};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14976, 1216};
        }
        else // Retribution
        {
          item = {14976, 1217};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25017, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25017, -16};
        }
        else // Retribution
        {
          item = {25017, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {43943, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43842, 0};
        }
        else // Retribution
        {
          item = {42835, 0};
        }
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {12017, 867};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {12017, 333};
        }
        else // Retribution
        {
          item = {12017, 1208};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25056, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25056, -16};
        }
        else // Retribution
        {
          item = {25056, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {43903, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {42812, 0};
        }
        else // Retribution
        {
          item = {42864, 0};
        }
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {11980, 868};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {11980, 333};
        }
        else // Retribution
        {
          item = {11980, 1206};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25056, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25056, -16};
        }
        else // Retribution
        {
          item = {25056, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42791, 0};
        }
        else // Protection, Retribution
        {
          item = {43926, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {10659, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {1490, 0};
        }
        else // Retribution
        {
          item = {17774, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25634, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25787, 0};
        }
        else // Retribution
        {
          item = {29776, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {43837, 0};
        }
        else // Protection, Retribution
        {
          item = {43829, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {17774, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {4130, 0};
        }
        else // Retribution
        {
          item = {5079, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {30293, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25996, 0};
        }
        else // Retribution
        {
          item = {25937, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {38763, 0};
        }
        else // Protection, Retribution
        {
          item = {43838, 0};
        }
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {15437, 864};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {15437, 287};
        }
        else // Retribution
        {
          item = {15437, 1205};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25042, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25042, -16};
        }
        else // Retribution
        {
          item = {25042, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {43861, 0};
        }
        else // Protection, Retribution
        {
          item = {43924, 0};
        }
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {15229, 2040};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {15221, 1199};
        }
        else // Retribution
        {
          item = {15256, 1226};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25322, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25154, -41};
        }
        else // Retribution
        {
          item = {25168, -41};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {39143, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43923, 0};
        }
        else // Retribution
        {
          item = {43883, 0};
        }
      }
      itemList.push_back(item);

      // Off hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {14982, 2043};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {14982, 1197};
        }
        else // Retribution
        {
          item = {0, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {25084, -44};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {25084, -41};
        }
        else // Retribution
        {
          item = {0, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1) // Holy
        {
          item = {42860, 0};
        }
        else if (specialization == BOOST_SPEC_2) // Protection
        {
          item = {43843, 0};
        }
        else // Retribution
        {
          item = {0, 0};
        }
      }
      itemList.push_back(item);

      // Ranged
      item = {0, 0};
      itemList.push_back(item);
      break;
    case CLASS_HUNTER:
      // Head
      if (TargetLevel == 60)
      {
        item = {15684, 468};
      }
      else if (TargetLevel == 70)
      {
        item = {24906, -5};
      }
      else
      {
        item = {43937, 0};
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        item = {12048, 612};
      }
      else if (TargetLevel == 70)
      {
        item = {25070, -5};
      }
      else
      {
        item = {42808, 0};
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        item = {15686, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24908, -5};
      }
      else
      {
        item = {42887, 0};
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        item = {15680, 636};
      }
      else if (TargetLevel == 70)
      {
        item = {24904, -5};
      }
      else
      {
        item = {42896, 0};
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        item = {15683, 618};
      }
      else if (TargetLevel == 70)
      {
        item = {24902, -5};
      }
      else
      {
        item = {42889, 0};
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        item = {15685, 633};
      }
      else if (TargetLevel == 70)
      {
        item = {24907, -5};
      }
      else
      {
        item = {39066, 0};
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        item = {15678, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24903, -5};
      }
      else
      {
        item = {42891, 0};
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        item = {15679, 609};
      }
      else if (TargetLevel == 70)
      {
        item = {24909, -5};
      }
      else
      {
        item = {42816, 0};
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        item = {15682, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24905, -5};
      }
      else
      {
        item = {39070, 0};
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        item = {12017, 612};
      }
      else if (TargetLevel == 70)
      {
        item = {25056, -5};
      }
      else
      {
        item = {42812, 0};
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        item = {12005, 609};
      }
      else if (TargetLevel == 70)
      {
        item = {25055, -5};
      }
      else
      {
        item = {42864, 0};
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        item = {5079, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {29776, 0};
      }
      else
      {
        item = {43829, 0};
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        item = {17774, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {25937, 0};
      }
      else
      {
        item = {43838, 0};
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        item = {10249, 609};
      }
      else if (TargetLevel == 70)
      {
        item = {25042, -5};
      }
      else
      {
        item = {43889, 0};
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        item = {15278, 629};
      }
      else if (TargetLevel == 70)
      {
        item = {25182, -5};
      }
      else
      {
        item = {36610, -40};
      }
      itemList.push_back(item);

      // Off hand
      item = {0, 0};
      itemList.push_back(item);

      // Ranged
      if (TargetLevel == 60)
      {
        item = {15289, 597};
      }
      else if (TargetLevel == 70)
      {
        item = {25252, -40};
      }
      else
      {
        item = {39134, 0};
      }
      itemList.push_back(item);
      break;
    case CLASS_ROGUE:
      // Head
      if (TargetLevel == 60)
      {
        item = {15439, 636};
      }
      else if (TargetLevel == 70)
      {
        item = {24794, -40};
      }
      else
      {
        item = {43840, 0};
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        item = {12048, 612};
      }
      else if (TargetLevel == 70)
      {
        item = {25070, -5};
      }
      else
      {
        item = {42808, 0};
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        item = {15441, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24796, -40};
      }
      else
      {
        item = {42869, 0};
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        item = {15442, 636};
      }
      else if (TargetLevel == 70)
      {
        item = {24792, -40};
      }
      else
      {
        item = {43891, 0};
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        item = {15434, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24790, -40};
      }
      else
      {
        item = {43909, 0};
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        item = {15440, 633};
      }
      else if (TargetLevel == 70)
      {
        item = {24795, -40};
      }
      else
      {
        item = {43896, 0};
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        item = {15435, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24791, -40};
      }
      else
      {
        item = {39035, 0};
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        item = {15436, 609};
      }
      else if (TargetLevel == 70)
      {
        item = {24797, -40};
      }
      else
      {
        item = {39038, 0};
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        item = {15438, 621};
      }
      else if (TargetLevel == 70)
      {
        item = {24793, -40};
      }
      else
      {
        item = {39038, 0};
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        item = {12017, 612};
      }
      else if (TargetLevel == 70)
      {
        item = {25056, -40};
      }
      else
      {
        item = {42812, 0};
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        item = {11992, 611};
      }
      else if (TargetLevel == 70)
      {
        item = {25055, -40};
      }
      else
      {
        item = {42864, 0};
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        item = {17774, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {29776, 0};
      }
      else
      {
        item = {43829, 0};
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        item = {5079, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {25937, 0};
      }
      else
      {
        item = {43838, 0};
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        item = {10249, 609};
      }
      else if (TargetLevel == 70)
      {
        item = {25042, -40};
      }
      else
      {
        item = {43889, 0};
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        item = {15247, 603};
      }
      else if (TargetLevel == 70)
      {
        item = {25112, -40};
      }
      else
      {
        item = {43911, 0};
      }
      itemList.push_back(item);

      // Off hand
      if (TargetLevel == 60)
      {
        item = {15246, 603};
      }
      else if (TargetLevel == 70)
      {
        item = {25111, -40};
      }
      else
      {
        item = {42861, 0};
      }
      itemList.push_back(item);

      // Ranged
      if (TargetLevel == 60)
      {
        item = {29203, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {28543, -40};
      }
      else
      {
        item = {39134, 0};
      }
      itemList.push_back(item);
      break;
    case CLASS_PRIEST:
    case CLASS_MAGE:
    case CLASS_WARLOCK:
      // Head
      if (TargetLevel == 60)
      {
        item = {14332, 891};
      }
      else if (TargetLevel == 70)
      {
        item = {24681, -37};
      }
      else
      {
        item = {38737, 0};
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        item = {12027, 864};
      }
      else if (TargetLevel == 70)
      {
        item = {25070, -37};
      }
      else
      {
        item = {42793, 0};
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        item = {14335, 876};
      }
      else if (TargetLevel == 70)
      {
        item = {24683, -37};
      }
      else
      {
        item = {42842, 0};
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        item = {14328, 891};
      }
      else if (TargetLevel == 70)
      {
        item = {24679, -37};
      }
      else
      {
        item = {42792, 0};
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        item = {14337, 876};
      }
      else if (TargetLevel == 70)
      {
        item = {24677, -37};
      }
      else
      {
        item = {42788, 0};
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        item = {14334, 888};
      }
      else if (TargetLevel == 70)
      {
        item = {24682, -37};
      }
      else
      {
        item = {43863, 0};
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        item = {14329, 876};
      }
      else if (TargetLevel == 70)
      {
        item = {24678, -37};
      }
      else
      {
        item = {42789, 0};
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        item = {14330, 864};
      }
      else if (TargetLevel == 70)
      {
        item = {24684, -37};
      }
      else
      {
        item = {38736, 0};
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        item = {14333, 879};
      }
      else if (TargetLevel == 70)
      {
        item = {24680, -37};
      }
      else
      {
        item = {38741, 0};
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        item = {11992, 864};
      }
      else if (TargetLevel == 70)
      {
        item = {25056, -37};
      }
      else
      {
        item = {42791, 0};
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        item = {12017, 867};
      }
      else if (TargetLevel == 70)
      {
        item = {25055, -39};
      }
      else
      {
        item = {43874, 0};
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        item = {10659, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {25634, 0};
      }
      else
      {
        item = {43836, 0};
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        item = {17774, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {30293, 0};
      }
      else
      {
        item = {43837, 0};
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        item = {10249, 864};
      }
      else if (TargetLevel == 70)
      {
        item = {25042, -37};
      }
      else
      {
        item = {43861, 0};
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        item = {15278, 802};
      }
      else if (TargetLevel == 70)
      {
        item = {25181, -39};
      }
      else
      {
        item = {39121, 0};
      }
      itemList.push_back(item);

      // Off hand
      item = {0, 0};
      itemList.push_back(item);

      // Ranged
      if (TargetLevel == 60)
      {
        item = {15283, 854};
      }
      else if (TargetLevel == 70)
      {
        item = {25294, -39};
      }
      else
      {
        item = {43828, 0};
      }
      itemList.push_back(item);
      break;
    case CLASS_DEATH_KNIGHT:
      // Head
      if (TargetLevel == 60)
      {
        item = {14979, 1232};
      }
      else if (TargetLevel == 70)
      {
        item = {25018, -41};
      }
      else
      {
        item = {39108, 0};
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        item = {12048, 1208};
      }
      else if (TargetLevel == 70)
      {
        item = {25070, -41};
      }
      else
      {
        item = {42808, 0};
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        item = {14981, 2151};
      }
      else if (TargetLevel == 70)
      {
        item = {25028, -41};
      }
      else
      {
        item = {39888, 0};
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        item = {14975, 1232};
      }
      else if (TargetLevel == 70)
      {
        item = {25008, -41};
      }
      else
      {
        item = {43945, 0};
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        item = {14977, 2151};
      }
      else if (TargetLevel == 70)
      {
        item = {25014, -41};
      }
      else
      {
        item = {42882, 0};
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        item = {14980, 2158};
      }
      else if (TargetLevel == 70)
      {
        item = {25019, -41};
      }
      else
      {
        item = {43940, 0};
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        item = {14978, 2154};
      }
      else if (TargetLevel == 70)
      {
        item = {25015, -41};
      }
      else
      {
        item = {39102, 0};
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        item = {14983, 1205};
      }
      else if (TargetLevel == 70)
      {
        item = {25021, -41};
      }
      else
      {
        item = {39100, 0};
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        item = {14976, 1217};
      }
      else if (TargetLevel == 70)
      {
        item = {25017, -41};
      }
      else
      {
        item = {42835, 0};
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        item = {12017, 1208};
      }
      else if (TargetLevel == 70)
      {
        item = {25056, -41};
      }
      else
      {
        item = {42864, 0};
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        item = {11980, 1206};
      }
      else if (TargetLevel == 70)
      {
        item = {25056, -41};
      }
      else
      {
        item = {42812, 0};
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        item = {17774, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {29776, 0};
      }
      else
      {
        item = {43838, 0};
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        item = {5079, 0};
      }
      else if (TargetLevel == 70)
      {
        item = {25937, 0};
      }
      else
      {
        item = {43829, 0};
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        item = {15437, 1205};
      }
      else if (TargetLevel == 70)
      {
        item = {25042, -41};
      }
      else
      {
        item = {43924, 0};
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        item = {15258, 1232};
      }
      else if (TargetLevel == 70)
      {
        item = {25168, -41};
      }
      else
      {
        item = {43883, 0};
      }
      itemList.push_back(item);

      // Off hand
      item = {0, 0};
      itemList.push_back(item);

      // Ranged
      item = {0, 0};
      itemList.push_back(item);
      break;
    case CLASS_SHAMAN:
      // Head
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15684, 891};
        }
        else // Enhancement
        {
          item = {15684, 636};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24906, -39};
        }
        else // Enhancement
        {
          item = {24906, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43978, 0};
        }
        else // Enhancement
        {
          item = {43937, 0};
        }
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {12027, 864};
        }
        else // Enhancement
        {
          item = {12027, 287};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25070, -39};
        }
        else // Enhancement
        {
          item = {25070, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42793, 0};
        }
        else // Enhancement
        {
          item = {42808, 0};
        }
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15686, 876};
        }
        else // Enhancement
        {
          item = {15686, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24908, -39};
        }
        else // Enhancement
        {
          item = {24908, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43830, 0};
        }
        else // Enhancement
        {
          item = {42887, 0};
        }
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15680, 891};
        }
        else // Enhancement
        {
          item = {15680, 639};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24904, -39};
        }
        else // Enhancement
        {
          item = {24904, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43977, 0};
        }
        else // Enhancement
        {
          item = {42896, 0};
        }
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15683, 873};
        }
        else // Enhancement
        {
          item = {15683, 618};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24902, -39};
        }
        else // Enhancement
        {
          item = {24902, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42814, 0};
        }
        else // Enhancement
        {
          item = {42821, 0};
        }
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15685, 888};
        }
        else // Enhancement
        {
          item = {15685, 633};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24907, -39};
        }
        else // Enhancement
        {
          item = {24907, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42890, 0};
        }
        else // Enhancement
        {
          item = {39887, 0};
        }
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15678, 876};
        }
        else // Enhancement
        {
          item = {15678, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24903, -39};
        }
        else // Enhancement
        {
          item = {24903, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42815, 0};
        }
        else // Enhancement
        {
          item = {42891, 0};
        }
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15679, 864};
        }
        else // Enhancement
        {
          item = {15679, 609};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24909, -39};
        }
        else // Enhancement
        {
          item = {24909, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42892, 0};
        }
        else // Enhancement
        {
          item = {42816, 0};
        }
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15682, 876};
        }
        else // Enhancement
        {
          item = {15682, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {24905, -39};
        }
        else // Enhancement
        {
          item = {24905, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43976, 0};
        }
        else // Enhancement
        {
          item = {43981, 0};
        }
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {12017, 867};
        }
        else // Enhancement
        {
          item = {12017, 612};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25057, -39};
        }
        else // Enhancement
        {
          item = {25057, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42791, 0};
        }
        else // Enhancement
        {
          item = {42812, 0};
        }
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {11992, 611};
        }
        else // Enhancement
        {
          item = {11992, 611};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25056, -39};
        }
        else // Enhancement
        {
          item = {25056, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43903, 0};
        }
        else // Enhancement
        {
          item = {42864, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {10659, 0};
        }
        else // Enhancement
        {
          item = {17774, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25634, 0};
        }
        else // Enhancement
        {
          item = {29776, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43836, 0};
        }
        else // Enhancement
        {
          item = {43829, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {17774, 0};
        }
        else // Enhancement
        {
          item = {5079, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {30293, 0};
        }
        else // Enhancement
        {
          item = {25937, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43837, 0};
        }
        else // Enhancement
        {
          item = {43838, 0};
        }
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {10249, 864};
        }
        else // Enhancement
        {
          item = {10249, 609};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25042, -39};
        }
        else // Enhancement
        {
          item = {25042, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {43925, 0};
        }
        else // Enhancement
        {
          item = {43889, 0};
        }
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {15229, 2040};
        }
        else // Enhancement
        {
          item = {15229, 602};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25323, -44};
        }
        else // Enhancement
        {
          item = {25127, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {39143, 0};
        }
        else // Enhancement
        {
          item = {39144, 0};
        }
      }
      itemList.push_back(item);

      // Off hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {10367, 384};
        }
        else // Enhancement
        {
          item = {0, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {25084, -39};
        }
        else // Enhancement
        {
          item = {0, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Elemental, Restoration
        {
          item = {42860, 0};
        }
        else // Enhancement
        {
          item = {0, 0};
        }
      }
      itemList.push_back(item);

      // Ranged
      item = {0, 0};
      itemList.push_back(item);
      break;
    case CLASS_DRUID:
      // Head
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10261, 888};
        }
        else // Feral Combat
        {
          item = {10261, 633};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24802, -39};
        }
        else // Feral Combat
        {
          item = {24802, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43905, 0};
        }
        else // Feral Combat
        {
          item = {43840, 0};
        }
      }
      itemList.push_back(item);

      // Neck
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {12048, 867};
        }
        else // Feral Combat
        {
          item = {12048, 612};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25070, -39};
        }
        else // Feral Combat
        {
          item = {25070, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42793, 0};
        }
        else // Feral Combat
        {
          item = {42808, 0};
        }
      }
      itemList.push_back(item);

      // Shoulders
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10263, 876};
        }
        else // Feral Combat
        {
          item = {10263, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24804, -39};
        }
        else // Feral Combat
        {
          item = {24804, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42800, 0};
        }
        else // Feral Combat
        {
          item = {42869, 0};
        }
      }
      itemList.push_back(item);

      // Body
      item = {0, 0};
      itemList.push_back(item);

      // Chest
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10264, 891};
        }
        else // Feral Combat
        {
          item = {10264, 636};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24800, -39};
        }
        else // Feral Combat
        {
          item = {24800, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43912, 0};
        }
        else // Feral Combat
        {
          item = {39036, 0};
        }
      }
      itemList.push_back(item);

      // Waist
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10259, 876};
        }
        else // Feral Combat
        {
          item = {10259, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24798, -39};
        }
        else // Feral Combat
        {
          item = {24798, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43914, 0};
        }
        else // Feral Combat
        {
          item = {43909, 0};
        }
      }
      itemList.push_back(item);

      // Legs
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10262, 891};
        }
        else // Feral Combat
        {
          item = {10262, 636};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24803, -39};
        }
        else // Feral Combat
        {
          item = {24803, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {36160, -37};
        }
        else // Feral Combat
        {
          item = {43896, 0};
        }
      }
      itemList.push_back(item);

      // Feet
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10257, 876};
        }
        else // Feral Combat
        {
          item = {10257, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24799, -39};
        }
        else // Feral Combat
        {
          item = {24799, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42798, 0};
        }
        else // Feral Combat
        {
          item = {39035, 0};
        }
      }
      itemList.push_back(item);

      // Wrists
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10256, 864};
        }
        else // Feral Combat
        {
          item = {10256, 609};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24805, -39};
        }
        else // Feral Combat
        {
          item = {24805, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42865, 0};
        }
        else // Feral Combat
        {
          item = {39038, 0};
        }
      }
      itemList.push_back(item);

      // Hands
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10260, 876};
        }
        else // Feral Combat
        {
          item = {10260, 621};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {24801, -39};
        }
        else // Feral Combat
        {
          item = {24801, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42866, 0};
        }
        else // Feral Combat
        {
          item = {39040, 0};
        }
      }
      itemList.push_back(item);

      // Finger 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {12017, 867};
        }
        else // Feral Combat
        {
          item = {12017, 612};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25057, -39};
        }
        else // Feral Combat
        {
          item = {25057, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {42791, 0};
        }
        else // Feral Combat
        {
          item = {42812, 0};
        }
      }
      itemList.push_back(item);

      // Finger 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {12005, 865};
        }
        else // Feral Combat
        {
          item = {12005, 609};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25056, -39};
        }
        else // Feral Combat
        {
          item = {25056, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43874, 0};
        }
        else // Feral Combat
        {
          item = {42864, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 1
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10659, 0};
        }
        else // Feral Combat
        {
          item = {17774, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25634, 0};
        }
        else // Feral Combat
        {
          item = {29776, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43836, 0};
        }
        else // Feral Combat
        {
          item = {43829, 0};
        }
      }
      itemList.push_back(item);

      // Trinket 2
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {17774, 0};
        }
        else // Feral Combat
        {
          item = {5079, 0};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {30293, 0};
        }
        else // Feral Combat
        {
          item = {25937, 0};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43837, 0};
        }
        else // Feral Combat
        {
          item = {43838, 0};
        }
      }
      itemList.push_back(item);

      // Back
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {10249, 864};
        }
        else // Feral Combat
        {
          item = {10249, 609};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25042, -39};
        }
        else // Feral Combat
        {
          item = {25042, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {43925, 0};
        }
        else // Feral Combat
        {
          item = {43889, 0};
        }
      }
      itemList.push_back(item);

      // Main hand
      if (TargetLevel == 60)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {15278, 885};
        }
        else // Feral Combat
        {
          item = {15278, 630};
        }
      }
      else if (TargetLevel == 70)
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {25182, -39};
        }
        else // Feral Combat
        {
          item = {25182, -40};
        }
      }
      else
      {
        if (specialization == BOOST_SPEC_1 || specialization == BOOST_SPEC_3) // Balance, Restoration
        {
          item = {36610, -36};
        }
        else // Feral Combat
        {
          item = {36610, -40};
        }
      }
      itemList.push_back(item);

      // Off hand
      item = {0, 0};
      itemList.push_back(item);

      // Ranged
      item = {0, 0};
      itemList.push_back(item);
      break;
    default:
      break;
    }
    return itemList;
  }
};