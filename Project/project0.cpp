#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

void confighelp()
{
    vector <vector <string> > confighelp;
    confighelp.push_back({"help", "shows available commands and their descriptions, depending on the state of the program"});
    confighelp.push_back({"initialize", "asks number of players, the name of each player, and asks which territories each player wants to occupy in their turn"});
    confighelp.push_back({"turn", "tells the player available units to claim. Then asks which territory the player wants to assign them to, and in what numbers. Then asks attack configurations, from which territory, to which territory. Then rolls the dice and informs the units gained or lost to the player. Repeats the process until one of the territories runs out of units, or until the attacker decides to stop. Afterwards, the player is asked which surrounding territories should be fortified, as well as the units transported from one to the other."});
    confighelp.push_back({"exit", "ends the program"});

    /*
    //range-based loops
    for (vector <string> &loopvec : helpvector)
    {
        // the "&" reference is not neccessary but if we didnt use it the for loop would copy the contents of the arrays, which is not efficient
        for (string &vecstring : loopvec)
        {
            cout << vecstring << " | ";
        }
        cout << endl;
    }
    */

    for (int q = 0; q < confighelp.size(); q++)
    {
        for (int w = 0; w < confighelp[q].size(); w++)
        {
            cout << confighelp[q][w] << " | ";
        }
        cout << endl;
    }
}

void configoption(string command)
{
    //Componente 1: configuracion del juego
    
    if (command == "help"){
        confighelp();
    }
    else if (command == "initialize")
    {
        
    }
    else if (command == "turn")
    {
        
    }
    else if (command == "exit")
    {
        
    }
    else if (command == "clear")
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    else
    {
        cout << "invalid command, type help to get a list of available commands" << endl;
    }
}



int main()
{
   bool gameinit = false;
   string command;

   cin >> command;
   configoption(command);
    
}