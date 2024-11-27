#ifndef ATTACKUNIT_H
#define ATTACKUNIT_H

#include "Unit.h"

class AttackUnit : public Unit
{
    float m_attackPower;
public:
    float getAttackPower();
};

#endif // ATTACKUNIT_H
