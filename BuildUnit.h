#ifndef BUILDUNIT_H
#define BUILDUNIT_H

#include "unit.h"

class BuildUnit : public Unit
{
    float m_buildPower;
public:
    float getBuildPower();
};

#endif // BUILDUNIT_H
