#ifndef BUILDUNIT_H
#define BUILDUNIT_H

#include "Unit.h"

class BuildUnit : public Unit
{
    float m_buildPower;
public:
    float getBuildPower();
};

#endif // BUILDUNIT_H
