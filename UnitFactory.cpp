#include "UnitFactory.h"

Unit* UnitFactory::createUnit(const std::string& unitType,int row,int column){
    if (unitType == "Knight") {
        return new AttackUnit (
            100, 10, 2, 3, 100, std::vector<GroundType>{GroundType::Grass},
            Position{.row=row,.column=column}, 500, "warrior", "A brave knight."
            );
    } else if (unitType == "Priest") {
        return new HealUnit (
            80, 5, 2, 6, 200, std::vector<GroundType>{GroundType::Grass},
            Position{.row=row,.column=column}, 10, "priest", "A brave priest."
            );
    } else if (unitType == "Druid") {
        return new BuildUnit (
            90, 7, 3, 3, 500, std::vector<GroundType>{GroundType::Grass},
            Position{.row=row,.column=column}, 10, "druid", "A wierd fella."
            );
    } else {
        throw std::invalid_argument("Unknown unit type!");
    }
}
