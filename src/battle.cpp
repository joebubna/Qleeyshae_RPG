// @file: battle.cpp
// @Created By: Kyle Jacobsen
// Created: 5-20-09
#include "../incl/battle.h"
Battle::Battle( Person * playerInit, Person * orcInit )
{
    player_ = playerInit;
    enemy_ = orcInit;
}

///////////////////////////////////////////
////////////I/O Functions//////////////////
///////////////////////////////////////////        
string Battle::streamOutput(){
    ss << ends;
    return ss.str();
    //output_.insert( 1 , s );   
}
string Battle::output()
{
    return output_;
}

string Battle::intString( int ){
    
}
        
int Battle::getChoice( char choice )
{
    int code;
    /*  
    Choice Codes:
        Attack code = 0;
        Defend = 2;
        Recover = 3;
        Chat = 87;
    */
    switch ( choice )
    {
        case 'a':
            code = 0;
            break;
        case 'A':
            code = 0;
            break;
        case 'd':
            code = 2;
            break;
        case 'D':
            code = 2;
            break;
        case 'r':
            code = 3;
            break;
        case 'R':
            code = 3;
            break;
        default:
            code = -1;
            break;
    }
    return code;
}
////////////////////////////////////
///////////Battle Step//////////////
////////////////////////////////////
int Battle::run( char choice )
{
    ss.str("");
    output_.clear();
    int result = 0;
    //Players turn
    if( getChoice( choice ) != -1 ){
        resetACBonus( player_ );
        takeTurn( player_ , enemy_ , getChoice( choice ) );
        
        // Checking for death..
        if( dead( enemy_ ) )
        {
            result = 1;
            ss << enemy_->name() << " has died.\n";
        }
        //////enemy_s Turn ONLY IF NEITHER PERSON IS DEAD ////////
        if( dead( enemy_ ) == false && dead( player_ ) == false )
        {
            resetACBonus( enemy_ );
            enemyAI();
        }
        // Check if player is dead after enemy turn
        if( dead( player_ ) )
        {
            ss << player_->name() << " has been slain.\n";
            result = 2;
        }
    } else {
        ss << player_->name() << " stares at" <<  enemy_->name() << ",\nwho stares back, the fury of battle within their eyes through this staring contest.\n" ;
    }
    output_ = streamOutput();
    return result;
    
}


void Battle::takeTurn( Person * attacker, Person * defender , int action )
{ 
    switch( action )
    {
        case 0:
            ss << attacker->name() << " attacks "<< defender->name();
            
            ss << " with a " << attacker->getWeaponEquipped()->getName();
            
            //////////////////////////////////////////////////////////////////////////
            // THIS LINE OF CODE ADDED BY JOE TO SHOW HOW TO ACCESS A PERSON'S WEAPONS
            //////////////////////////////////////////////////////////////////////////
            //ss << " with a weapon that has a DamageRoll of " 
            //<< attacker->getWeaponEquipped()->getDamageRoll();
            //////////////////////////////////////////////////////////////////////////
            // END OF EXAMPLE CODE BY JOE
            //////////////////////////////////////////////////////////////////////////
            
            attack( attacker , defender );
            if( action_ == "misses" ){
                ss << "\n and strikes nothing but the air.\n";
            } else if(action_ == "crit"){
                ss << "\n and lets out a cry to critically hit " << defender->name() << " for " << getRoundDamage() << " damage.\n";
                
            }else {
                ss << "\n for " << getRoundDamage() << " damage.\n";
            }
            break;
        case 2:
            defend( attacker );
            ss << attacker->name() << " readies his " << attacker->getWeaponEquipped()->getName() <<" for the impending strike.\n";
            break;
        case 3:
            recover( attacker );
            ss << attacker->name() << " increases his latent recovery rate to heal " << attacker->getMaxHP() * .10 << " HP.\n";
            break;
        default:
            break;
    }
} 
///////////////////////////////////////////////
/////////////////Commands//////////////////////
///////////////////////////////////////////////

void Battle::attack(Person* attacker, Person* defender)
{   
    int attRoll = toHit();
    //Crit testing
    //attRoll = 20;
    if( attRoll > defender->getAC() && attRoll < 20 )
    {
        roundDamage_ = getDamage( attacker );
        defender->setHP( defender->getHP() - roundDamage_ );
        action_ = "normal";
    }
    else if( attRoll == 20 )
    {
        roundDamage_ = getDamage( attacker ) * 2;
        defender->setHP( defender->getHP() - roundDamage_ );
        action_ = "crit"; //crit on natural 20
    } else {
        roundDamage_ = 0;   
        action_ = "misses";
    }
}

void Battle::defend( Person* character ){
    int charAC = character->getAC() / 2;
    character->setACBonus( charAC );
}

void Battle::recover( Person* character ){
    double heal = ( character->getMaxHP() * 0.1) + character->getHP();
    if(  character->getMaxHP() <= ( heal )){
        character->setHP( character->getMaxHP() );
    } else {
        character->setHP( (int)heal );   
    }
}
//////////////////////////////////////////////
//////////HouseKeeping functions//////////////
//////////////////////////////////////////////
int Battle::getRoundDamage()
{
    return roundDamage_;
}

bool Battle::dead( Person* character )
{
    bool isItDead = false;
    if( character->getHP() <= 0 )
    {
        isItDead = true;
    } 
    return isItDead;
}

int Battle::getDamage( Person* character)
{
    int dr = character->getWeaponEquipped()->getDamageRoll();
    int dm = character->getWeaponEquipped()->getDamageMod();
    int d = ( rand() % dr ) + dm;
    ////cout << "Damage Roll: " << d << endl;
    return d;
}

int Battle::toHit()
{
    int a = ( ( rand() % 20 ) + 1 );
    ////cout << "\nAttack roll: " << a << endl;
    return a; 
}
void Battle::resetACBonus( Person* character ){
    character->setACBonus( 0 );   
}

//////////////////////////////////////////////
////////////////Enemy AI//////////////////////
//////////////////////////////////////////////

void Battle::enemyAI()
{
    int act = enemyTurnChoice();
    takeTurn( enemy_ , player_ , act );
}

int Battle::enemyTurnChoice(){
    int command;
    int AI = ( rand() % 100 );
    if( AI >= 90 && enemy_->getHP() < enemy_->getMaxHP() * .5 ){
        //Recovers 10% health
        command = 3;
    } else if( AI >= 70 ){
        //Increases AC by 50%
        command = 2;
    }
    else if( AI >= 0 ){
        //Attacks
        command = 0;
    } 
    return command;
}
