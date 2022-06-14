/*
 * game.cpp
 *
 *  Created on: 15-Sep-2021
 *      Author: sahil
 */

#include"game.h"
using namespace std;



Game::Game()
{

	 playersPerTeam = 4;
	 maxBalls = 6;
	 totalPlayers = 11;
	 players[0]="VIRAT ";
	 players[1]="ROHIT ";
	 players[2]="DHAWAN";
	 players[3]="PANT  ";
	 players[4]="KARTIK";
	 players[5]="RAHUL ";
	 players[6]="JADEJA";
	 players[7]="HARDIK";
	 players[8]="BUMRAH";
	 players[9]="BKUMAR";
    players[10]="ISHANT";





    isFirstInnings = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";

}



void Game::Start()
{
   cout<<"\t\t\t STARTING....\n\t\t   ";

 cout <<"...";
for(int r=1;r<=60;r++)
{
    string c = ">";


    for(int q=0;q<=10000000;q++);//to display the character slowly
    cout<< c;
}
cout <<"\n";


}
void Game::welcome()
{
cout<<"\n\n";
cout<<"  |********************************************************************************|\n";
cout<<"  |###################   WELCOME TO THE VIRTUAL CRICKET GAME   ####################|\n";
cout<<"  |********************************************************************************|\n";

cout<<"Press enter to continue...\n";getchar();
cout<<"\n\n";
cout<<"  #********************************************************************************#\n";
cout<<"  #                       GAME INSTRUCTIONS                                        #\n";
cout<<"  #              -> Create two teams each of 4 players.                            #\n";
cout<<"  #              -> Select players from given list of 11 players.                  #\n";
cout<<"  #              -> Lead the toss and decide the chice of play.                    #\n";
cout<<"  #              -> Each innings will be of 6 balls.                               #\n";
cout<<"  #********************************************************************************#\n";



}





void Game::playersList()
{
cout<<"\n\n";
cout<<"   #********************************************************************************#\n";
cout<<"   #                                  ||LIST OF PLAYERS||                           #\n";
cout<<"   #********************************************************************************#\n";

for(int i=0; i<11;i++)
{
    cout<<"\t\t\t\t"<<"["<<i<<"]"<<players[i]<<endl;
}

}

int Game::input_integer()
{
  int num;
while(!(cin>>num))
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "   oops!Invalid input!\n   Please enter the valid integer: ";


}
return num;

}






int   Game::validate_players(int index)
{
   int n,m;
   vector<Player>playersOFA;
   vector<Player>playersOFB;

   playersOFA = teamA.players;
   playersOFB = teamB.players;
   n = playersOFA.size() ;
   m = playersOFB.size() ;


   for(int i=0; i<n; i++)
   {
       if(playersOFA[i].index== index)
       {
           return 0;
       }

   }
      for(int i=0; i<m; i++)
   {
       if(playersOFB[i].index== index)
       {
           return 0;
       }

   }
   return 1;
}







void Game:: select_players()
{

cout<<"\n\n";
cout<<"  |********************************************************************************|\n";
cout<<"  |###################         Create Team A and Team B        ####################|\n";
cout<<"  |********************************************************************************|\n";


 cout<<endl<<"\t\tSELECT PLAYERS OF TEAM A";
for (int i=0; i<playersPerTeam; i++)//for team A
{

    teamASelection:
    cout<< endl<<" Select player " << i+1 << " of team A -";
    int playerIndexTeamA = input_integer();

    if(playerIndexTeamA > 10  || playerIndexTeamA <0)
    {
        cout<<endl<<"oops!Please select from the given players " <<endl;
        goto teamASelection;
    }
    else if(!(validate_players(playerIndexTeamA)))
    {
        cout<<"oops!Player is already selected";
         goto teamASelection;
    }
    else
    {
    Player teamAPlayer;
    teamAPlayer.index = playerIndexTeamA;
    teamAPlayer.name = players[playerIndexTeamA];
    teamA.players.push_back(teamAPlayer);
    }
}

 cout<<endl<<"\t\tSELECT PLAYERS OF TEAM B";
for (int i=0; i<playersPerTeam; i++)//FOR TEAM B
{

     teamBSelection:
    cout<< endl<<" Select player " << i+1 << " of team B -";
    int playerIndexTeamB = input_integer();
    if(playerIndexTeamB > 10  || playerIndexTeamB <0){
        cout<<endl<<"Please select from the given players " <<endl;
        goto teamBSelection;
    }
 else if(!(validate_players(playerIndexTeamB)))
    {
        cout<<"oops!Player is already selected";
         goto teamBSelection;
    }
    else
    {


    Player teamBPlayer;
    teamBPlayer.index = playerIndexTeamB;
    teamBPlayer.name = players[playerIndexTeamB];
    teamB.players.push_back(teamBPlayer);
    }
}


}







