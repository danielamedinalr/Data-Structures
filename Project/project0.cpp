#include<iostream>

using namespace std;

int configoption()
{
    //Componente 1: configuracion del juego
    int option;
    string command;

    if (command == "help"){
        option = 0;
    }
    else if (command == "initialize")
    {
        option = 1;
    }
    else if (command == "turn")
    {
        option = 2;
    }
    else if (command == "exit")
    {
        option = 3;
    }
    else
    {
        cout << "invalid command, type help to get a list of available commands" << endl;
    }
}

int main()
{
    //int option;
    //string command;
    
}