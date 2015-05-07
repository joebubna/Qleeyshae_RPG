/**
* @File: Game.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/game.h"

Game::Game()
{
    //Seeding the Random for the rest of the features
    srand( time( NULL ) );
    // This gamestate means the player is free roaming...
    gameState = 0;
    
    // This sets the game to show the standard display options to the right of 
    // the map to start out with. This will change during gameplay.
    displayOverride = 0;

    // Creating 1 slot in the master people list to start.
    people_.resize( 1, NULL );

    // Declaring the current map to be the map with the index 0.
    cMap = 0;

    // Creating 10 slots in the master map list.
    theMapList_.resize( 10, NULL );  
}



// This function takes a keycode and passes an appropriate command to the runCommand function.
void Game::keyCommand(int someKey)
{
    string command;

    switch(someKey)
    {
        case 55: // 7
            command = "move northwest";
            runCommand(command);
            break;
        case 56: // 8
            command = "move north";
            runCommand(command);
            break;
        case 57: // 9
            command = "move northeast";
            runCommand(command);
            break;
        case 52: // 4
            command = "move west";
            runCommand(command);
            break;
        case 53: // 5
            command = "enter building";
            runCommand(command);
            break;
        case 54: // 6
            command = "move east";
            runCommand(command);
            break;
        case 49: // 1
            command = "move southwest";
            runCommand(command);
            break;
        case 50: // 2
            command = "move south";
            runCommand(command);
            break;
        case 51: // 3
            command = "move southeast";
            runCommand(command);
            break;
    };
};


// Starts a new game.
void Game::newGame() {
    // Variables
    string newPlayerName;
    
    // CREATING THE PLAYER
    // Setting the control pointer to the person created (making that the
    // person that the player controls).
    this->player = new Person;

    // Loading the player into the master person's list.
    this->people_[0] = player;
    
    // Setting the player to be a human (I.E. relateCode of 1)
    player->setRelateCode( 1 );
    
    // Grabbing and setting the player's name
    getline (cin, newPlayerName);
    player->name( newPlayerName );
    
    // Setting other new game player attributes.
    player->setAC(10);
    player->setClassName("Adventurer");
    player->setLevel(1);
    player->setHP(100);
    player->setMaxHP(100);
    player->setAC(10);
    player->setGP(1000);
    player->setEXP(0);
    player->setIsEnemy(0); // Needed or you fight yourself.
    
    // Giving the player items to start with...
    this->player->itemAdd( new Longsword );
    this->player->setWeaponEquipped(0); // Equipping the Longsword.
    
    // Giving the player other items.
    this->player->itemAdd( new Coffee );
    this->player->itemAdd( new OrcHorn );
    this->player->itemAdd( new Diamond );
    this->player->itemAdd( new Pendant );
       
    // Clearing the screen and loading the main map.
    system("CLS");
    loadMap( "main" );
}



// This loads a saved game from file. NOT USED - FOR FUTURE EXPANSION
void Game::loadGame() {
    // *** MAKE THIS READ FROM A FILE THE CURRENT MAP ***
    /*
    loadMap( "somemap" );
    */
}



