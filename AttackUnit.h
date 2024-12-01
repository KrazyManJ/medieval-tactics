#ifndef ATTACKUNIT_H
#define ATTACKUNIT_H

#include "Unit.h"

class AttackUnit : public Unit
{
public:
    float getAttackPower();
    void useAbility(int row, int column) override;
};

#endif // ATTACKUNIT_H
