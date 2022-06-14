/*
 * player.h
 *
 *  Created on: 15-Sep-2021
 *      Author: sahil
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include<string>
class Player
{
public:
	Player();
	std::string name;// as string is also a part of namespace std
	int index;
	int runScored;
	int ballsPlayed;
	int ballsBowled;
	int runsGiven;
	int wicketsTaken;
};




#endif /* PLAYER_H_ */
