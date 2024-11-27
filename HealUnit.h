#ifndef HEALUNIT_H
#define HEALUNIT_H

#include "unit.h"

class HealUnit : public Unit
{
    float m_healPower;
public:
    float getHealPower();
};

#endif // HEALUNIT_H
