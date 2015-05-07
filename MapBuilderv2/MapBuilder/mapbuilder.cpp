#include "mapbuilder.h"

MapBuilder::MapBuilder() {
    ////////////////////////////////////////////////////////
    // PUT PROGRAM VERSION BELOW!!!
    ////////////////////////////////////////////////////////
    cout << "VERSION 2.0" << endl;
    
    
    cout << "Please enter the text map you would like to load: ";
    cin >> readFile;
    
    cout << endl << endl;
    
    cout << "Please enter the default terrain type for this map: ";
    cin >> defaultTerrain;
    
    cout << endl << endl;
    
    cout << "Please enter the name you'd like to save the converted file as: ";
    cin >> saveFile;
}

string MapBuilder::getType( char c ) const {
    string type = defaultTerrain;
    if (c == 'g') {
        type = "grass";
    }
    else if (c == 'r') {
        type = "rock";
    }
    else if (c == 'T') {
        type = "trees";
    }
    else if (c == '#') {
        type = "mountains";
    }
    else if (c == '~') {
        type = "river";
    }
    else if (c == '|') {
        type = "verticalRoad";
    }
    else if (c == '_') {
        type = "horizontalRoad";
    }
    else if (c == ';') {
        type = "swamp";
    }          
    else if (c == ',') {
        type = "woodFloor";
    }
    return type;
}

void MapBuilder::convert() {
    char c;
    int x = 0;
    int y = 0;
    int maxX = 0;
    int maxY = 0;
    string mapName, terrainType;
    
    // Declares an Input filestream
    ifstream datafile(readFile.c_str());
    // Declares an Output filestream.
    ofstream mapfile(saveFile.c_str());
    if (datafile.is_open()) {
        cout << "Output open!" << endl;
    }
    
    if (datafile.is_open())
    {
        while (! datafile.eof() )
        {
            datafile >> c;
            if (c == '/') {
                x = 0;
                y++;
            }
            else {
                mapfile << x << " " << y << " " << getType( c ) << " 0" << "\n";
                x++;
            }
            
            if (x > maxX) {
                maxX = x;
            }
            if (y > maxY) {
                maxY = y;
            }
        }
        cout << "Map Width: " << maxX << endl;
        cout << "Map Height: " << maxY - 1 << endl;
        
        datafile.close();
        datafile.clear();
    }   
    else cout << "Unable to open file"; 
}
