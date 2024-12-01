#ifndef HEALUNIT_H
#define HEALUNIT_H

#include "Unit.h"

class HealUnit : public Unit
{
public:
    float getHealPower();
    void useAbility(int row, int column) override;
};

#endif // HEALUNIT_H
