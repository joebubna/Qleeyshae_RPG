/**
* @File: view.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/view.h"
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGREY 7
#define DARKGREY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define BLINK 128
View::View( int w_ ) {

}
void View::displayMapLine( Map *aMap, Person *thePlayer, int w_, int h_, int line )
{
    HANDLE h;
    h=GetStdHandle(-11);
    int color_attribute, color_front, color_back;
    string outChar; // The character that will be displayed on the map.
    color_back = BLACK;
                    
    int bX = thePlayer->getX();
    int bY = thePlayer->getY();
    
    int sX = bX - 9;
    int eX = bX + 9;
    
    //int j = bY;
    //for( int j = sY; j <= eY; j++ ) {    
        for( int i = sX; i <= eX; i++ )
        {   
            
            if (line < 0 || line > h_ || i < 0 || i > w_)
            {
                color_front = BROWN;
                outChar = "# ";
            }
            else {
                // display terrain in the square
                    
                switch( aMap->getTerrainType(i,line) )
                {
                    case grass:
                        color_front = GREEN;
                        //color_back = GREEN;
                        outChar = ". ";
                        break;
                    case tree:
                        color_front = LIGHTGREEN;
                        //color_back = GREEN;
                        outChar = "T ";
                        break;
                    case trees:
                        color_front = LIGHTGREEN;
                        //color_back = GREEN;
                        outChar = "T ";
                        break;
                    case mud:
                        outChar = "M ";
                        break;
                    case rock:
                        color_front = LIGHTGREY;
                        //color_back = GREEN;
                        outChar = ". ";
                        break;
                    case water:
                        color_front = LIGHTBLUE;
                        //color_back = BLUE;
                        outChar = "~ ";
                        break;
                    case river:
                        color_front = LIGHTBLUE;
                        //color_back = BLUE;
                        outChar = "~ ";
                        break;
                    case bush:
                        outChar = "B ";
                        break;
                    case sand:
                        outChar = "S ";
                        break;
                    case gravel:
                        outChar = "G ";
                        break;
                    case dirt:     
                        outChar = "D ";  
                        break;
                    case desert:
                        outChar = "D ";
                        break;
                    case mountain:
                        color_front = BROWN;
                        //color_back = GREEN;
                        outChar = "# ";
                        break;
                    case swamp:
                        color_front = CYAN;
                        //color_back = MAGENTA;
                        outChar = "; ";
                        break;
                    case verticalRoad:
                        color_front = YELLOW;
                        //color_back = BROWN;
                        outChar = "| ";
                        break;
                    case horizontalRoad:
                        color_front = YELLOW;
                        //color_back = BROWN;
                        outChar = "_ ";
                        break;  
                    case woodFloor:
                        color_front = BROWN;
                        //color_back = BROWN;
                        outChar = ", ";
                        break;        
                    case carpet:
                        color_front = LIGHTRED;
                        outChar = ". ";
                        break;
                };
                    
                if (bX == i && bY == line) {
                // The square has the player in it...
                    color_front = LIGHTRED;
                    outChar = "@ ";
                }
                else if( aMap->getBuildingType(i,line) ) {
                //the square at [i,j] has a building in it...
                    switch( aMap->getBuildingType(i,line) ) {
                        case castle:
                            color_front = LIGHTCYAN;
                            outChar = "* ";
                            break;
                        case town:
                            color_front = LIGHTCYAN;
                            outChar = "* ";
                            break;
                        case cave:
                            color_front = LIGHTCYAN;
                            outChar = "* ";
                            break;
                        case house:
                            color_front = LIGHTRED;
                            outChar = "* ";
                            break;  
                        case stairUp:
                            color_front = LIGHTGREY;
                            outChar = "< ";
                            break;
                        case stairDown:
                            color_front = LIGHTGREY;
                            outChar = "> ";
                            break;
                    };        
                }                        
                else if (aMap->getPerson(i,line)) {
                // The square at [i,j] has a person(s) in it.
                    if (aMap->getPerson(i,line)->getHP() > 0) {
                        getPersonDisplay( aMap, i, line, color_front, outChar );                            
                    }
                    else {
                        getPersonDisplay( aMap, i, line, color_front, outChar );
                        color_front = CYAN;
                        //outChar = "Y ";
                    }
                }
                
            } // end if off map
            
            // ACTUALLY DISPLAYING STUFF
            color_attribute = _rotl(color_back,4) | color_front;
            SetConsoleTextAttribute(h,color_attribute); // Setting screen color.
            cout << outChar;
            
        //}
        //cout << endl;
    }
    
    //Set color back to white.
    color_front = WHITE;
    color_back = BLACK;;
    color_attribute = _rotl(color_back,4) | color_front;
    SetConsoleTextAttribute(h,color_attribute); // Setting screen color.
    
};


void View::getPersonDisplay( Map *aMap, int i, int line, int &color_front, string &outChar ) {
    if ( aMap->getPerson(i,line)->getClassName() == "Orc" ) {
        color_front = LIGHTGREEN;
        outChar = "o ";
    }
    else if( aMap->getPerson(i,line)->getClassName() 
            == "Elf" ) {
        color_front = LIGHTGREEN;
        outChar = "E ";
        }
    else if(aMap->getPerson(i,line)->getClassName() 
            == "Human" ) {
        color_front = WHITE;
        outChar = "@ ";
        }
    else if(aMap->getPerson(i,line)->getClassName() 
            == "Goblin" ) {
        color_front = BROWN;
        outChar = "g ";
        }
    else if(aMap->getPerson(i,line)->getClassName() 
            == "Kobold" ) {
        color_front = LIGHTGREEN;
        outChar = "k ";
       }
    else if(aMap->getPerson(i,line)->getClassName() 
            == "Croc" ) {
        color_front = MAGENTA;
        outChar = "c ";
       }
    else if(aMap->getPerson(i,line)->getClassName() 
            == "Dwarf" ) {
        color_front = CYAN;
        outChar = "D ";
        }   
    else if(aMap->getPerson(i,line)->getClassName() 
            == "OrcChief" ) {
        color_front = LIGHTMAGENTA;
        outChar = "o ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "FemaleHuman" ) {
        color_front = LIGHTMAGENTA;
        outChar = "@ ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "FemaleElf" ) {
        color_front = GREEN;
        outChar = "E ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "FemaleDwarf" ) {
        color_front = LIGHTCYAN;
        outChar = "D ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "Guard" ) {
        color_front = LIGHTBLUE;
        outChar = "@ ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "GuardDwarf" ) {
        color_front = LIGHTBLUE;
        outChar = "D ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "GuardElf" ) {
        color_front = LIGHTBLUE;
        outChar = "E ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "King" ) {
        color_front = MAGENTA;
        outChar = "@ ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "Queen" ) {
        color_front = LIGHTMAGENTA;
        outChar = "@ ";
    }
    else if(aMap->getPerson(i,line)->getClassName()
            == "Cow" ) {
        color_front = BROWN;
        outChar = "C ";
    }
} // END getPersonDisplay( int &color_front, string &outChar )


void View::displayTileInfo(Map *aMap, int x, int y)
{
    string text;
    
    cout << "You are standing ";
    switch( aMap->getTerrainType(x,y) )
    {
        case grass:
            text = "on some grass. ";
            break;
        case tree:
            text = "in a forest. ";
            break;
        case trees:
            text = "in a forest. ";
            break;
        case mud:
            text = " knees deep in Mud! ";
            break;
        case rock:
            text = "on solid ground. ";
            break;
        case water:
            text = "~ ";
            break;
        case river:
            text = "~ ";
            break;
        case bush:
            text = "B ";
            break;
        case sand:
            text = "S ";
            break;
        case gravel:
            text = "G ";
            break;
        case dirt:     
            text = "D ";  
            break;
        case desert:
            text = "D ";
            break;
        case mountain:
            text = "# ";
            break;
        case swamp:
            text = "in a thick swampy soup.";
            break;
        case verticalRoad:
            text = "on a Road.";
            break;
        case horizontalRoad:  
            text = "on a Road.";
            break;    
        case woodFloor:
            text = "on a wood floor.";
            break;     
        case carpet:
            text = "on a lush velvet carpet.";
            break;
        };
    cout << text;
};

string View::returnTileInfo(Map *aMap, int x, int y)
{
    string text;
    
    text = "You are standing ";
    switch( aMap->getTerrainType(x,y) )
    {
        case grass:
            text += "on some grass. ";
            break;
        case tree:
            text += "in a forest. ";
            break;
        case trees:
            text += "in a forest. ";
            break;
        case mud:
            text += " knees deep in Mud! ";
            break;
        case rock:
            text += "on solid ground. ";
            break;
        case water:
            text += "~ ";
            break;
        case river:
            text += "~ ";
            break;
        case bush:
            text += "B ";
            break;
        case sand:
            text += "S ";
            break;
        case gravel:
            text += "G ";
            break;
        case dirt:     
            text += "D ";  
            break;
        case desert:
            text += "D ";
            break;
        case mountain:
            text += "# ";
            break;
        case swamp:
            text += "in a thick swamp.";
            break;
        case verticalRoad:
            text += "on a Road.";
            break;
        case horizontalRoad:  
            text += "on a Road.";
            break;     
        case woodFloor:  
            text += "on a wood floor.";
            break;    
        case carpet:
            text += "on a lush velvet carpet.";
            break;
        };
    return text;
};

void View::displayScreen(Map *aMap, Person *thePlayer, string custStr, int gameState, bool override)
{
    int sideSize = 9; // if map is 19, 10 is center and 9 on each side.
    int w_ = aMap->getWidth() - 1;
    int h_ = aMap->getHeight() - 1;
    
    for(int i = -1 * sideSize; i < sideSize + 1; i++)
    {
        displayMapLine( aMap, thePlayer, w_, h_, i + thePlayer->getY() );
        cout << "   ";
        
        if (custStr == "0") {
            displayHudLine( aMap, thePlayer, i + sideSize );
        }
        else {           
            displayHudLine( aMap, thePlayer, i + sideSize, custStr, override );
        }
        
        /*
        if ( i == 7 )
        {
            displayTileInfo(aMap, thePlayer->getX(), thePlayer->getY());
        };
        */
        cout << endl;
    };
    cout << endl;
    displayPrompt(gameState);
};

