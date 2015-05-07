/**
* @File: person.h
* @Created By: Josiah Bubna
* @Created Date: 05/01/2009
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
//#include "map.h"
#include "collectable.h"
#include "weapon.h"
#include "weaponh/fist.h"
#include "armor.h"
#include "armorh/skin.h"


using namespace std;

class Map;

class Person
{
    public: 
        Person();
        
        // General Inspectors
        string name() const { return name_; };  
        int getRelateCode() const { return relateCode_; };
        bool getIsEnemy() const { return isEnemy_; };         
        int getX() const { return cX_; };
        int getY() const { return cY_; }; 
        int getLastX() const { return lastX_; };
        int getLastY() const { return lastY_; };
        int getLevel() const { return level_; };
        int getHP() const { return HP_; };
        int getMaxHP() const { return maxHP_; };
        int getEXP() const { return exp_; };
        int getMaxEXP() const { return level_ * 1000; };
        int getAC() const { return AC_; };
        int getACBonus() const { return ACBonus_; };
        int getExpValue() const { return expValue_; };
        int getGP() const { return GP_; };
    
        string getClassName() const { return className_; };
        string getChatLine() const { return chatLine_; };
        string getDescription() const { return description_; };
        
        // General Setters
        void setX( int newX );
        void setY( int newY );
        void setLastX( int newX );
        void setLastY( int newY );
        void name( string newName ); 
        void setClassName( string );
        void setRelateCode( int );
        void setIsEnemy( bool );         
        void setLevel( int );
        void setHP( int );
        void setMaxHP( int );
        void setEXP( int );
        void setAC ( int );
        void setACBonus ( int );
        void setGP ( int );        
        void setExpValue( int );
        void setChatLine( string );    
        void setDescription( string );
        
        /*
        void setWeapon( Weapon* );
        void setArmor( Armor* );
        void setAugment( Augment* );
        void setTreasure( Treasure* );
        */
        
        // Inventory related
        void itemAdd( Collectable* );
        void itemRemove( Collectable* );
        void removeEmptySlots();
        void repositionCursur();
        int getItemAmount() const; // returns iem vector size
        int getInventoryPos(); // inventory curose position
        void setInventoryPos(int pos);
        Collectable* itemGet( int idx ) const; // returns a single item.
        vector <Collectable*> itemList() const; // returns all the items.
        
        // Active inventory
        Collectable* getWeaponEquipped() const; // Inspector, returns pointer to currently equiped weapon.
        void  setWeaponEquipped( int idx ); // Setter, equips a weapon.
        Collectable* getArmorEquipped() const;
        void  setArmorEquipped( int idx );
        
        
    private:
        /////////////////////////////////////////
        // Data Members
        /////////////////////////////////////////
        string name_; // This person's name.
        string className_; // This person's class name
        int relateCode_; // 1 = Human/elf/dwarf, 0 = Non-human/orc/goblin
        bool isEnemy_; // Is explicitly an enemy?       
        int cX_; // Player's current X position.
        int cY_; // Player's current Y position.
        int GP_; // The person's Money.
        int level_; // The person's Character Level
        int HP_; // The person's current health.
        int maxHP_; // The person's maximum health if fully healed.
        int exp_; // The person's current experience points.
        int AC_;
        int ACBonus_;
        int expValue_; // The person's experience value if killed.       
        string chatLine_; // What this person says if spoken with.
        string description_; // A description shown in the game when enountering this person.
        int lastX_;
        int lastY_;
        
        // A vector of pointers to Collectables (aka. this person's inventory)
        vector <Collectable*> inventory_;       
        int inventoryPos_; // inventory cursur position 0 - 9 normaly
        int cWeapon_; // The person's currently equiped weapon.
        int cArmor_; // The person's currently equiped armor.
        
        // This is in Game Class so if we let you switch characters the quest log
        // is more global and not linked to any single person.
        // Questlog Journal;
        
        //will need mutators and setters for each IN FUTURE
        /*
        int MP_;
        int attack_;
        int strength_;
        int dexterity_;
        int constitution_;
        int intelligence_; 
        int wisdom_;
        int charisma_;
        */
};
#endif
