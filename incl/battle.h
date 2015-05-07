// @file: battle.h
// @Created By: Kyle Jacobsen
// Created: 5-20-09
#include "Person.h"
#include <string>
#include <sstream>
#include <time.h>

class Battle{
    public:
        Battle( Person*, Person* );
        /////////////////
        //I/O Functions//
        /////////////////
        //void input( int i );
        string output();
        string streamOutput();
        string intString( int );
        int getChoice( char );
        
        //////////////////////////
        //HouseKeeping functions//
        //////////////////////////
        int toHit();
        int getDamage( Person* );
        int getRoundDamage();
        bool dead( Person* );
        void resetACBonus( Person* );
        ////////////
        //Commands//
        ////////////
        void attack( Person*, Person*);
        void defend( Person* );
        void recover( Person* );
        ///////////////////////////////////
        //Increase the battle by one step//
        ///////////////////////////////////
        int run( char choice );
        void takeTurn( Person* , Person* , int );
        ////////////
        //Enemy AI//
        ////////////
        void enemyAI();
        int enemyTurnChoice();
        
    private:    
        Person* player_;
        Person* enemy_;
        string output_;
        stringstream ss;
        string action_;
        int roundDamage_;
};

