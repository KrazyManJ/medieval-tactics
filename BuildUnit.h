#ifndef BUILDUNIT_H
#define BUILDUNIT_H

#include "Unit.h"

class BuildUnit : public Unit
{
public:
    float getBuildPower();
    void useAbility(int row, int column) override;
};

#endif // BUILDUNIT_H
