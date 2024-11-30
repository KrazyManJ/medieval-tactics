//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include <GroundType.h>


class MapObject {
    bool m_solid;
    GroundType m_groundType;

public:
    MapObject(bool solid, GroundType groundtype);
    GroundType getType();
    bool isSolid();
    ~MapObject();
};



#endif //MAPOBJECT_H