void View::displayPrompt(int type)
{
    //types
    // 0 - on the map
    // need to add these. :)
    // 1 - battle
    // 2 - shop
    switch(type)
    {
        
    case 0:
        cout << "[i]nventory    e[x]amine    [t]ext command    [a]ttack   [c]hat ";
        cout << endl << endl;
        cout << ">";
        break;
    case 1:
        cout << "[i]nventory    [a]ttack    [d]efend    [r]ecover    [f]lee combat  ";
        cout << endl << endl;
        cout << ">";
        break;
    case 2:
        cout << "[e]quipt [d]rop [b]back ";
        cout << endl << endl;
        cout << ">";
        break;
    case 3:
        cout << "[u]se [t]ake [b]back ";
        cout << endl << endl;
        cout << ">";
        break;
    case 4:
        cout << "Are you sure? [y]es [n]o";
        cout << endl << endl;
        cout << ">";
    default:
        cout << "[i]nventory    e[x]amine    [t]ake    [a]ttack   [c]hat";
        cout << endl << endl;
        cout << "default>";
        break;
    }
};



string View::makeInventory( Person* thePlayer, int inventoryMove )
{
        stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
       
       
        vector <Collectable*> items = thePlayer->itemList();
        
        int count = 0;
        int inventoryPos = thePlayer->getInventoryPos();
        
        if(inventoryMove < 0 && inventoryPos > 0)
        { 
            thePlayer->setInventoryPos(inventoryPos + inventoryMove);
        }
        else if(inventoryMove > 0 && thePlayer->getInventoryPos() < items.size() - 1 )
        {
            thePlayer->setInventoryPos(inventoryPos + inventoryMove);
        };
        
        
        
        // name and stats
        string myString = "     - " + thePlayer->name() +"'s Items - \n";        
        
        if(items[thePlayer->getInventoryPos()] != NULL)
        {
            /*
            if(items[thePlayer->getInventoryPos()]->getDescription().size() > 32)
            {
                stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
                ss <<  "Value: " << items[thePlayer->getInventoryPos()]->getValue() << "\n";
                myString += ss.str();
                myString += "Desc: " + items[thePlayer->getInventoryPos()]->getDescription().substr(0,32) + "\n";
                myString += "      " + items[thePlayer->getInventoryPos()]->getDescription().substr(32) +"\n";
            }
            else
            {*/
                
                stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
                if (items[thePlayer->getInventoryPos()]->type() == weapon) {
                    int dMax = items[thePlayer->getInventoryPos()]->getDamageRoll() + items[thePlayer->getInventoryPos()]->getDamageMod();
                    int dMin = items[thePlayer->getInventoryPos()]->getDamageMod();
                    ss <<  "Attack: " << dMin << "-" << dMax << "  Def: N/A\n";
                }
                else {
                    ss <<  "Attack: N/A  Def: N/A\n";
                }
                //myString += ss.str();
                ss <<  "Value: " << items[thePlayer->getInventoryPos()]->getValue() << "\n";
                myString += ss.str();
                myString += "Desc: " + items[thePlayer->getInventoryPos()]->getDescription() + "\n";
                myString += " \n";
            //}
        }
        else
        {
            myString +=       "Attack:  N/A  Def: N/A\n";
            myString += " \n";
            myString += "Desc: \n";
            myString += " \n";
        }
        myString += " \n";
        
        //Items you have
        for(int i = 0; i < items.size(); i ++)
        {
            if( items[i] != NULL)
            {
                
                stringstream ss;
                if( thePlayer->getInventoryPos() == i) ss << "-> ";
                ss << i  << " " << items[i]->getName();
                
                /////////////////////////////////
                // Determines if item is equiped
                /////////////////////////////////
                if ( thePlayer->getWeaponEquipped() == thePlayer->itemGet(i) ) {
                    ss << " (Equipped)";
                }
                else if ( thePlayer->getArmorEquipped() == thePlayer->itemGet(i) ) {
                    ss << " (Equipped)";
                }
                
                
                ss << endl;
                myString += ss.str();
                count ++;
            }
            else
            {
                stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
                if( thePlayer->getInventoryPos() == i) ss << "-> ";
                ss << i  << " [ empty slot ]\n";
                myString += ss.str();
                count ++;
            }
            
        }
        
        //Empty items        
        if(count < 9)
        {
            for(int i = count; i < 10; i ++)
            {
                stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
                ss << i  << " [ empty slot ]\n";
                myString += ss.str();
                
            }
        }
       return myString;
};



