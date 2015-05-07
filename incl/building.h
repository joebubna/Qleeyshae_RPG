/**
* @File: map.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
//#include "globals.h"

using namespace std;

enum buildingType { 
    noBuilding, castle, hut, town, cave, house, mansion, tower, stairUp, stairDown
    };

class Building
{
    public: 
        Building();
        Building( buildingType );
        Building( buildingType, int nx, int ny );
        
        // Inspectors
        buildingType type() const;
        int getX() const;
        int getY() const;
        
        // Setters
        void type( buildingType );
        void setX( int );
        void setY( int );
        void desc( string );
        
    private:
        buildingType type_;
        string desc_;
        int cX_;
        int cY_;
};
#endif
