/**
* @File: Spear.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "..\..\incl\weaponh\spear.h"

using namespace std;

Spear::Spear(){
    setDamageMod( 1 );
    setDamageRoll( 10 );
    setName("Spear");
    setValue( 35 );
    setDescription( "A wooden Spear." );
}
Spear::Spear( int dm, int dr, string newName ){
    setDamageMod( dm );
    setDamageRoll( dr );
    setName( newName );
    setValue( 35 );
    setDescription( "A wooden Spear." );
}

