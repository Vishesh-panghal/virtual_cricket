#include <vector>
#include "player.h"
class Team
{
    Team();

public:
    std::string name;
    int totalRunScored;
    int wicketsLoss;
    int totalBallBowled;
    std::vector<Player> Players;
};