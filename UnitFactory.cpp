#include "UnitFactory.h"

Unit* UnitFactory::createUnit(const std::string& unitType,int row,int column){
    return unitCreationMap.at(unitType)(row,column);
}

QVariant UnitFactory::serialize(){
    QVariantList list;
    for (auto it = unitCreationMap.begin(); it != unitCreationMap.end(); ++it) {
        list.append(it->second(0,0)->serialize());
    }
    return list;
}

std::map<std::string,std::function<Unit*(int,int)>> UnitFactory::unitCreationMap = {
    {"Warrior",[](int r, int c){ return new AttackUnit(100,10,2,3,100,{GroundType::Grass},{r,c},500,"Warrior","A brave knight."); }},
    {"Priest",[](int r, int c){ return new HealUnit(80, 5, 2, 6, 200,{GroundType::Grass},{r,c}, 10, "Priest", "A brave priest."); }},
    {"Druid",[](int r, int c){ return new BuildUnit(90, 7, 3, 3, 500, {GroundType::Grass},{r,c}, 10, "Druid", "A weird fella."); }}
};
