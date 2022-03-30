#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include"team.h"


class Game
{
    public:
    Game();
    int playerPerTeam;
    int maxBall;
    int totalPlayers;
    std::string Players[11];
    bool isFirstinning;
    Team teamA,teamB;
    Team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;
};