void Game::show_teams()
{

     cout<<"\n\n";
     cout<<"             ||YOUR SELECTED TEAMS||   \n\n";
     cout<<"   |############################################|"<<"\n";
     cout<<"   |   TEAM-A";cout<<"\t\t||\t    ";cout<<" TEAM-B\t|"<<"\n";
    for(int i=0; i<playersPerTeam; i++)
    {
     cout<<"   |   ";cout<< teamA.players[i].name ;
     cout<<"\t\t||\t     ";cout<<teamB.players[i].name;
     cout<<"\t|";cout<<"\n";

    }
     cout<<"   |############################################|";
}

void  Game::toss()
{
    cout<<"\n\n";
cout<<"  |********************************************************************************|\n";
cout<<"  |###################             ||TIME FOR TOSS||            ###################|\n";
cout<<"  |********************************************************************************|\n";

cout<<"\n\n\n\t\t\t..tossing the coin............\n\t\t\t   ";

 cout <<"!";
for(int r=1;r<=20;r++)
{
    string c = "#";


    for(int q=0;q<=100000000;q++);//to display the character slowly
    cout<< c;
}
cout <<"!\n";


srand (time(NULL));
int randomValue = rand() % 2;//that is 0 or 1;

switch(randomValue)
  {

case 0:
    cout<<"\n\tTeam A won the toss"<< endl ;
    tossChoice(teamA);
    break;

case 1:
    cout<<"\n\tTeam B won the toss"<< endl ;
     tossChoice(teamB);
    break;
  }
}
void Game::tossChoice(Team toss_winner_team)
{
    cout<<"\t\tEnter 1 to bat or 2 to bowl first.\n";
    cout<<"\n\t 1.Bat\n";
    cout<<"\n\t 2.Bowl\n";

    int toss_choice = input_integer();

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch(toss_choice)
    {
    case 1:
       cout<< endl<< toss_winner_team.name<<" won the toss and elected to bat first "<<endl;

       if(toss_winner_team.name.compare ("Team-A")== 0)
       {
           battingTeam = &teamA;
           bowlingTeam = &teamB;
       }
       else
       {
           battingTeam = &teamB;
           bowlingTeam = &teamA;
       }
        break;
    case 2:
       cout<< endl<< toss_winner_team.name<<" won the toss and elected to bowl first. "<<endl;

       if(toss_winner_team.name.compare ("Team-B")== 0)
       {
           battingTeam = &teamA;
           bowlingTeam = &teamB;
       }
       else
       {
           battingTeam = &teamB;
           bowlingTeam = &teamA;
       }

        break;
     default:

        break;
    }

}




//*******************first innings >>>>>>>>>>>>>>>>>>>
void Game:: startFirstInnings()
{
    cout<<"\t\t ||| FIRST INNINGS |||\n\n";
    isFirstInnings = true;

    initializePlayers();
}

void Game::initializePlayers()
{
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout<< battingTeam->name <<"-"<<batsman->name<<" is batting " <<endl;
    cout<< bowlingTeam->name <<"-"<<bowler->name<<" is bowling " <<endl;

}

void Game:: playInnings()
{
    batsman->runScored =0;
    battingTeam->totalRunScored=0;
    for(int i=0; i< maxBalls; i++)
    {
        cout<< "Press Enter to bowl....";
        getchar();
        cout<<"Bowling...\n";
        bat();
        if(!(validate_inningsScore()))
        {
            break;
        }
    }
}






void Game::bat()
{
    srand(time(NULL));
    int runsScored = rand()%7;// from 0 to 6

    batsman->runScored = batsman->runScored + runsScored;
    battingTeam->totalRunScored = battingTeam->totalRunScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    bowler->ballsBowled = bowler->ballsBowled +1;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled +1;
    bowler->runsGiven = bowler->runsGiven + runsScored;

    if(runsScored != 0)
    {
        cout<< endl<< bowler->name<<" to "<< batsman->name<< " " <<runsScored<<" runs!"<<endl<<endl;
   showGameScorecard();
    }
    else
    {
        cout<< endl<< bowler->name<<" to "<< batsman->name<< " OUT!"<<endl<<endl;

    battingTeam->wicketsLost = battingTeam->wicketsLost +1;
    bowler->wicketsTaken = bowler->wicketsTaken + 1;

     showGameScorecard();

    int nextPlayerIndex = battingTeam->wicketsLost;
    batsman = &battingTeam->players[nextPlayerIndex];
    }
}





