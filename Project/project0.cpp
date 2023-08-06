#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

void confighelp()
{
    vector <vector <string> > confighelp;
    confighelp.push_back({"help", "shows available commands and their descriptions, depending on the state of the program"});
    confighelp.push_back({"initialize", "asks number of players, the name of each player, and asks which territories each player wants to occupy in their turn"});
    confighelp.push_back({"turn", "tells the player available units to claim. Then asks which territory the player wants to assign them to, and in what numbers. Then asks attack configurations, from which territory, to which territory. Then rolls the dice and informs the units gained or lost to the player. Repeats the process until one of the territories runs out of units, or until the attacker decides to stop. Afterwards, the player is asked which surrounding territories should be fortified, as well as the units transported from one to the other."});
    confighelp.push_back({"clear", "resets the screen of the terminal"});
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
        cout << endl << endl;
    }
}

void gameconfig(bool &initstate)
{
    //Componente 1: configuracion del juego
    bool endgame = false, validplayer = false, playerturn = false, endturn = false;
    string command;
    
    do{
        cin >> command;
        for(int q = 0; q < command.length(); q++)
        {
            command[q] = tolower(command[q]); 
        }

        if (command == "help"){
            confighelp();
        }
        else if (command == "initialize")
        {
            if(initstate == true)
            {
                cout << "game has already been initialized" << endl;
            }
            else if (initstate == false)
            {
                initstate = true;
                cout << "game initialized succesfully" << endl;
            }
        }
        else if (command == "turn")
        {
            if (initstate == false)
            {
                cout << "game has not been initialized correctly" << endl;
            }
            else if (endgame == true)
            {
                cout << "game already has a winner" << endl;
            }
            else if (validplayer == false)
            {
                cout << "player is not in the game" << endl;
            }
            else if (playerturn == false)
            {
                cout << "different player has the turn" << endl;
            }
            else if (endturn == true)
            {
                cout << "turn of current player has ended" << endl;
            }
        }
        else if (command == "exit")
        {
            break;
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
    } while (command != "exit");
}

int main()
{
   bool gameinit = false;
   
   gameconfig(gameinit);
    
}