// Runs the game. Starts master game loop.
void Game::run() {
    string command;
    int inventoryMove = 0;  // -1 move up 1 move down 0 stay

    // Outputting the title screen.
    myView.displayTitleScreen();

    // Prompt for new game or load from save here.
    // ADD PROMPT IN FUTURE HERE.
    bool loadGame_ = false;
    if (loadGame_) {
        loadGame();
    }
    else {
        newGame();
    }


    // if gameState is negative endgame
    while (gameState > -1) {

        if(gameState == 0) // Do Map Stuff
        {
            //do map command
            myView.displayScreen( theMapList_[cMap], this->player, displayData, gameState, displayOverride );

            // Clearing Display Data
            displayData = "";
            displayOverride = 0;

            int someKey = getch();
            switch(someKey)
            {
                case 84: // t/T
                case 116:
                    cout <<">";
                    getline(cin, command, '\n');
                    runCommand(command);
                    break;
                case 27: //esc key
                    gameState = -1;
                    break;
                case 73: // i
                case 105: // I
                    gameState = 2;
                    break;
                case 120: // x
                case 88: // X
                if( theMapList_[cMap]->getPerson(player->getX(),player->getY()) != NULL)
                {
                    if( theMapList_[cMap]->getPerson(player->getX(),player->getY())->getHP() <= 0)
                    {
                    gameState = 3;
                    }
                }
                    break;
                case 99: // c
                    command = "chat";
                    runCommand(command);
                    break;
                default:
                    keyCommand(someKey);
                    break;
            };
        }
        else if(gameState == 1) //Do battle stuff
        {
            // Let the user know a battle is starting.
            //displayData = "An enemy has attacked you!\n You are now in a battle.\n";

            // Init battle status.
            int battleStatus = 0;

            while (gameState == 1) {

                // Declare a battle.
                int x = player->getX();
                int y = player->getY();
                Battle bat( player, theMapList_[cMap]->getPerson(x,y) );

                // Clear Screen
                system("CLS");

                // Displays output on screen with battle results.
                myView.displayScreen( theMapList_[cMap], this->player, displayData, gameState);

                int someKey = getch();
                switch(someKey)
                {
                    case 84: // t/T
                    case 116:
                        cout <<">";
                        getline(cin, command, '\n');
                        runCommand(command);
                        break;
                    case 70: //F
                    case 102: //f
                        // If fleeing a battle...
                        gameState = 0;
                        move( player, player->getLastX(), player->getLastY() );
                        break;
                    case 27: //esc key
                        gameState = -1;
                        break;
                    default:
                        battleStatus = bat.run( someKey );
                        displayData = bat.output();
                        break;
                };
                
                
                // Changes gamestate if you killed enemy or died.
                if (battleStatus == 1) { // If you killed your enemy.
                    
                    // Give the player the enemy's GP
                    int moneyToGive = theMapList_[cMap]->getPerson(x,y)->getGP();
                    int currentMoney = player->getGP();
                    player->setGP( moneyToGive + currentMoney );
                    theMapList_[cMap]->getPerson(x,y)->setGP( 0 ); // Taking away the enemy's gold.
                    
                    // Give the player the enemy's Experience Value.
                    int expToGive = theMapList_[cMap]->getPerson(x,y)->getExpValue();
                    int currentExp = player->getEXP();
                    player->setEXP( expToGive + currentExp );
                    
                    // If the player has enough experience to level up, do stuff.
                    if (player->getEXP() >= player->getLevel() * 1000) {
                        
                        // Reset their stored experience
                        player->setEXP( player->getEXP() - (player->getLevel() * 1000) );
                        
                        // Increase the player's level
                        player->setLevel( player->getLevel() + 1 );
                        
                        // Give the player a higher max HP
                        player->setMaxHP( player->getMaxHP() + 10 );
                    }
                    
                    // Reset gameState to exit battle mode.
                    gameState = 0;
                }
                else if (battleStatus == 2) { // If you died.
                    // Clears Screen
                    system("CLS");
    
                    // Outputs final battle results (showing you died).
                    myView.displayScreen( theMapList_[cMap], this->player, displayData);
                    
                    // ends game loop.
                    gameState = -2;
                    
                    // Pauses so the player can see the result of the last battle round.
                    system("pause");
                }

            } // end While (gamestate == 1)
        }
        else if(gameState == 2) { // Player's Inventory
        
        //system("pause");
        myView.displayScreen( theMapList_[cMap], this->player, myView.makeInventory(this->player, inventoryMove), gameState, 1);
        inventoryMove = 0;
        int someKey = getch();
        itemType selectedItemType;
        int sIdx;
        switch(someKey)
        {
            case 84: // t/T
            case 116:
                cout <<">";
                getline(cin, command, '\n');
                runCommand(command);
                break;
            case 56: // 8
                inventoryMove --;
                break;
            case 50: // 2
                inventoryMove ++;
                    break;
            case 70: //F
            case 102: //f
                gameState = 0;
                break;
            case 69: // E
            case 101: // e
                selectedItemType = player->itemGet(player->getInventoryPos())->type();
                sIdx = player->getInventoryPos(); // selected index.
                
                if (selectedItemType == weapon) {
                    player->setWeaponEquipped( sIdx );
                    //cout << "Item Equipped!" << endl;
                }
                else if (selectedItemType == armor) {
                    player->setArmorEquipped( sIdx );
                }
                else {
                    //cout << "Cannot Equipped that item!" << endl;
                }
                break;
                
            case 68: //D
            case 100: //d
                // Drops items
                delete player->itemGet(player->getInventoryPos());
                player->itemRemove( player->itemGet(player->getInventoryPos()) );
                player->removeEmptySlots();
                player->repositionCursur();
                        
                break;
            case 66: // B
            case 98: // b
            case 27: //esc key
                gameState = 0;
                break;
            default:
                break;
            };
                
        }
        
        else if(gameState == 3) { // Checking  Dead Body's Inventory
        Person* otherPerson = theMapList_[cMap]->getPerson(player->getX(),player->getY());
        //theMapList_[cMap]->getPerson(1,2);
        myView.displayScreen( theMapList_[cMap], this->player, myView.makeInventory(theMapList_[cMap]->getPerson(player->getX(),player->getY()), inventoryMove), gameState, 1);
        
        inventoryMove = 0;
        int someKey = getch();
        switch(someKey)
        {
            case 67: // c/C
            case 99:
                cout <<">";
                getline(cin, command, '\n');
                runCommand(command);
                break;
            case 84: // t/T
            case 116:
                if(this->player->getItemAmount() < 9)
                {
                    this->player->itemAdd( otherPerson->itemGet( otherPerson->getInventoryPos() ) );                    
                    otherPerson->itemRemove( otherPerson->itemGet( otherPerson->getInventoryPos() ) );
                    //otherPerson->removeEmptySlots();
                    //cout << "fuu";
                    //system("pause");
                }
                break;
            case 56: // 8
                inventoryMove --;
                break;
            case 50: // 2
                inventoryMove ++;
                    break;
            case 70: //F
            case 102: //f
                gameState = 0;
                break;
            case 66: // B
            case 98: // b
            case 27: //esc key
                gameState = 0;
                break;
            default:
                break;
            };   
        }
    
        //runCommand( command );

        // Clear Screen
        system("CLS");

    }


    if( gameState == -1) // If you won the game
    {
        myView.displayEndGame();
    }
    else if ( gameState == -2) // If you lost the game.
    {
        myView.displayGameOver();
    }

}

