#ifndef WARRIOR_H
#define WARRIOR_H
#include <iostream>

#include "AttackUnit.h"

class Warrior : public AttackUnit
{
public:
    void useAbility() override;
    std::string getAbilityName() override;
};

#endif // WARRIOR_H
