/**
* @File: world.h
* @Created By: Josiah Bubna
* @Created Date: 05/04/2009
*/

#ifndef MAPSQUARE_H
#define MAPSQUARE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

#include "terrain.h"
#include "building.h"
#include "person.h"

using namespace std;

class MapSquare {
    public:
        MapSquare();
        
        // Terrain related
        //Terrain& terrain();
        const terrainType getTerrainType();
        string terrainGetDesc() const { return terrain_.getDesc(); };
        void terrainSetType( terrainType );
        void terrainSetDesc( string );
        
        // Building related
        const buildingType getBuildingType();
        void buildingSetType( buildingType );
        void buildingSetDesc( string );
        
        // Person related
        void personAdd( Person* );
        void personRemove( Person* );
        Person* getPerson( int i ) { return people_[i]; };
        
        void setWarp( string newWarp ) { warp_ = newWarp; };
        void setWarpX( int nx ) { warpX_ = nx; };
        void setWarpY( int ny ) { warpY_ = ny; };
        string getWarp() const { return warp_; };
        int getWarpX() const { return warpX_; };
        int getWarpY() const { return warpY_; };
        
    
    private:
        
        // The terrain for this map square.
        Terrain terrain_;
        
        // The building located on this map square (if any)
        Building building_;
        
        // A vector of pointers to People
        vector <Person*> people_;
               
        //Pointer to another map if this is a warp point.
        string warp_; // Name of map to warp to.
        // X coordinate to warp to (if not specified, will go to map default).
        int warpX_; 
        // Y coordinate to warp to (if not specified, will go to map default).
        int warpY_;
};
#endif
