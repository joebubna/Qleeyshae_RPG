/**
* @File: MapSquare.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/mapsquare.h"

MapSquare::MapSquare() {
    people_.resize( 3, NULL ); 
    terrain_ = grass;
    //warpX_ = -1;
    //warpY_ = -1;
}


const terrainType MapSquare::getTerrainType() {
   return this->terrain_.type(); 
}

void MapSquare::terrainSetType( terrainType newType ) {
    this->terrain_.type( newType );
}

void MapSquare::terrainSetDesc( string newDesc ) {
    this->terrain_.desc( newDesc );
}


const buildingType MapSquare::getBuildingType() {
    return this->building_.type();
}

void MapSquare::buildingSetType( buildingType newType ) {
    this->building_.type( newType );
}

void MapSquare::buildingSetDesc( string newDesc ) {
    this->building_.desc( newDesc );
}

void MapSquare::personAdd( Person* newPerson ) {
    // This cycles through the vector and checks if there's an empty
    // slot to load the person into.
    bool exit = false;
    for (int i=0; i < people_.size() && exit == false; i++) {
        if (!this->people_[i]) { // If this slot is empty
            this->people_[i] = newPerson; // add the person.
            exit = true;
        }
    }
    
    if (exit == false) {
        // if there was no room to put the person in from the loop above,
        // then add a new slot with them in it.
        this->people_.push_back( newPerson );
    }
    //this->people_[0] = newPerson;
}

void MapSquare::personRemove( Person* thePerson ) {
    for (int i=0; i < people_.size(); i++) {
        if (this->people_[i] == thePerson) {
            // Drops this vector space.
            this->people_[i] = NULL;
            this->people_.erase( people_.begin() + i );
        }
    }
}



