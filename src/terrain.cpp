/**
* @File: Terrain.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/Terrain.h"



Terrain::Terrain() {
    this->type( grass );
}

Terrain::Terrain( terrainType initType = grass ) {
    this->type( initType );
}

void Terrain::type( terrainType newType ) {
    this->type_ = newType;
}

void Terrain::desc( string newDesc ) {
    this->desc_ = newDesc;
}

const terrainType Terrain::type()  {
    return type_;
}

const Collectable* Terrain::itemGet( int idx ) {
    return this->inventory_[idx];
}

const vector <Collectable*> Terrain::itemList() {
    return this->inventory_;
}

void Terrain::itemAdd( Collectable* newItem) {
    this->inventory_.push_back( newItem );
}

void Terrain::itemRemove( Collectable* theItem ) {
    for (int i=0; i < inventory_.size(); i++) {
        if (this->inventory_[i] == theItem) {
            this->inventory_[i] = NULL;
        }
    }
}
