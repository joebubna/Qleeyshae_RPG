/**
* @File: game.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <conio.h>
#include "view.h"
#include "map.h"
#include "collectable.h"
#include "person.h"
#include "weapon.h"
#include "weaponh/weaponList.h"
#include "armor.h"
#include "treasure.h"
#include "treasureh/treasureList.h"
#include "augment.h"
#include "battle.h"
#include "generalfunctions.h"

using namespace std;

enum direction { 
    N, NE, E, SE, S, SW, W, NW
    };

class Game
{
    public: 
        Game();
        void run();
        
        // Takes a map and x,y coordinates; looks if movement is valid
        // and completes the move if is valid.
        void move( Person* whom, int x, int y );   
        
        // Executes a game command.
        void runCommand( string command );
        
        void keyCommand(int someKey);
        void textCommand(string someText);
         
    private:
        // A vector of maps.
        vector< Map* > theMapList_;
        
        // A vector of persons
        vector<Person*> people_;
        Person *player; // A pointer to whatever person the player controls.
        
        // The UI for the game
        View myView;
        
        // Important variables.
        int cMap; // The current map in use.
        int gameState; // 0 - WorldMap, 1 - Battle, 2 - Shopping.  -1 - end game
        string displayData; // Text that gets displayed on the side of the map.
        int displayOverride; // Controls whether you get the whole side of the map for your text or not.
        
        
        // Beginning of game functions
        void loadGame();
        void newGame();
        
        // World loading functions
        void loadMap( string, int msX = -1, int msY = -1 );
        void loadTerrain();
        void loadBuildings();
        void loadPersons();
        void loadWarps();
        
        // Conversion from text file to game type functions (related to world loading)
        terrainType str_to_terrain( string fs );
        buildingType str_to_building( string fs );
        Weapon* str_to_weapon( string fs );
        Armor* str_to_armor( string fs );
        Augment* str_to_augment( string fs );
        Treasure* str_to_treasure( string fs );
        
        // Checks if this person can move into the coordinates given. Yes/No.
        bool mapLook( Map* theMap, int x, int y );
        
        // Getting key strokes    --- the input
        char getKey();

};
#endif