void Game::loadMap(string filename, int msX, int msY ) {
    // msX = Map start X. Is Optional. Given by warp.txt to override
    // the map's default starting point.
    // filename is the same as the map's name.



    // Checks if this map already exists in memory and switches cMap to it if
    // it does exist, otherwise loads from text files.
    // Cycles through the Map List to find an unused spot to load this new map.
    bool inMem = false;
    for (int i=0; i < theMapList_.size() && inMem == false; i++) {
        if (this->theMapList_[i]) { // If this slot is empty
            if (this->theMapList_[i]->getName() == filename) {
                cMap = i; // Set the current map to this slot.
                inMem = true;
            }
        }
    }

    int sX,sY; // starting x,y location for placing the player on this map.
    if (inMem == true) {
        // Overrides map's default starting point using passed value from warps.txt
        // This is optional.
        if (msX != -1 && msY != -1) {
            sX = msX;
            sY = msY;
        }
        else {
            sX = theMapList_[cMap]->getStartX();
            sY = theMapList_[cMap]->getStartY();
        }
    }
    else {
        // Variables
        int x,y;
        string type;
        string filepath;

        // Open map whose named was given
        filepath = "maps/"+filename+"/info.txt";
        ifstream datafile(filepath.c_str());
        if (datafile.is_open())
        {
        while (! datafile.eof() )
        {
            datafile >> x >> y >> type >> sX >> sY;
        }
        datafile.close();
        datafile.clear();
        }
        else cout << "Unable to open file";

        // Overrides map's default starting point using passed value from warps.txt
        // This is optional.
        if (msX != -1 && msY != -1) {
            sX = msX;
            sY = msY;
        }

        // Cycles through the Map List to find an unused spot to load this new map.
        bool exit = false;
        for (int i=0; i < theMapList_.size() && exit == false; i++) {
            if (!this->theMapList_[i]) { // If this slot is empty
                cMap = i; // Set the current map to this slot.
                exit = true;
            }
        }

        if (exit == false) {
            // if there was no room to put it in from the loop above,
            // then add a new slot.
            this->theMapList_.push_back( NULL );
            cMap = theMapList_.size() - 1;
        }

        // Create a new map with the parameters just grabbed from the file.
        theMapList_[cMap] = new Map( filename, x, y, type, sX, sY );

        // Populating the newly created map.
        loadTerrain();
        loadBuildings();
        loadPersons();
        loadWarps();
    } // end If else (inMem == true)

    // Placing the player on the current map which was just loaded.
    player->setX( sX );
    player->setY( sY );
    theMapList_[cMap]->personAdd( player );
}

