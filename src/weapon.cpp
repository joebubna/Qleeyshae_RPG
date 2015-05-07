/**
* @File: Weapon.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/weapon.h"

Weapon::Weapon() {
    type( weapon );
}

/*void Weapon::weapon( weaponType newType ) {
    this->type_ = newType;
}*/
void Weapon::setDamageMod( int i){
    damageMod_ = i;
}
void Weapon::setDamageRoll(int i){
    damageRoll_ = i;
}
/*void Weapon::setName(string s){
    name_ = s;
}*/
