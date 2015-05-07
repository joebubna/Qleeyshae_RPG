/**
* @File: Person.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/person.h"

Person::Person() {
    setInventoryPos(0);  
    setWeaponEquipped( -1 );
    setArmorEquipped( -1 );
    //cWeapon_ = -1;
    //cArmor_ = -1;
}

void Person::setX( int newX ) {
    this->cX_ = newX;
}

void Person::setY( int newY ) {
    this->cY_ = newY;
}

void Person::setLastX( int newX ) {
    this->lastX_ = newX;
}

void Person::setLastY( int newY ) {
    this->lastY_ = newY;
}

void Person::name( string newName ) {
    this->name_ = newName;
}

void Person::setClassName( string newClassName ) {
    this->className_ = newClassName;
}

void Person::setRelateCode( int newCode ) {
    this->relateCode_ = newCode;
}

void Person::setIsEnemy( bool newStatus ) {
    this->isEnemy_ = newStatus;
}

void Person::setLevel( int newLevel ) {
    this->level_ = newLevel;
}

void Person::setHP( int newHp ) {
    this->HP_ = newHp;
}

void Person::setMaxHP( int newMaxHP ) {
    this->maxHP_ = newMaxHP;
}

void Person::setEXP( int newExp ) {
    this->exp_ = newExp;
}

void Person::setAC ( int newAC ) {
    this->AC_ = newAC;
}

void Person::setACBonus ( int newACBonus ) {
    this->ACBonus_ = newACBonus;
}

void Person::setGP ( int newGP ) {
    this->GP_ = newGP;
}

void Person::setExpValue( int newExpValue ) {
    this->expValue_ = newExpValue;
}

void Person::setChatLine( string newChatLine ) {
    this->chatLine_ = newChatLine;
}

void Person::setDescription( string newDescription ) {
    this->description_ = newDescription;
}

void Person::itemAdd( Collectable* newItem) {
    this->inventory_.push_back( newItem );
    
    /*
    bool exit = false;
    for (int i=0; i < inventory_.size() && exit == false; i++) {
        if (!this->inventory_[i]) { // If this slot is empty
            this->inventory_[i] = newItem; // add the person.
            exit = true;
        }
    }
    
    if (exit == false) {
        // if there was no room to put the person in from the loop above,
        // then add a new slot with them in it.
        this->inventory_.push_back( newItem );
    }
    */
}

void Person::itemRemove( Collectable* theItem ) {
    for (int i=0; i < inventory_.size(); i++) {
        if (this->inventory_[i] == theItem) {
            this->inventory_[i] = NULL;
        }
    }
}
void Person::removeEmptySlots() {
    if(inventory_.size() > 1)
    {
        for (int i=0; i < inventory_.size(); i ++) {
            if (this->inventory_[i] == NULL) {
                this->inventory_.erase(inventory_.begin() + i);
            }
        }
    }
}
void Person::repositionCursur() {
    while( itemGet(getInventoryPos()) == NULL)
    {
        if(getInventoryPos() > 0) { 
            setInventoryPos(getInventoryPos() - 1);
        }else
        { break; }
    }
}

Collectable* Person::itemGet( int idx ) const {
    return this->inventory_[idx];
}

vector <Collectable*> Person::itemList() const {
    return this->inventory_;
}
int Person::getItemAmount() const{
    return inventory_.size();
}
int Person::getInventoryPos()
{
    return inventoryPos_;
}
void Person::setInventoryPos(int pos)
{
    inventoryPos_ = pos;
}

Collectable* Person::getWeaponEquipped() const {
    if (cWeapon_ < 0 || cWeapon_ > 9) {
        Collectable *aFist = new Fist;
        return aFist;
    }
    else {
        return this->inventory_[cWeapon_];
    }
}

void Person::setWeaponEquipped( int idx ) {
    cWeapon_ = idx;
}

Collectable* Person::getArmorEquipped() const {
    if (cArmor_ < 0 || cArmor_ > 9) {
        Collectable *aSkin = new Skin;
        return aSkin;
    }
    else {
        return this->inventory_[cArmor_];
    }
}

void  Person::setArmorEquipped( int idx ) {
    cArmor_ = idx;
}
