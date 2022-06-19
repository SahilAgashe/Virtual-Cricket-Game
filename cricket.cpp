//============================================================================
// Name        : virtual.cpp
// Author      :*      Author: SAHIL AMRUT AGASHE*  Created on: 15-Sep-2021
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

 

#include"game.h"
using namespace std;


int main()
{
setbuf(stdout,NULL);//FOR PROPER WORKING OF OUTPUT
Game game;
game.Start();
game.welcome();//welcome and instructions;

cout<<"Press enter to continue...\n";getchar();

game.playersList();
game.select_players();

cout<<"Press enter to continue...\n";getchar();

game.show_teams();
game.toss();

cout<<"Press enter to continue...\n";getchar();

game.startFirstInnings();
game.playInnings();
game.startSecondInnings();
game.playInnings_2nd();

cout<<"Press enter to continue...\n";getchar();

game.Final_scoreBoard();



	return 0;
}
