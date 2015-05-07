/**
* @File: collectable.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
/*
#include "weapon.h"
#include "augment.h"
#include "armor.h"
#include "treasure.h"
*/

using namespace std;

enum itemType { 
    blank, weapon, augment, armor, treasure
    };

class Collectable
{
    public: 
        Collectable();
        
        // Inspectors
        itemType type() const;
        string getName() const { return this->name_; };
        void setName(string name);
        // Mutators
        void type( itemType );
        void setValue( int newVal = 10);
        int getValue();
        void setDescription(string dec = "Default item");
        string getDescription();
        
        
        // Virtual Functions:
        virtual int getDamageMod() const {};
        virtual int getDamageRoll() const {};
        virtual void setDamageMod( int ) {};
        virtual void setDamageRoll( int ) {};
        
    private:
        itemType type_;
        string description_;
        string name_;
        int value_;
        int weight_;
        
};
#endif
