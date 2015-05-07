/**
* @File: map.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/map.h"

Map::Map( string name, int w, int h, string type, int sX, int sY ) {
    this->width_ = w;
    this->height_ = h;
    this->name_ = name;
    this->type_ = type;
    this->startX_ = sX;
    this->startY_ = sY;
    
    MapSquare blank;
    this->gB_.resize(width_);
    for (int i = 0; i < this->gB_.size(); i++) {
        this->gB_[i].resize(h, blank);
    }
}

// Returns the terrain type in a certain mapsquare.
const terrainType Map::getTerrainType( int x, int y ) {
    return this->gB_[x][y].getTerrainType();
}

const buildingType Map::getBuildingType( int x, int y ) {
    return this->gB_[x][y].getBuildingType();
}

void Map::personAdd( Person* P ) {
    this->gB_[P->getX()][P->getY()].personAdd(P);
}


void Map::personRemove( Person* P ) {
    this->gB_[P->getX()][P->getY()].personRemove(P);
}

void Map::buildingSetType( buildingType nType, int x, int y ) {
    this->gB_[x][y].buildingSetType( nType );
}

void Map::terrainSetType( terrainType nType, int x, int y ) {
    this->gB_[x][y].terrainSetType( nType );
}

void Map::terrainSetDesc( string nDesc, int x, int y ) {
    this->gB_[x][y].terrainSetDesc( nDesc );
}

void Map::buildingSetDesc( string nDesc, int x, int y ) {
    this->gB_[x][y].buildingSetDesc( nDesc );
}

void Map::setWarp( int x, int y, string mapName ) {
    this->gB_[x][y].setWarp( mapName );
}

void Map::setWarpX( int x, int y, int wX ) {
    this->gB_[x][y].setWarpX( wX );
}

void Map::setWarpY( int x, int y, int wY ) {
    this->gB_[x][y].setWarpY( wY );
}

void Map::setStartX( int nX ) {
    this->startX_ = nX;
}

void Map::setStartY( int nY ) {
    this->startY_ = nY;
}