void View::displayHudLine(Map *theMap, Person* thePlayer, int line, string display, bool override)
{
    // Variables
    string MSDesc,TDesc,warpDesc;
    string blank = " \n";
    string strOut;
    int dline;
    stringstream ss (stringstream::in | stringstream::out | stringstream::app | stringstream::ate);
    int pX = thePlayer->getX();
    int pY = thePlayer->getY();
    
    if (override == false) {
        if (display == "") {
            if (theMap->getWarp(pX,pY).size() > 0) {
                    warpDesc = "Entrance to ";
                    warpDesc += str_first_to_upper( theMap->getWarp(pX,pY) );
                    warpDesc += ".\n \n ";
            }
            
            // Grabbing Terrain description
            MSDesc = trim(theMap->terrainGetDesc( pX, pY ));
            if (MSDesc.size() < 1 || MSDesc == "0") {
                MSDesc = returnTileInfo(theMap, pX, pY );
            }
            MSDesc += "\n";
            //MSDesc = strWrap( MSDesc, 37 );
            
            // Grabbing the Person description
            if (theMap->getPerson( pX, pY )->getHP() > 0) {
                TDesc = trim(theMap->getPerson( pX, pY )->getDescription());
                TDesc += "\n";
            }
            //TDesc = strWrap( TDesc, 37 );
            
            // Adding the terrain info and any custom display text together.
            display = blank + warpDesc + MSDesc + TDesc;
        } // end if (display == "") {
        else {
            display = blank + display;
        }
              
    } // end if Override == false
    
    // Makes sure string isn't too long.
    display = strWrap( display, 37 );
    
    // Takes a display string passed to it and splits each line into a vector.
    vector< string > displayVector;
    if (display != "0") {
        explode(display, "\n", displayVector);
    }
    
    // Takes the map name and makes the first character uppercase.
    string mName = str_first_to_upper( theMap->getName() );
    
    switch(line)
    {
        case 0:
            ss << thePlayer->name();
            break;
        case 1:
            ss << "Lv.     " << thePlayer->getLevel() << " " << thePlayer->getClassName();           
            break;
        case 2:
            ss << "HP:     " << thePlayer->getHP() << "/" << thePlayer->getMaxHP();
            break;
        case 3:
            ss << "AC:     " << thePlayer->getAC();
            break;
        case 4:
            ss << "GP:     "<< thePlayer->getGP();
            break;
        case 5:
            ss << "Exp:    " << thePlayer->getEXP() << "/" << thePlayer->getMaxEXP();
            break;
        case 6:
            //cout << "The Riverbank of Q'leeyshae ";          
            ss << "Location: " << mName << " (" << thePlayer->getX() << ',' << thePlayer->getY() << ')';
            break;
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            dline = line - 7;
            if ( dline < displayVector.size() && dline >= 0) {
                strOut = trim(displayVector.at(dline));
            }
            break;
            
            
            
            /*   Should add a View Key Option
            
            # - mountains. unpassable
            . - grassland, normal ground.
            _ - horizontal road
            | - vertical road
            * - place of interest that can be entered. caves, towns, etc.
            + - town. unpassable, simple dressing to surround the *.
            T - trees.
            ; - swampland.
            ~ - river.
    
            */
       

    }
    
    // Outputting to screen.
    if (override == true) {
        // If override is true, then disregards the normal info it puts on the
        // screen such as HP, LEVEL, etc, and just puts out what you passed to 
        // it.
        strOut = "";
        if ( line < displayVector.size() ) {
           strOut = trim(displayVector.at(line));
        }
    }
    else {
        if (line < 7) {
            strOut = ss.str();
        }
    }
    cout << strOut;
};


