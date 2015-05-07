/**
* @File: Fist.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "..\..\incl\weaponh\fist.h"

using namespace std;

Fist::Fist(){
    setDamageMod( 0 );
    setDamageRoll( 2 );
    setName("Spear");
}

Fist::Fist( int dm, int dr, string newName ){
    setDamageMod( dm );
    setDamageRoll( dr );
    setName( newName );
}

