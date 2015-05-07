/**
* @File: Fist.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef FIST_H
#define FIST_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

#include "../weapon.h"

using namespace std;

class Fist : public Weapon
{
    public: 
        Fist();
        Fist( int, int ,string );
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
