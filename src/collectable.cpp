/**
* @File: collectable.cpp
* @Created By: Josiah Bubna
* @Created Date: 05/03/2009
*/

#include "../incl/collectable.h"

Collectable::Collectable() {
    type( blank );
}

itemType Collectable::type() const {
    return this->type_;
}

void Collectable::type( itemType newType ) {
    this->type_ = newType;
}
void Collectable::setValue( int newValue)
{
    this->value_ = newValue;
}
int Collectable::getValue()
{
    return this->value_;
}
void Collectable::setDescription(string dec)
{
    this->description_ = dec;
}
string Collectable::getDescription()
{
    return this->description_;
}
void Collectable::setName(string newName){
    this->name_ = newName;
}
