//
// Created by MiloslavŠvábenský(ml on 30.11.2024.
//

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

MapObject::~MapObject(){

}
