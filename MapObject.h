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
    void setIsSolid(bool value);
    void setType(GroundType newType);
    ~MapObject();
};



#endif //MAPOBJECT_H
