#ifndef BOOST_H_
#define BOOST_H_

#include "Player.h"

class Boost
{
public:
  static void BoostPlayer(Player *player, uint8 specialization);

private:
  static void GiveLevel(Player *player, uint32 targetLevel);
  static void GiveGold(Player *player);
  static void GiveEquipment(Player *player, uint8 specialization, uint32 targetLevel);
  static void ResetTalents(Player *player);
  static void GiveProficiencies(Player *player);
  static void GiveSpells(Player *player);
  static void GiveDualSpec(Player *player);
  static void GiveRiding(Player *player);
  static void GiveMounts(Player *player);
  static void UnlockFlightPaths(Player *player);
  static void BindHeartstone(Player *player);
  static void Teleport(Player *player);
};

#endif