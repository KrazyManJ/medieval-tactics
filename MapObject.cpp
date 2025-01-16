#include "MapObject.h"

MapObject::MapObject(bool solid, GroundType groundtype) {
	m_solid = solid;
	m_groundType = groundtype;
}

GroundType MapObject::getType() {
	return m_groundType;
}

bool MapObject::isSolid() {
	return m_solid;
}

void MapObject::setIsSolid(bool value) {
    m_solid = value;
}

void MapObject::setType(GroundType newType) {
    m_groundType = newType;
}

QVariantMap MapObject::serialize(){
    QVariantMap map;
    QString type;
    switch (m_groundType) {
    case GroundType::Grass:
        type = "grass";
        break;
    case GroundType::Water:
        type = "water";
        break;
    default:
        type = "grass";
        break;
    }
    map["type"] = type;
    return map;
}
