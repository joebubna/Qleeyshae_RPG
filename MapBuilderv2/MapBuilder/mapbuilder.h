/**
* @File: MapBuilder.h
* @Created By: Josiah Bubna
*/

#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class MapBuilder
{
    public: 
        MapBuilder();
        void convert();
        string getType( char ) const;
        
    private:
        string readFile;
        string saveFile;
        string defaultTerrain;
};
#endif
