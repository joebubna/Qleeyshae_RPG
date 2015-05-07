/**
* @File: longsword.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "..\..\incl\weaponh\Longsword.h"

using namespace std;

Longsword::Longsword(){
    setDamageMod( 2 );
    setDamageRoll( 8 );
    setName("Longsword");
    setValue( 75 );
    setDescription( "A Grey Longsword." );
}
Longsword::Longsword( int dm, int dr, string name ){
    setDamageMod( dm );
    setDamageRoll( dr );
    setName( name );
    setValue( 75 );
    setDescription( "A Grey Longsword." );
}

