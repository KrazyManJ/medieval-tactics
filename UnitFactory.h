#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include <memory>
#include <string>
#include "AttackUnit.h"
#include "HealUnit.h"
#include "BuildUnit.h"

class UnitFactory
{
public:
    static std::unique_ptr<Unit> createUnit(const std::string& unitType,int row,int column);
};

#endif // UNITFACTORY_H
