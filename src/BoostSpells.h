#ifndef BOOST_SPELLS_H_
#define BOOST_SPELLS_H_

#include "Player.h"

class BoostSpells
{
public:
  static void LearnSpells(Player *player);
  static void LearnTalentRanks(Player *player);
private:
  static std::vector<std::vector<int>> GetClassSpells();
  static std::vector<std::vector<int>> GetTalentSpells();
};

#endif