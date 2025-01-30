#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include <string>
#include "AttackUnit.h"
#include "HealUnit.h"
#include "BuildUnit.h"

class UnitFactory {
private:
    static std::map<std::string,std::function<Unit*(int,int)>> unitCreationMap;
public:
    static Unit* createUnit(const std::string& unitType,int row,int column);
    static std::vector<std::string> getAllAvailableUnitsToCreate();
    static QVariant serialize();
};

#endif // UNITFACTORY_H