void Game::loadWarps() {
    /*
        FORMAT:
        x y mapname mapX mapY

        x = x location of warp point on current map.
        y = y location of warp point on current map.
        mapname = name of the map to warp to.
        mapX = x location to warp to.
        mapY = y location to warp to.

        mapX and MapY should be set to -1 if you want to have the player loaded
        into the default starting location of the map.
    */
    // Variables
    int x,y,wX,wY;
    string mapName, filename, filepath;

    // Open the current map
    filename = theMapList_[cMap]->getName();
    filepath = "maps/"+filename+"/warps.txt";
    ifstream datafile(filepath.c_str());
    if (datafile.is_open())
    {
    while (! datafile.eof() )
    {
        datafile >> x >> y >> mapName >> wX >> wY;
        theMapList_[cMap]->setWarp( x, y, mapName );
        theMapList_[cMap]->setWarpX( x, y, wX );
        theMapList_[cMap]->setWarpY( x, y, wY );
    }
    datafile.close();
    datafile.clear();
    }
    else cout << "Unable to open file";
}

void Game::loadPersons() {
    // TEXT FILE LAYOUT:
    // x y name classname relatecode isenemy level ac hp maxhp gp exp
    // expvalue weapon armor augment treasure desc chat

    // Variables
    int x, y, relateCode, level, ac, hp, maxHp, gp, exp, expValue;
    bool isEnemy;
    string name, className, desc, chat, weapon, armor, augment, treasure;
    string filename, filepath, trash;
    Weapon *theWeapon;
    Armor *theArmor;
    Augment *theAugment;
    Treasure *theTreasure;

    // Open the current map
    filename = theMapList_[cMap]->getName();
    filepath = "maps/"+filename+"/persons.txt";
    ifstream datafile(filepath.c_str());
    if (datafile.is_open())
    {
    while (! datafile.eof() )
    {
        datafile >> x >> y;
        getline (datafile, name, ';');
        datafile >> className >> relateCode >> isEnemy >>
        level >> ac >> hp >> maxHp >> gp >> exp >> expValue >> weapon >>
        armor >> augment >> treasure;
        getline (datafile, desc, ';');
        getline (datafile, chat, ';');
        getline (datafile, trash);

        /*
        cout
        << "Testing Data: " << endl
        << "x: " << x << endl
        << "y: " << y << endl
        << "name: " << name << endl
        << "className: " << className << endl
        << "relateCode: " << relateCode << endl
        << "isEnemy: " << isEnemy << endl
        << "level: " << level << endl
        << "ac: " << ac << endl
        << "hp: " << hp << endl
        << "maxhp: " << maxHp << endl
        << "gp: " << gp << endl
        << "exp: " << exp << endl
        << "expvalue: " << expValue << endl
        << "weapon: " << weapon << endl
        << "armor: " << armor << endl
        << "augment: " << augment << endl
        << "treasure: " << treasure << endl
        << "desc: " << desc << endl
        << "chat: " << chat << endl
        ;
        */
        
        // Creating the person.
        Person *thisPerson = new Person;
        
        // Giving the person any items assigned to them.
        if (weapon != "weapon") {
            theWeapon = str_to_weapon( weapon );
            thisPerson->itemAdd( theWeapon );
            thisPerson->setWeaponEquipped(0);
        }
        if (armor != "armor") {
            theArmor = str_to_armor( armor );
            thisPerson->itemAdd( theArmor );
            thisPerson->setArmorEquipped(1);
        }
        if (augment != "augment") {
            theAugment = str_to_augment( augment );
            thisPerson->itemAdd( theAugment );
        }
        if (treasure != "treasure") {
            theTreasure = str_to_treasure( treasure );
            thisPerson->itemAdd( theTreasure );
        }

        // Sets this person's attributes
        thisPerson->setX( x );
        thisPerson->setY( y );
        thisPerson->name( name );
        thisPerson->setClassName( className );
        thisPerson->setRelateCode( relateCode );
        thisPerson->setIsEnemy( isEnemy );
        thisPerson->setLevel( level );
        thisPerson->setHP( hp );
        thisPerson->setMaxHP( maxHp );
        thisPerson->setEXP( exp );
        thisPerson->setAC( ac );
        thisPerson->setGP( gp );
        thisPerson->setExpValue( expValue );
        thisPerson->setChatLine( chat );
        thisPerson->setDescription( desc );


        // Loads person into master list.
        this->people_.push_back( thisPerson );

        // Adds the person to the map.
        int idx = people_.size() - 1;
        theMapList_[cMap]->personAdd( people_[idx] );

        ///////////////////////////////////////////////////
        // TESTING CODE TO VARIFY IT'S WORKING
        ///////////////////////////////////////////////////
        /*
        Map *aMap = theMapList_[cMap];

        cout
        << "Testing Data: " << endl
        << "x: " << x << endl
        << "y: " << y << endl
        << "name: " << aMap->getPerson(1,1)->name() << endl
        << "className: " << aMap->getPerson(1,1)->getClassName() << endl
        << "relateCode: " << aMap->getPerson(1,1)->getRelateCode() << endl
        << "isEnemy: " << aMap->getPerson(1,1)->getIsEnemy() << endl
        << "level: " << aMap->getPerson(1,1)->getLevel() << endl
        << "ac: " << aMap->getPerson(1,1)->getAC() << endl
        << "hp: " << aMap->getPerson(1,1)->getHP() << endl
        << "maxhp: " << aMap->getPerson(1,1)->getMaxHP() << endl
        << "gp: " << aMap->getPerson(1,1)->getGP() << endl
        << "exp: " << aMap->getPerson(1,1)->getEXP() << endl
        << "expvalue: " << aMap->getPerson(1,1)->getExpValue() << endl
        << "desc: " << aMap->getPerson(1,1)->getDescription() << endl
        << "chat: " << aMap->getPerson(1,1)->getChatLine() << endl
        << "weapon: " << aMap->getPerson(1,1)->itemGet(0)->type() << endl
        ;
        */
        /*
        << "armor: " << aMap->getPerson(1,1)->getArmor()->type() << endl
        << "augment: " << aMap->getPerson(1,1)->getAugment()->type() << endl
        << "treasure: " << aMap->getPerson(1,1)->getTreasure()->type() << endl
        */



    }
    datafile.close();
    datafile.clear();
    }
    else cout << "Unable to open file";

}

