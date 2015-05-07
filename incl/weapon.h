/**
* @File: weapon.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "collectable.h"

using namespace std;

/*enum weaponType { 
    longsword, spear, shortsword, greatsword, powerto6greatsword
    };*/

class Weapon : public Collectable
{
    public: 
        Weapon();
        
        // Inspectors
        //weaponType weapon() const { return this->type_; };
        //string getName() const { return this->name_; };
        int getDamageMod() const { return this->damageMod_; };
        int getDamageRoll() const { return this->damageRoll_; };
       
        // Setters
        //void weapon( weaponType );
        //void setName( string );
        void setDamageMod( int );
        void setDamageRoll( int );
        
    private:
        //weaponType type_;
        int damageMod_;
        int damageRoll_;
        /*string name_;
        int durability_;
        int maxDurability_;
        int weight_;
        int speedPen_;*/
        
};
#endif
