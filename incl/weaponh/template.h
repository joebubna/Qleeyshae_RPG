/**
* @File: longsword.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef SWORD_H
#define SWORD_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

#include "../weapon.h"

using namespace std;

class Sword : public Weapon
{
    public: 
        Sword();
        Sword( int, int ,string );
        // Inspectors
        /*
        
        */
        // Setters
        /*
        
        */
    private:
        /*
        int durability_;
        int maxDurability_;
        int weight_;
        int speedPen_;*/
        
};
#endif
