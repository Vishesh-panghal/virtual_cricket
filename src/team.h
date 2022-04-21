#include <vector>
#include "player.h"
class Team
{
public:
    Team();
    std::string name;
    int totalRunScored;
    int wicketsLoss;
    int totalBallBowled;
    std::vector<Player> Players;
};