/**
* @File: map.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef TERRAIN_H
#define TERRAIN_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "globals.h"
#include "collectable.h"

using namespace std;

enum terrainType { 
    noTerrain, grass, tree, trees, rock, mud, water, river, bush, sand, gravel, 
    desert, dirt, mountain, swamp, verticalRoad, horizontalRoad, woodFloor, carpet
    };

class Terrain
{
    public: 
        Terrain();
        Terrain( terrainType );
        
        // Inspectors
        const terrainType type();
        string getDesc() const { return desc_; };
        const Collectable* itemGet( int idx ); // returns a single item.
        const vector <Collectable*> itemList(); // returns all the items.
        
        // Setters
        void type( terrainType );
        void desc( string );
        
        // Inventory related
        void itemAdd( Collectable* );
        void itemRemove( Collectable* );
        
    private:
        terrainType type_;
        string desc_;
        vector <Collectable*> inventory_;
};
#endif
