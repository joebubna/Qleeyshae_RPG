/**
* @File: Spear.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef SPEAR_H
#define SPEAR_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

#include "../weapon.h"

using namespace std;

class Spear : public Weapon
{
    public: 
        Spear();
        Spear( int, int ,string );
        //Inherited Inspectors/setters
        /*
        int getDamageMod() const { return this->damageMod_; };
        int getDamageRoll() const { return this->damageRoll_; };
        string getName() const { return this->name_; };
        void setDamageMod( int );
        void setDamageRoll( int );
        void setName( string )*/
};
#endif
