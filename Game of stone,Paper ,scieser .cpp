#include <iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;

enum enGameChoice { Paper = 1, Stone = 2, Scissor = 3 };
enum enWinner { Player1 = 1, Computer = 2,Draw=3 };
struct stRoundInfo {
    short NumberRound;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string NameWinner;
};
struct stGameResults {
    short NumberRound = 0;
    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner WinnerGame;
    string GameWinnerName = "";
};
short HowRounds() {
    short round;
    do {
        cout << " How Many Round You Want  ?";
        cin >> round;
    } while (round < 1 || round>10);
    return round;
}
enGameChoice PlayerChoice() {
    short Choice;
    do {
        cout << "Choose  [1]:Paper  ,[2]:Stone  ,[3]:Scissors  ?";
        cin>> Choice;
    } while (Choice < 1 || Choice >3);

    return (enGameChoice)Choice;
}

short RandomChoiceComputer(short From, short To) {
    short Number = rand() % (To - From + 1) + From;
    return Number;
}
enGameChoice GetComputerChoice() {
    return (enGameChoice)RandomChoiceComputer(1, 3);
}
enWinner RoundWinner(stRoundInfo Winner) {
    if (Winner.Player1Choice == Winner.ComputerChoice) {
        return enWinner::Draw;
    }
    switch (Winner.Player1Choice) {
    case enGameChoice::Paper:
        if (Winner.ComputerChoice == enGameChoice::Scissor) {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Scissor:
        if (Winner.ComputerChoice == enGameChoice::Stone) {
            return enWinner::Computer;
        }
        break;
    case enGameChoice::Stone:
        if (Winner.ComputerChoice == enGameChoice::Paper) {
            return enWinner::Computer;
        }
        break;

    }
    return enWinner::Player1;
}

string WHoRoundWinner(enWinner Winnername) {
    string arrWinnerName[3] = { "Player1","Computer","No Winner" };
    return arrWinnerName[Winnername - 1];
}
string NameChoice(enGameChoice NameChoice) {
    string arrNameChoice[3] = { "Paper","Stone","Scissors" };
    return arrNameChoice[NameChoice - 1];
}
void PrintRoundResults(stRoundInfo Results) {
    cout << "\n\n_____________________Round [" << Results.NumberRound<<"]____________________" << endl;
    cout << "Player Choice             :" << NameChoice(Results.Player1Choice) << endl;
    cout << "Computer Choice           :" << NameChoice(Results.ComputerChoice) << endl;
    cout << "Name Winner               :" << Results.NameWinner << endl;
    cout << "_____________________________________________________\n\n";

}enWinner GameWinner(stGameResults GameWinner) {
    if (GameWinner.PlayerWinTimes > GameWinner.ComputerWinTimes)
        return enWinner::Player1;
    else if (GameWinner.ComputerWinTimes > GameWinner.PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}
string GameWinnerName(enWinner WinnerFinal ) {
    string arrFinalGameWinner[3] = { "Player1","Computer","Draw " };
    return arrFinalGameWinner[WinnerFinal - 1];
}
void SetColorForHowWins(enWinner ColorWinner) {
    switch (ColorWinner) {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    case enWinner::Draw:
        system("color 6F");
    }
}
stGameResults FinalGameResults(short HRounds,short PlayerWinTimes,short ComputerWinTimes,short DrawTimes) {
    stGameResults Game_Results;
    Game_Results.NumberRound = HRounds;
    Game_Results.PlayerWinTimes = PlayerWinTimes;
    Game_Results.ComputerWinTimes = ComputerWinTimes;
    Game_Results.DrawTimes = DrawTimes;
    Game_Results.WinnerGame = GameWinner(Game_Results);
    Game_Results.GameWinnerName = GameWinnerName(Game_Results.WinnerGame);

    SetColorForHowWins(Game_Results.WinnerGame);
    return Game_Results;
}
stGameResults StartGame(short HowRounds) {
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes=0;
    for (int GameRound = 1; GameRound <= HowRounds; GameRound++) {
        cout << "Round    [" << GameRound << "]  begins ....\n";
        RoundInfo.NumberRound = GameRound;
        RoundInfo.Player1Choice = PlayerChoice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = RoundWinner(RoundInfo);
        RoundInfo.NameWinner = WHoRoundWinner(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
            PlayerWinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FinalGameResults(HowRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}
string Tabs(short HowTabs) {
    string T;
    for (int q = 1; q <= HowTabs; q++) {
        T = T + "\t";
        cout << T;
    }
    return T;
}
void ShowFinalGameResults(stGameResults allResults) {
    cout << Tabs(2) << "Rounds [" << allResults.NumberRound << "] " << endl;
    cout << Tabs(2) << "Player1 Won Times          :" << allResults.PlayerWinTimes << endl;
    cout << Tabs(2) << "Computer won Times         :" << allResults.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times                 :" << allResults.DrawTimes << endl;
    cout << Tabs(2) << "Game Winner                :" << allResults.GameWinnerName << endl;


}

void ShowGameOverScreen() {
    cout << Tabs(2) << "__________________________________________________\n";
    cout << Tabs(2) << "            +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "__________________________________________________\n";
}
void PlayGame() {
    char Playagain = 'Y';
    do {
        stGameResults GameResults = StartGame(HowRounds());
        ShowGameOverScreen();
        ShowFinalGameResults(GameResults);


        cout << "\n\nDo You Want to play again  ?";
        cin >> Playagain;
    } while (Playagain == 'y' || Playagain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    PlayGame();


    system("pause");
    return 0;
}













