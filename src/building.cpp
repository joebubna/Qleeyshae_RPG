/**
* @File: Building.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/Building.h"

Building::Building() {
    this->type( noBuilding );
}

Building::Building( buildingType defaultType = house ) {
    this->type( defaultType );
}

Building::Building( buildingType defaultType, int x, int y ) {
    this->type( defaultType );
    this->setX( x );
    this->setY( y );
}

void Building::type( buildingType newType ) {
    this->type_ = newType;
}

buildingType Building::type() const {
    return this->type_;
}

void Building::desc( string newDesc ) {
    this->desc_ = newDesc;
}

int Building::getX() const {
    return this->cX_;
}

int Building::getY() const {
    return this->cY_;
}

void Building::setX( int newX ) {
    this->cX_ = newX;
}


void Building::setY( int newY ) {
    this->cY_ = newY;
}
