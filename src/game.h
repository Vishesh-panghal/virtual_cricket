#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"

class Game
{
public:
    Game();
    int playerPerTeam;
    int maxBall;
    int totalPlayers;
    std::string Players[11];
    bool isFirstinning;
    Team teamA, teamB;
    Team *battingTeam, *bowlingTeam;
    Player *batsman, *bowler;

    
    void welcome();
    void showAllPlayers();
    int takeIntegerInput();
    void selectPlayers();
    bool validateSelectedPlayer(int);
    void showTeamPlayers();
    void toss();
    void tossChoice(Team);
    void startFirstInnings();
    void initializePlayers();
    void playInnings();
    void bat();
    bool validateInningsScore();
    void showGameScorecard();
};