/**
* @File: map.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "mapsquare.h"
#include "person.h"
//#include "globals.h"

using namespace std;

class Map
{
    public: 
        Map( string name, int = 20, int = 20, string type = "outdoor", 
            int sX = 0, int sY = 0 );
        
        // Inspectors
        string getType() const { return type_; };
        string terrainGetDesc( int x, int y ) const { return gB_[x][y].terrainGetDesc(); };
        const terrainType getTerrainType( int x, int y );
        const buildingType getBuildingType( int x, int y );
        int getWidth() const { return width_; };
        int getHeight() const { return height_; };
        int getStartX() const { return startX_; };
        int getStartY() const { return startY_; };
        string getName() const { return name_; };
        Person* getPerson( int x, int y, int i = 0 ) { return gB_[x][y].getPerson(i); };
        
        string getWarp(int x, int y) const { return gB_[x][y].getWarp(); };
        int getWarpX(int x, int y) const { return gB_[x][y].getWarpX(); };
        int getWarpY(int x, int y) const { return gB_[x][y].getWarpY(); };
        void setWarp(int x, int y, string mapname);
        void setWarpX( int x, int y, int wX );
        void setWarpY( int x, int y, int wY );
        void setStartX( int );
        void setStartY( int );
        
        // Setters
        void personAdd( Person* );
        void personRemove( Person* );
        void buildingSetType( buildingType, int x, int y );
        void terrainSetType( terrainType, int x, int y );
        void terrainSetDesc( string, int x, int y );
        void buildingSetDesc( string, int x, int y );
        
        
    private:   
        int width_;
        int height_;
        int startX_;
        int startY_;
        string name_;
        string type_;
        
        // gB is short for Game Board
        vector< vector<MapSquare> > gB_;       
};
#endif
