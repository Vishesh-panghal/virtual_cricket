/*
_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-_
Name = Virtual Cricket game
Author = Vishesh Panghal
version = 0.001
Copyright = Author
Description = Cricket game in C++, Ansi style
_-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-__-_-_-_-_-_-_
*/

#include "game.h"
using namespace std;

int main()
{
    Game Game;
    Game.welcome();

    cout << "Press Entre key to continue" << endl;
    getchar();

    Game.showAllPlayers();
    Game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPress Enter to toss";
    getchar();

    Game.toss();
    Game.startFirstInnings();

    return 0;
}