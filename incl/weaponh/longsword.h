/**
* @File: longsword.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef LONGSWORD_H
#define LONGSWORD_H
#include "../weapon.h"
using namespace std;

class Longsword : public Weapon
{
    public: 
        Longsword();
        Longsword( int, int ,string );
    private:
        /*
        int durability_;
        int maxDurability_;
        int weight_;
        int speedPen_;*/
        
};
#endif
