#include "game.h"


Game::Game() {

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