#include "game.h"
using namespace std;

Game::Game()
{

	playerPerTeam = 4;
	maxBall = 6;
	totalPlayers = 11;

	Players[0] = "Virat";
	Players[1] = "Rohit";
	Players[2] = "Dhawan";
	Players[3] = "Pant";
	Players[4] = "Karthik";
	Players[5] = "KLRahul";
	Players[6] = "Jadeja";
	Players[7] = "Hardik";
	Players[8] = "Bumrah";
	Players[9] = "BKumar";
	Players[10] = "Ishant";

	isFirstinning = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}
void Game::welcome()
{

	cout << "---------------------------------------" << endl;
	cout << "|============== CRIC-IN ==============|" << endl;
	cout << "|                                     |" << endl;
	cout << "|   Welcome to Virtual Cricket Game   |" << endl;
	cout << "---------------------------------------" << endl;

	cout << endl
		 << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "|================== Instructions ==================|" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "|                                                  |" << endl;
	cout << "| 1. Create 2 teams (Team-A and Team-B with 4      |" << endl;
	cout << "|    players each) from a given pool of 11 players.|" << endl;
	cout << "| 2. Lead the toss and decide the choice of play.  |" << endl;
	cout << "| 3. Each innings will be of 6 balls.              |" << endl;
	cout << "----------------------------------------------------" << endl;
}
void Game::showAllPlayers()
{

	cout << endl;
	cout << "---------------------------------------" << endl;
	cout << "|========== Pool of Players ==========|" << endl;
	cout << "---------------------------------------" << endl;
	cout << endl;

	for (int i = 0; i < totalPlayers; i++)
	{
		cout << "\t\t[" << i << "] " << Players[i] << endl;
	}
}
int Game::takeIntegerInput()
{

	int n;

	while (!(cin >> n))
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}
	return n;
}

bool Game::validateSelectedPlayer(int index)
{

	int n;
	vector<Player> players;

	players = teamA.Players;
	n = players.size();
	for (int i = 0; i < n; i++)
	{
		if (players[i].index == index)
		{
			return false;
		}
	}

	players = teamB.Players;
	n = players.size();
	for (int i = 0; i < n; i++)
	{
		if (players[i].index == index)
		{
			return false;
		}
	}
	return true;
}
void Game::selectPlayers()
{

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|========== Create Team-A and Team-B ==========|" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < playerPerTeam; i++)
	{

	// Add player to team A
	teamASelection:
		cout << endl
			 << "Select player " << i + 1 << " of Team A - ";
		int playerIndexTeamA = takeIntegerInput();

		if (playerIndexTeamA < 0 || playerIndexTeamA > 10)
		{
			cout << endl
				 << "Please select from the given players" << endl;
			goto teamASelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamA))
		{
			cout << endl
				 << "Player has been already selected. Please select other player" << endl;
			goto teamASelection;
		}
		else
		{
			Player teamAPlayer;
			teamAPlayer.index = playerIndexTeamA;
			teamAPlayer.name = Players[playerIndexTeamA];
			teamA.Players.push_back(teamAPlayer);
		}

	// Add player to team B
	teamBSelection:
		cout << endl
			 << "Select player " << i + 1 << " of Team B - ";
		int playerIndexTeamB = takeIntegerInput();

		if (playerIndexTeamB < 0 || playerIndexTeamB > 10)
		{
			cout << endl
				 << "Please select from the given players" << endl;
			goto teamBSelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamB))
		{
			cout << endl
				 << "Player has been already selected. Please select other player" << endl;
			goto teamBSelection;
		}
		else
		{
			Player teamBPlayer;
			teamBPlayer.name = Players[playerIndexTeamB];
			teamB.Players.push_back(teamBPlayer);
		}
	}
}

void Game::showTeamPlayers()
{

	vector<Player> teamAPlayers = teamA.Players;
	vector<Player> teamBPlayers = teamB.Players;

	cout << endl
		 << endl;
	cout << "--------------------------\t\t--------------------------" << endl;
	cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
	cout << "--------------------------\t\t--------------------------" << endl;

	for (int i = 0; i < playerPerTeam; i++)
	{
		cout << "|\t"
			 << "[" << i << "] " << teamAPlayers[i].name << "\t |"
			 << "\t\t"
			 << "|\t"
			 << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
	}
	cout << "--------------------------\t\t--------------------------" << endl
		 << endl;
}

void Game::toss()
{

	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "|========== Let's Toss  ==========|" << endl;
	cout << "-----------------------------------" << endl
		 << endl;

	cout << "Tossing the coin..." << endl
		 << endl;

	srand(time(NULL));
	int randomValue = rand() % 2; // 0 or 1

	switch (randomValue)
	{
	case 0:
		cout << "Team-A won the toss" << endl
			 << endl;
		tossChoice(teamA);
		break;
	case 1:
		cout << "Team-B won the toss" << endl
			 << endl;
		tossChoice(teamB);
		break;
	}
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game::startFirstInnings() {

	cout << "\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstinning = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->Players[0];
	bowler = &bowlingTeam->Players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}
void Game::playInnings() {

	for (int i = 0; i < maxBall; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bat();

	    if (!validateInningsScore()) {
	    	break;
	    }
	}
}
void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runScored = batsman->runScored + runsScored;
	battingTeam->totalRunScored = battingTeam->totalRunScored + runsScored;
	batsman->ballPlayed = batsman->ballPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballBowled = bowler->ballBowled + 1;
	bowlingTeam->totalBallBowled = bowlingTeam->totalBallBowled + 1;
	bowler->runGiven = bowler->runGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLoss = battingTeam->wicketsLoss + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLoss;
    	batsman = &battingTeam->Players[nextPlayerIndex];
    }
}

bool Game::validateInningsScore() {

	if (isFirstinning) {

		if (battingTeam->wicketsLoss == playerPerTeam || bowlingTeam->totalBallBowled == maxBall) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunScored << " - "
					<< battingTeam->wicketsLoss << " (" << bowlingTeam->totalBallBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}
    } else { // Else 2nd innings

    }

	return true;
}
void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunScored << " - "
      << battingTeam->wicketsLoss << " (" << bowlingTeam->totalBallBowled << ") | " << batsman->name
      << " " << batsman->runScored << " (" << batsman->ballPlayed << ") \t" << bowler->name << " "
	  << bowler->ballBowled << " - " << bowler->runGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}