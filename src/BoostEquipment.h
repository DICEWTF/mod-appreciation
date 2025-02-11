#ifndef BOOST_EQUIPMENT_H_
#define BOOST_EQUIPMENT_H_

#include "Player.h"

enum
{
  BOOST_SPEC_1 = 0,
  BOOST_SPEC_2 = 1,
  BOOST_SPEC_3 = 2,
};

class BoostEquipment
{
public:
  static void EquipPlayer(Player *player, uint8 specialization, uint32 targetLevel);

private:
  static std::vector<std::vector<int>> GetItemList(uint32 classId, uint8 specialization, uint32 TargetLevel);
};

#endif