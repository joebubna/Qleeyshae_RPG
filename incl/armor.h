/**
* @File: armor.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
#include "collectable.h"

using namespace std;

class Armor : public Collectable
{
    public: 
        Armor( int = 20 );
        
    private:
};
#endif
