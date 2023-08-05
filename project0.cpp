#include<iostream>

using namespace std;

int main()
{
    int option;
    string command;

    if (command == "init"){
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