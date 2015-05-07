/**
* @File: Shortsword.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "..\..\incl\weaponh\shortsword.h"

using namespace std;

Shortsword::Shortsword(){
    setDamageMod( 1 );
    setDamageRoll( 4 );
    setName("Shortsword");
    setValue( 50 );
    setDescription( "A Grey Shortsword." );
}
Shortsword::Shortsword( int dm, int dr, string newName ){
    setDamageMod( dm );
    setDamageRoll( dr );
    setName( newName );
    setValue( 50 );
    setDescription( "A Grey Shortsword." );
}