void Game::loadTerrain() {
    // Variables
    int x,y;
    string type,desc;
    string filename,filepath;
    terrainType tsquare;

    // Open the current map
    filename = theMapList_[cMap]->getName();
    filepath = "maps/"+filename+"/terrain.txt";
    ifstream datafile(filepath.c_str());
    if (datafile.is_open())
    {
    while (! datafile.eof() )
    {
        datafile >> x >> y >> type;
        getline (datafile, desc);
        tsquare = str_to_terrain( type );
        theMapList_[cMap]->terrainSetType( tsquare, x, y );
        if (desc.size() > 0) {
            theMapList_[cMap]->terrainSetDesc( desc, x, y );
        }
      //cout << x << y << type << desc << endl;
    }
    datafile.close();
    datafile.clear();
    }
    else cout << "Unable to open file";
}


void Game::loadBuildings() {
    // Variables
    int x,y;
    string type,desc;
    string filename,filepath;
    buildingType bsquare;
    bool canEnter;

    // Open the current map
    filename = theMapList_[cMap]->getName();
    filepath = "maps/"+filename+"/buildings.txt";
    ifstream datafile(filepath.c_str());
    if (datafile.is_open())
    {
    while (! datafile.eof() )
    {
        datafile >> x >> y >> type >> canEnter;
        getline (datafile, desc);
        bsquare = str_to_building( type );
        theMapList_[cMap]->buildingSetType( bsquare, x, y );
        if (desc.size() > 0) {
            theMapList_[cMap]->buildingSetDesc( desc, x, y );
        }
      //cout << x << y << type << desc << endl;
    }
    datafile.close();
    datafile.clear();
    }
    else cout << "Unable to open file";
}

terrainType Game::str_to_terrain( string fs ) {
    if (fs == "grass") { return grass; }
    else if (fs == "rock") { return rock; }
    else if (fs == "trees") { return trees; }
    else if (fs == "mountains") { return mountain; }
    else if (fs == "river") { return river; }
    else if (fs == "verticalRoad") { return verticalRoad; }
    else if (fs == "horizontalRoad") { return horizontalRoad; }
    else if (fs == "swamp") { return swamp; }
    else if (fs == "woodFloor") { return woodFloor; }
    else if (fs == "carpet") { return carpet; }
}


buildingType Game::str_to_building( string fs ) {
    if (fs == "castle") { return castle; }
    else if (fs == "town") { return town; }
    else if (fs == "cave") { return cave; }
    else if (fs == "house") { return house; }
    else if (fs == "mansion") { return mansion; }
    else if (fs == "tower") { return tower; }
    else if (fs == "hut") { return hut; }
    else if (fs == "stairUp") {return stairUp; }
    else if (fs == "stairDown") {return stairDown; }
}

