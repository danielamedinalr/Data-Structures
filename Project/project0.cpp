#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector <string> readinputs()
{
    string consoleinput, line;
    
    vector <string> commands;

    //sometimes getline misbehaves because of /n
    //so sometimes we have to use cin.ignore()
    
    do
    {
        getline(cin, consoleinput);
    } while (consoleinput.length() == 0);
    
    stringstream inputs(consoleinput);

    while(inputs >> line)
    {
        commands.push_back(line);
    }
    
    for(string &cmds: commands)
    {
        for (int q = 0; q < cmds.length(); q++)
        {
            cmds[q] = tolower(cmds[q]);
        }
    }

    return commands;
}

void printhelp(vector <vector <string> > &helpvecs, vector <string> &helpline)
{
    string option;
    if (helpline.size() == 1)
        {
            cout << endl << "available commands: " << endl << endl;
            for(int q = 0; q < helpvecs.size(); q++)
            {
                cout << helpvecs[q][0] << endl;
            }
            cout << endl << "type help -command to get a description of each command" << endl << endl;
        }
        else
        {
            option = helpline[1].substr(1);
            for (int q = 0; q < helpvecs.size(); q++)
            {
                if (helpvecs[q][0] == option)
                {
                    cout << endl << helpvecs[q][0] << ": " << helpvecs[q][1] << endl << endl;
                    return;
                }
            }
            cout << "command: " << option << " does not exist" << endl; 
        }
}

void helpsearch(vector <string> &helpline)
{
    string option;
    vector <vector <string> > confighelp;
    confighelp.push_back({"help", "Shows available commands and their descriptions, depending on the state of the program"});
    confighelp.push_back({"initialize", "Asks number of players, the name of each player, and asks which territories each player wants to occupy in their turn"});
    confighelp.push_back({"turn", "Tells the player available units to claim. Then asks which territory the player wants to assign them to, and in what numbers. Then asks attack configurations, from which territory, to which territory. Then rolls the dice and informs the units gained or lost to the player. Repeats the process until one of the territories runs out of units, or until the attacker decides to stop. Afterwards, the player is asked which surrounding territories should be fortified, as well as the units transported from one to the other."});
    confighelp.push_back({"clear", "Resets the screen of the terminal"});
    confighelp.push_back({"exit", "Ends the program"});

    vector <vector <string> > saveshelp;
    saveshelp.push_back({"help", "Shows available commands and their descriptions, depending on the state of the program"});
    saveshelp.push_back({"save", "Saves the state of the current game in an uncompressed text file"});
    saveshelp.push_back({"save_compressed", "Saves the state of the current game in a compressed binary file"});
    saveshelp.push_back({"initialize", "Initializes the game with the data from the specified file"});
    saveshelp.push_back({"clear", "Resets the screen of the terminal"});

    vector <vector <string> > strategyhelp;
    strategyhelp.push_back({"help", "Shows available commands and their descriptions, depending on the state of the program"});
    strategyhelp.push_back({"conquest_cost", "Calculates the cost and sequence of territories that must be conquered to control the territory specified. The attack starts at the territory controled by the current player that is closest to the specified territory"});
    strategyhelp.push_back({"cheapest_conquest", "Calculates which territory would result in the least number of units lost. The cost is calculated for the current player and their territories"});
    

    if (helpline.back() == "confighelp")
    {
        printhelp(confighelp, helpline);
    }
    else if (helpline.back() == "saveshelp")
    {
        printhelp(saveshelp, helpline);
    }
    else if (helpline.back() == "strategyhelp")
    {
        printhelp(strategyhelp, helpline);
    }
    
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
    /*
    //normal loops
    for (int q = 0; q < confighelp.size(); q++)
    {
        for (int w = 0; w < confighelp[q].size(); w++)
        {
            cout << confighelp[q][w] << " | ";
        }
        cout << endl << endl;
    }
    */

}

void gameconfig(bool &initstate, bool &endgame)
{
    //Componente 1: configuracion del juego
    bool validplayer = false, playerturn = false, endturn = false;
    vector <string> commands;
    
    do{
        commands = readinputs();
        
        if (commands[0] == "help"){
            commands.push_back("confighelp");
            helpsearch(commands);
        }
        else if (commands[0] == "initialize")
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
        else if (commands[0] == "turn")
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
        else if (commands[0] == "exit")
        {
            break;
        }
        else if (commands[0] == "clear")
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
    } while (commands[0] != "exit");
}

void gamesaves(bool &gameinit)
{
    //Componente 2
    bool savefine = false, readfine = false;
    vector <string> commands;

    do
    {
        commands = readinputs();

        if (commands[0] == "help")
        {
            commands.push_back("saveshelp");
            helpsearch(commands);
        }
        else if (commands[0] == "save")
        {
            if(gameinit == false)
            {
                cout << "game has not been initialized correctly" << endl;
            }
            else if (savefine == false)
            {
                cout << "save error, game has not been saved correctly" << endl;
            }
            else
            {
                cout << "game saved correctly" << endl;
            }
        }
        else if (commands[0] == "save_compressed")
        {
            if(gameinit == false)
            {
                cout << "game has not been initialized correctly" << endl;
            }
            else if (savefine == false)
            {
                cout << "save and compression error, game has not been saved nor compressed correctly" << endl;
            }
            else
            {
                cout << "game saved and compressed correctly" << endl;
            }
        }
        else if (commands[0] == "initialize")
        {
            if(readfine == false)
            {
                if(commands.size() <= 1)
                {
                    cout << "no file name specified" << endl;
                }
                else
                {
                    cout << commands[1] << " does not contain valid info to initialize the game" << endl;
                }
            }
            else
            {
                gameinit = true;
                cout << "game initialized from file correctly" << endl;
            }
        }
        else if (commands[0] == "clear")
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
    } while (commands[0] != "exit");
}

void gamestrategy(bool &gameinit, bool &endgame)
{
    //Componente 3
    vector <string> commands;

    do
    {
        commands = readinputs();
        
        if(commands[0] == "help")
        {
            commands.push_back("strategyhelp");
            helpsearch(commands);
        }
        else if (commands[0] == "conquest_cost")
        {
            if (gameinit == false)
            {
                cout << "game has not been initialized correctly" << endl;
            }
            else if (endgame == true)
            {
                cout << "game already has a winner" << endl;
            }
            else
            {
                cout << "to conquer territory "  << "x" << ", from territory "  << "y" << " through territories " << "z, e, d" << "player must use " << "10" << " army units" << endl;
            }
        }
        else if (commands[0] == "cheapest_conquest")
        {
            if (gameinit == false)
            {
                cout << "game has not been initialized correctly" << endl;
            }
            else if (endgame == true)
            {
                cout << "game already has a winner" << endl;
            }
            else
            {
                cout << "the cheapest conquest is conquering territory x from territory y, going through territories z e d, using up 10 army units" << endl;
            }
        }
    } while (commands[0] != "exit");
    
}

int main()
{
   bool gameinit = false, endgame = false;

   cout << "configuration options: " << endl;
   gameconfig(gameinit, endgame);

   cout << "save options: " << endl;
   gamesaves(gameinit);

   cout << "strategy options: " << endl;
   gamestrategy(gameinit, endgame);

   return 0; 
}