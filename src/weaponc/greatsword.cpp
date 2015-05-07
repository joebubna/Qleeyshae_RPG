/**
* @File: greatsword.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "..\..\incl\weaponh\Greatsword.h"

using namespace std;

Greatsword::Greatsword(){
    setDamageMod( 2 );
    setDamageRoll( 8 );
    setName("Greatsword");
    setValue( 100 );
    setDescription( "A Grey Greatsword." );
}
Greatsword::Greatsword( int dm, int dr, string name ){
    setDamageMod( dm );
    setDamageRoll( dr );
    setName( name );
    setValue( 100 );
    setDescription( "A Grey Greatsword." );
}