Weapon* Game::str_to_weapon( string fs ) {
    Weapon *theWeapon;
    if (fs == "longsword") { theWeapon = new Longsword; }
    else if (fs == "greatsword") { theWeapon = new Greatsword; }
    else if (fs == "shortsword") { theWeapon = new Shortsword; }
    else if (fs == "spear") { theWeapon = new Spear; }
    return theWeapon;
}

Armor* Game::str_to_armor( string fs ) {
    Armor *theArmor;
    theArmor = new Armor;
    return theArmor;
}

Augment* Game::str_to_augment( string fs ) {
    Augment *theAugment;
    theAugment = new Augment;
    return theAugment;
}

Treasure* Game::str_to_treasure( string fs ) {
    Treasure *theTreasure;
    if (fs == "goldenCup") { theTreasure = new GoldenCup; }
    else { theTreasure = new GoldenCup; }

    return theTreasure;
}

void Game::runCommand( string command ) {
    if (command == "move north") {
        int nX = player->getX();
        int nY = player->getY() - 1;
        move( player, nX, nY );
    }
    else if (command == "move south") {
        int nX = player->getX();
        int nY = player->getY() + 1;
        move( this->player, nX, nY );
        //this->test = "Yes";
    }
    else if (command == "move east") {
        int nX = player->getX() + 1;
        int nY = player->getY();
        move( player, nX, nY );
    }
    else if (command == "move west") {
        int nX = player->getX() - 1;
        int nY = player->getY();
        move( player, nX, nY );
    }
    else if (command == "move northeast") {
        int nX = player->getX() + 1;
        int nY = player->getY() - 1;
        move( player, nX, nY );
    }
    else if (command == "move southeast") {
        int nX = player->getX() + 1;
        int nY = player->getY() + 1;
        move( player, nX, nY );
    }
    else if (command == "move southwest") {
        int nX = player->getX() - 1;
        int nY = player->getY() + 1;
        move( player, nX, nY );
    }
    else if (command == "move northwest") {
        int nX = player->getX() - 1;
        int nY = player->getY() - 1;
        move( player, nX, nY );
    }
    else if (command == "chat") {
        int x = player->getX();
        int y = player->getY();
        if (theMapList_[cMap]->getPerson(x,y) != player) {
            displayData = theMapList_[cMap]->getPerson(x,y)->name();
            displayData += ":\n";
            displayData += theMapList_[cMap]->getPerson(x,y)->getChatLine();
            displayData += "\n ";

            displayOverride = 1;
        }
    }
    else if (command == "enter building") {
        int x = player->getX();
        int y = player->getY();

        if (theMapList_[cMap]->getWarp(x,y).size() > 0) {
            loadMap(
                theMapList_[cMap]->getWarp(x,y),
                theMapList_[cMap]->getWarpX(x,y),
                theMapList_[cMap]->getWarpY(x,y)
            );
        }
    }
}

bool Game::mapLook( Map *theMap, int x, int y ) {
    //cout << "Function mapLook" << endl;
    if ( x < theMap->getWidth() &&  x >= 0 && y < theMap->getHeight() && y >= 0 ) {
        terrainType cTerrain = theMap->getTerrainType( x, y );
        if (    cTerrain == river ||
                cTerrain == water ||
                cTerrain == mountain
            ) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

void Game::move( Person *whom, int x, int y ) {
    //cout << "Function: Move" << endl;
    if ( mapLook( theMapList_[cMap], x, y ) ) {
        //cout << "Doing Movement Functions:" << endl;
        // Updates this person's last position.
        whom->setLastX( whom->getX() );
        whom->setLastY( whom->getY() );
        
        // Updates this person's current position.
        theMapList_[cMap]->personRemove( whom );
        whom->setX( x );
        whom->setY( y );
        theMapList_[cMap]->personAdd( whom );

        if (theMapList_[cMap]->getPerson(x,y)->getHP() > 0) {
            if ( theMapList_[cMap]->getPerson(x,y)->getIsEnemy() ) {
             // This person is explicitly set as an enemy.
             gameState = 1;
            }
            else if ( theMapList_[cMap]->getPerson(x,y)->getIsEnemy() == -1 ) {
             // This person's friend or enemy status is determined by their
             // relationship code.
                if (theMapList_[cMap]->getPerson(x,y)->getRelateCode() !=
                    player->getRelateCode() )
                {
                   gameState = 1;
                }
            }
        }
    }
}

