/*
 * game.h
 *
 *  Created on: 15-Sep-2021
 *      Author: sahil
 */

#ifndef GAME_H_
#define GAME_H_


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<limits>
#include"team.h"//vector,player.h
#include <iomanip>





class Game
{
public:
	Game();
	int playersPerTeam ;
	int maxBalls;
	int totalPlayers;
	std::string players[11];


	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam,*bowlingTeam ;
	Player *batsman,*bowler;


	void Start();
	void welcome();
	void playersList();
    int input_integer();
    void select_players();
    int  validate_players(int index);//returns 0 if false OR returns 1 if true
    void show_teams();
    void  toss();
    void tossChoice(Team toss_winner_team);
    void startFirstInnings();
    void initializePlayers();
    void  playInnings();
    void bat();
    int validate_inningsScore();
    void showGameScorecard();

    void startSecondInnings();
    void initializePlayers_2nd();
    void  playInnings_2nd();
    void bat_2nd();
    void showGameScorecard_2nd();
    void Final_scoreBoard();
};




#endif /* GAME_H_ */