int Game::validate_inningsScore()
{
    if(isFirstInnings)
    {
        if(battingTeam->wicketsLost == playersPerTeam  || bowlingTeam->totalBallsBowled == maxBalls )
        {
            cout<<"\t\t |||FIRST INNINGS ENDS ||| "<<endl<<endl;
            cout<<battingTeam->name<<" "<<battingTeam->totalRunScored<<"-" <<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;
            cout<< bowlingTeam->name<< " needs "<< battingTeam->totalRunScored +1 << " runs to win the match\n\n";

            return 0;
        }
    }
    else
    {
        if(bowlingTeam->wicketsLost == playersPerTeam  || battingTeam->totalBallsBowled == maxBalls )
        {
            cout<<"\t\t |||SECOND INNINGS ENDS ||| "<<endl<<endl;
            cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunScored<<"-" <<bowlingTeam->wicketsLost<<" ("<<battingTeam->totalBallsBowled<<")"<<endl;
            if( bowlingTeam->totalRunScored >=  (battingTeam->totalRunScored +1) )
            {
                cout<<bowlingTeam->name<<"  WON THE MATCH " ;
            }
            else if( bowlingTeam->totalRunScored ==  (battingTeam->totalRunScored ))
            {
                cout<<" MATCH ENDED IN DRAW";
            }
            else{
                 cout<<battingTeam->name<<"  WON THE MATCH " ;
            }
             cout<<"\n\t\t |||  MATCH FINISHED! ||| "<<endl<<endl;

            return 0;
        }           //2nd innings
    }
        return 1;

}






void Game::showGameScorecard()
{
    cout<<"#################################################################"<<endl;

    cout<<"\t"<<battingTeam->name<<" "<<battingTeam->totalRunScored<<"-"
    <<battingTeam->wicketsLost<<"("<<bowlingTeam->totalBallsBowled<<") |"<< batsman->name<<" "<<batsman->runScored<<"("<<batsman->ballsPlayed<<") \t"<<bowler->name<<" "
    << bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<<bowler->wicketsTaken<<"\t"<<endl;
    cout<<"#################################################################"<<endl<<endl;

}






//*************************************************************************************************
//now for second innings >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

void Game:: startSecondInnings()
{
    cout<<"\t\t ||| SECOND INNINGS |||\n\n";
    isFirstInnings = false;

    initializePlayers_2nd();
}




void Game::initializePlayers_2nd()
{
    //now here ,in 2nd inning's batting team == 1st inning's bowling team
    bowler = &battingTeam->players[0];
    batsman = &bowlingTeam->players[0];

    cout<< bowlingTeam->name <<"-"<<batsman->name<<" is batting " <<endl;
    cout<< battingTeam->name <<"-"<<bowler->name<<" is bowling " <<endl;

}






void Game:: playInnings_2nd()
{
    batsman->runScored =0;
    bowlingTeam->totalRunScored=0;
    for(int i=0; i< maxBalls; i++)
    {
        cout<< "Press Enter to bowl....";
        getchar();
        cout<<"Bowling...\n";
        bat_2nd();
        if(!(validate_inningsScore()))
        {
            break;
        }
    }
}






void Game::bat_2nd()
{
    srand(time(NULL));
    int runsScored = rand()%7;// from 0 to 6

    batsman->runScored = batsman->runScored + runsScored;
    bowlingTeam->totalRunScored = bowlingTeam->totalRunScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    bowler->ballsBowled = bowler->ballsBowled +1;
    battingTeam->totalBallsBowled = battingTeam->totalBallsBowled +1;
    bowler->runsGiven = bowler->runsGiven + runsScored;

    if(runsScored != 0)
    {
        cout<< endl<< bowler->name<<" to "<< batsman->name<< " " <<runsScored<<" runs!"<<endl<<endl;
   showGameScorecard_2nd();
    }
    else
    {
        cout<< endl<< bowler->name<<" to "<< batsman->name<< " OUT!"<<endl<<endl;

 bowlingTeam->wicketsLost = bowlingTeam->wicketsLost +1;
    bowler->wicketsTaken = bowler->wicketsTaken + 1;

     showGameScorecard_2nd();

    int nextPlayerIndex = bowlingTeam->wicketsLost;
    batsman = &bowlingTeam->players[nextPlayerIndex];
    }
}






