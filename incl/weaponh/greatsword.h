/**
* @File: Greatsword.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef GREATSWORD_H
#define GREATSWORD_H
#include "../weapon.h"
using namespace std;

class Greatsword : public Weapon
{
    public: 
        Greatsword();
        Greatsword( int, int ,string );
    private:
        /*
        int durability_;
        int maxDurability_;
        int weight_;
        int speedPen_;*/
        
};
#endif
