
#include <iostream>
#include <cmath>
#include<string>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enum enGameChoices{ Stone = 1 , Paper = 2 , Scissors = 3 };

struct stRoundResault
{

    string Player;
    string Computer;
    string Winner;

};

struct stGameResault 
{

    int GameRounds = 0;
    int PlayerWonTimes = 0;
    int ComputerWonTimes = 0;
    int DrawTimes = 0 ;
    string FinalWinner;

};

short HowManyRounds(stGameResault &GameResault,short &NumOfRounds) 
{

    do {


        cout << "How Many Rounds 1 TO 10 ?   ";
        cin >> NumOfRounds;

    } while ( NumOfRounds < 1 || NumOfRounds > 10 );

    GameResault.GameRounds = NumOfRounds;

    return NumOfRounds;

}

enGameChoices PlayerChoice()
{

    int PLC = 0;

    do {

        cout << "Your Choice :  [1] STONE  -  [2] PAPER  -  [3] SCISSORS  ?   ";
        cin >> PLC;

    } while (PLC < 1 || PLC > 3);

    return enGameChoices(PLC);
    

}

void FillPlayerChoice(enGameChoices playerChoice, stRoundResault &PlayerResault)
{
   

    switch (playerChoice)
    {
    case enGameChoices::Stone:
        PlayerResault.Player = "Stone";
        break;

    case enGameChoices::Paper:
        PlayerResault.Player = "Paper";
        break;

    case enGameChoices::Scissors:
        PlayerResault.Player = "Scissors";
        break;


    default:
        break;
    }

}

enGameChoices ComputerChoice ()
{

    return enGameChoices(RandomNumber(1, 3));

}

void FillComputerChoice(enGameChoices ComputerrChoice, stRoundResault &ComputerResault)
{

    


    switch (ComputerrChoice)
    {
    case enGameChoices::Stone:
        ComputerResault.Computer = "Stone";
        break;

    case enGameChoices::Paper:
        ComputerResault.Computer = "Paper";
        break;

    case enGameChoices::Scissors:
        ComputerResault.Computer = "Scissors";
        break;


    default:
        break;
    }

}

bool PlayerWins(enGameChoices playerchoice, enGameChoices computerchoice)
{
    return

        (playerchoice == enGameChoices::Paper && computerchoice == enGameChoices::Stone) ||
        (playerchoice == enGameChoices::Scissors && computerchoice == enGameChoices::Paper) ||
        (playerchoice == enGameChoices::Stone && computerchoice == enGameChoices::Scissors);
}

bool ComputerWins(enGameChoices playerchoice, enGameChoices computerchoice)
{
    return
        (computerchoice == enGameChoices::Paper && playerchoice == enGameChoices::Stone) ||
        (computerchoice == enGameChoices::Scissors && playerchoice == enGameChoices::Paper) ||
        (computerchoice == enGameChoices::Stone && playerchoice== enGameChoices::Scissors);
}

bool Draw(enGameChoices Playerchoice, enGameChoices Computerchoice)
{

    return (Playerchoice == Computerchoice);

}

void WhoWin(enGameChoices Playechoice, enGameChoices Computerchoice, stRoundResault &GameResault,stGameResault &GameResaultt)
{
    
    if (PlayerWins(Playechoice, Computerchoice))
    {

        system("color 2F");
        GameResault.Winner = "[Player]";
        GameResaultt.PlayerWonTimes +=1;

    }
    else if (ComputerWins(Playechoice, Computerchoice)) {

        cout << "\a";
        system("color 4F");
        GameResault.Winner = "[Computer]";
        GameResaultt.ComputerWonTimes +=1;
       
    }
    else if(Draw(Playechoice, Computerchoice))
    {

        system("color 6F");
        GameResault.Winner = "[No Winner]";
        GameResaultt.DrawTimes +=1;

    }

}

void ShowRoundResault(stRoundResault RoundResault)
{
    cout << "Player Choice   : " << RoundResault.Player << "\n\n";
    cout << "Computer Choice : " << RoundResault.Computer << "\n\n";
    cout << "Round Winner    : " << RoundResault.Winner << "\n\n";

}

void FinalWinner(stGameResault &Gameresault)
{

    if ( Gameresault.PlayerWonTimes > Gameresault.ComputerWonTimes )
    {

        Gameresault.FinalWinner = " PLAYER ";

    }

    else if ( Gameresault.ComputerWonTimes > Gameresault.PlayerWonTimes )
    {

        Gameresault.FinalWinner = " COMPUTER ";

    }

    else
        Gameresault.FinalWinner = " NO WINNER ";

} 

void ShowGameResault(stGameResault GameResault)
{
    system("cls");
    cout << "\n\n";
    cout << "\t\t ______________________________________________________________\n\n";
    cout << "\t\t\t\t  + + + G A M E O V E R + + +\n\n";
    cout << "\t\t ______________________________________________________________\n\n";
    cout << "\t\t ______________________ { Game Resault } ______________________\n\n";
    cout << "\t\t Game Rounds              : " << GameResault.GameRounds << endl;
    cout << "\t\t Player Won Time(s)       : " << GameResault.PlayerWonTimes << endl;
    cout << "\t\t Computer Won Time(s)     : " << GameResault.ComputerWonTimes << endl;
    cout << "\t\t Draw Time(s)             : " << GameResault.DrawTimes << endl;
    cout << "\t\t Final Winner             : " << GameResault.FinalWinner << endl << endl;
    cout << "\t\t ______________________________________________________________\n\n";

}

void Tabs(short NumOfRounds, enGameChoices &Playerchoice, enGameChoices &Computerchoice, stRoundResault RoundResault,stGameResault GameResault)
{

    HowManyRounds(GameResault, NumOfRounds);

    for (int i = 1; i <= NumOfRounds; i++)
    {
      
        cout << "\nRound [" << i << "] Begins : \n\n";

       Playerchoice= PlayerChoice();
       Computerchoice= ComputerChoice();

        FillPlayerChoice(Playerchoice, RoundResault);
       FillComputerChoice(Computerchoice, RoundResault);

        WhoWin(Playerchoice, Computerchoice, RoundResault,GameResault);

        cout << "\n";
        cout << "_____________Round [" << i << "]________________\n\n";

        ShowRoundResault(RoundResault);

        cout << "\n____________________________________________\n\n";

    }


    FinalWinner(GameResault);
   

    ShowGameResault(GameResault);

}

void StartGame(short NumOfRounds, enGameChoices& Playerchoice, enGameChoices& Computerchoice, stRoundResault RoundResault, stGameResault GameResault)
{



}

int main()
{
    
    //Seeds the Random Number Generator in C++,Called Only Once in Main Function.
    srand((unsigned)time(NULL));

    stRoundResault RoundResault;
    stGameResault GameResault;
    enGameChoices PlayerChoices;
    enGameChoices ComputerChoices;
    short num = 0;

   Tabs(num, PlayerChoices, ComputerChoices,RoundResault, GameResault);
  
    return 0;
}