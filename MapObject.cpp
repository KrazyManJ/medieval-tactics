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

MapObject::~MapObject(){

}
