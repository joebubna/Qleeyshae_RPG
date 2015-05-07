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
#include "..\..\incl\weaponh\Sword.h"

using namespace std;

Sword::Sword(){
    setDamageMod( 1 );
    setDamageRoll( 8 );
    setName("Sword");
}
Sword::Sword( int dm, int dr, string name ){
    
}