void Game::showGameScorecard_2nd()
{
    cout<<"#################################################################"<<endl;

    cout<<"\t"<<bowlingTeam->name<<" "<<bowlingTeam->totalRunScored<<"-"
    <<bowlingTeam->wicketsLost<<"("<<battingTeam->totalBallsBowled<<") |"<< batsman->name<<" "<<batsman->runScored<<"("<<batsman->ballsPlayed<<") \t"<<bowler->name<<" "
    << bowler->ballsBowled<<"-"<<bowler->runsGiven<<"-"<<bowler->wicketsTaken<<"\t"<<endl;
    cout<<"#################################################################"<<endl<<endl;

}




//**********************************final ScoreBoard

void Game::Final_scoreBoard()
{
     const char separator    = ' ';


    cout<<battingTeam->name<<" "<<battingTeam->totalRunScored<<"-" <<battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<")"<<endl;
    cout<<"==============================================================================="<<endl;

    cout << left << setw(36) << setfill(separator) << "PLAYERS";
    cout << left << setw(36) << setfill(separator) << "BATTING";
    cout << left << setw(36) << setfill(separator) << "BOWLING"<<endl;
     for(int i=0; i<playersPerTeam; i++)
     {
    cout<<"|-----------------------------------------------------------------------------|"<<endl;

    cout << left << setw(1) << setfill(separator) << "[";
    cout << left << setw(1) << setfill(separator) << i;
    cout << left << setw(1) << setfill(separator) << "]";
    cout << left << setw(27+6) << setfill(separator) << battingTeam->players[i].name;
    cout << left << setw(2) << setfill(separator) << battingTeam->players[i].runScored;
    cout << left << setw(1) << setfill(separator) <<"(";
    cout << left << setw(1) << setfill(separator) << battingTeam->players[i]. ballsPlayed;
    cout << left << setw(26+6) << setfill(separator) << ")";
    cout << left << setw(1) << setfill(separator) << battingTeam->players[i].ballsBowled;
    cout << left << setw(1) << setfill(separator) <<"-";
    cout << left << setw(2) << setfill(separator) << battingTeam->players[i].runsGiven;
    cout << left << setw(1) << setfill(separator) <<"-";
    cout << left << setw(25+6) << setfill(separator) << battingTeam->players[i].wicketsTaken;
    cout<<"\n";

     }

    cout<<"==============================================================================="<<"\n\n\n\n";


    cout<<bowlingTeam->name<<" "<<bowlingTeam->totalRunScored<<"-" <<bowlingTeam->wicketsLost<<" ("<<battingTeam->totalBallsBowled<<")"<<endl;
    cout<<"==============================================================================="<<endl;

    cout << left << setw(36) << setfill(separator) << "PLAYERS";
    cout << left << setw(36) << setfill(separator) << "BATTING";
    cout << left << setw(36) << setfill(separator) << "BOWLING"<<endl;
     for(int i=0; i<playersPerTeam; i++)
     {
    cout<<"|-----------------------------------------------------------------------------|"<<endl;

    cout << left << setw(1) << setfill(separator) << "[";
    cout << left << setw(1) << setfill(separator) << i;
    cout << left << setw(1) << setfill(separator) << "]";
    cout << left << setw(27+6) << setfill(separator) << bowlingTeam->players[i].name;
    cout << left << setw(2) << setfill(separator) << bowlingTeam->players[i].runScored;
    cout << left << setw(1) << setfill(separator) <<"(";
    cout << left << setw(1) << setfill(separator) << bowlingTeam->players[i]. ballsPlayed;
    cout << left << setw(26+6) << setfill(separator) << ")";
    cout << left << setw(1) << setfill(separator) << bowlingTeam->players[i].ballsBowled;
    cout << left << setw(1) << setfill(separator) <<"-";
    cout << left << setw(2) << setfill(separator) << bowlingTeam->players[i].runsGiven;
    cout << left << setw(1) << setfill(separator) <<"-";
    cout << left << setw(25+6) << setfill(separator) << bowlingTeam->players[i].wicketsTaken;
    cout<<"\n";

     }


      cout<<"==============================================================================="<<"\n";
}


