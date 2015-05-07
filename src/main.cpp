#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <istream>
#include <vector>
#include <string>
#include "../incl/game.h"
#include "../incl/view.h"

using namespace std;

int main(int argc, char *argv[])
{
    Game myGame;
    myGame.run();
    cout << endl;
    
    
     /*   The ascii  table  of all chars
    char c =0;
    int cc = 0;
    for(int i = 0; i < 256; i ++)
    {
        c = i;
        if ( c != 7)
        {
            cout  << i << ":" << c << "   ";
        }
        cc++;
        if(cc > 6)
        {
            cout << endl;
            cc =0;
        }

        //system("pause");
    }
    */

    system("PAUSE");
    return EXIT_SUCCESS;
}