void View::displayTitleScreen(){
    
    
    /*srand( time(NULL) );
    string title = "Ultimate Mystic Adventurers Quest Of Fire and Lightning " + romanNumeral();
    string subtitle = TitleScreenSubtitle();
    cout << setw() << "Ultimate Mystic Adventurers Quest Of Fire and Lightning " << romanNumeral()  << endl;
    cout << setw()  << subtitle << endl << endl << endl;
    */
    cout << " ============================================================================== "
         << "|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"
         << "|+                                                                            +|"
         << "|+                           ====================                             +|"     
         << "|+                           ====================                             +|"
         << "|+                           ==                                               +|"
         << "|+                           ==                                               +|"
         << "|+                           ==                                               +|"
         << "|+                           ==                                               +|"
         << "|+                           ==                                               +|"
         << "|+                           ====================                             +|"
         << "|+          Ultimate Mystic Adventurers Quest Of Fire and Lightning V         +|"
         << "|+                  Return of the Black Rain of the Darkqueen                 +|"
         << "|+                          Chapter 11: The Quickening                        +|"
         << "|+                           ====================                             +|"
         << "|+                                             ==                             +|"
         << "|+                                             ==                             +|"
         << "|+                                             ==                             +|"
         << "|+                                             ==     ________                +|"
         << "|+                                             ==    |SAVE US!|               +|"
         << "|+                                             ==    |________>               +|"
         << "|+                           ====================               \\O/           +|"
         << "|+                           ====================                |            +|"
         << "|+                                                              / \\           +|"
         << "|++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|"
         << " ============================================================================== " ;

    cout << "Through the history of the land of Q'leeyshae heroes have arisen in\n" 
         << "troubled times. The Dark Queen who nearly claimed all life itself has\n"
         << "returned. Her blackened rain falls upon the land, choking crops and\n"
         << "stagnating the lives of all who are exposed to it.\n\n"
         << "Have ye the courage to take upon yourself the mark of the hero?\n"
         << "If you believe you are the chosen one...\n"
         << "Write your name and enter the world of Q'leeyshae\n\n"
         << "Name:  ";
       
    
}
/*
string View::TitleScreenSubtitle(){
    int title = ( rand() % 5 );
    string subtitle;
    switch (title){
        case 0:
            subtitle = "Wrath of Gromnack of Steel";
            break;
        case 1:
            subtitle = "Revenge of the Heavens";
            break;
        case 2: 
            subtitle = "Return of the Black Rain of Darkqueen: The Quickening";
            break;  
        case 3: 
            subtitle = "The Daughters of Tyranny";
            break;
        case 4: 
            subtitle = "The Return of the Fellowship of the Eight Towers";
            break;
        case 5: 
            subtitle = "The Return of your Step-Mother";
            break;
    }   
    return subtitle;
}

string View::romanNumeral(){
    int title = (rand() % 6);
    string numeral;
    switch (title){
        case 0:
            numeral = "";
            break;
        case 1:
            numeral = "II";
            break;
        case 2: 
            numeral = "III";
            break;  
        case 3: 
            numeral = "IV";
            break;
        case 4: 
            numeral = "V";
            break;
        case 5: 
            numeral = "VI";
            break;
        case 6: 
            numeral = "VII";
            break;
        case 7: 
            numeral = "VIII";
            break;
    }   
    return numeral;   
}*/


void View::displayEndGame() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    // Outputs Sound
    char c = 7;
    cout << c;
    
    // Text
    cout <<"      * Y O U   W I N *" << endl;
    cout << endl;
    cout << c;
    cout <<"Thanks for playing!";
}


void View::displayGameOver() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    
    // Outputs sound.
    char c = 7;
    cout << c;
    
    // Text
    cout <<"      * G A M E   O V E R *" << endl;
    cout <<"      * Y O U   H A V E   D I E D ! *" << endl;
    cout << endl;
    cout << c;
    cout << c;
    cout << c;
    cout <<"Thanks for playing!";
}
