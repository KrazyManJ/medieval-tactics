#ifndef MAPOBJECT_H
#define MAPOBJECT_H
#include "GroundType.h"
#include "IQMLSerializable.h"

class MapObject : public IQMLSerializable{
    bool m_solid;
    GroundType m_groundType;

public:
    MapObject(bool solid, GroundType groundtype);
    GroundType getType();
    bool isSolid();
    void setIsSolid(bool value);
    void setType(GroundType newType);
    QVariantMap serialize() override;
};



#endif //MAPOBJECT_H
