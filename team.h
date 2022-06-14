/*
 * team.h
 *
 *  Created on: 15-Sep-2021
 *      Author: sahil
 */

#ifndef TEAM_H_
#define TEAM_H_
#include<vector>
#include"player.h"
class Team
{
public:
	std::string name;
	int totalRunScored;
	int wicketsLost;
	int totalBallsBowled;
	std::vector<Player>players; // for vector also namespace std used

};




#endif /* TEAM_H_ */
