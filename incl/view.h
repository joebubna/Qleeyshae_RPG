/**
* @File: map.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include <Windows.h>
#include <cctype>
#include <sstream>
#include "map.h"
#include "person.h"
#include "generalfunctions.h"

using namespace std;

class View
{
    public: 
        View( int = 20 );
        
        // Displays a view of the map with a specified width and height.
        void display( Map*, Person*);
        
        //Title Screen Things
        void displayTitleScreen(); 
       
        // Displays everything on the screen using helper functions. 
        void displayScreen(Map*, Person*, string custStr = "0", int gameState = 0, bool override = 0);
        
        // The last int is the line number starting at 0.
        void displayMapLine(Map*, Person*, int = 19, int = 19, int = 0 );
        
        // Controls hud display next to the map.
        void displayHudLine(Map*, Person*, int, string dis = "0", bool override = 0);
        
        // Tile info
        string returnTileInfo( Map*, int x = 0, int y = 0);
        void displayTileInfo( Map*, int x = 0, int y = 0);
        
        string makeInventory( Person*, int inventoryPos ); // For inventory screen.       
        void displayPrompt(int = 0 ); //Displays the possible commands and the prompt
        void textColor(int fontcolor,int backgroundcolor,HANDLE screen); // Changes output colors on screen.       
        void displayEndGame(); // If the game is over and you won.
        void displayGameOver(); // If the game is over and you died.
        
        // Grabs color and outChar.
        void getPersonDisplay( Map*, int i, int line, int &color_front, string &outChar );
        
        ///////////////////
        // Not being used
        ///////////////////
        //string TitleScreenSubtitle(); 
        //string romanNumeral();
        
    private:
};
#endif
