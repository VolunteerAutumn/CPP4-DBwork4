#include <iostream>
#include <windows.h>
using namespace std;

// PART I
// task 1
int main() {
    int sc = 0;
    char mode = 0, again = 0;
    int speed = 0;
    cout << "Hello!\n";
    while (true) {
        cout << "How long should the line be? >>> ";
        cin >> sc;
        cout << "And should it be (v)ertical or (h)orizontal? >>> ";
        cin >> mode;
        cout << "And choose the speed - (f)ast, (m)edium, (s)low >>> ";
        char spd;
        cin >> spd;
        if (spd == 'f') speed = 100;
        else if (spd == 'm') speed = 400;
        else if (spd == 's') speed = 700;
        else speed = 200;

        switch (mode) {
        case 'h':
            for (int i = 0; i < sc; i++) {
                cout << "_";
                Sleep(speed);
            }
            cout << endl;
            break;
        case 'v':
            for (int i = 0; i < sc; i++) {
                cout << "|" << endl;
                Sleep(speed);
            }
            break;
        default:
            cout << "Wrong choice!\n";
            break;
        }

        cout << "Should I do that again? (y/n) >>> ";
        cin >> again;
        if (again == 'n') {
            cout << "Bye bye!" << endl;
            return 0;
        }
    }
}

// task 2
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    char exitGame = 'y';

    while (exitGame == 'y' || exitGame == 'Y')
    {
        int compSum = 0, playerSum = 0;
        int randomNum;

        cout << "\nTHE ROUND... STARTS!!!\n";
        Sleep(1000);

        for (int i = 0; i < 3; i++)
        {
            system("cls"); // clear screen at start of each round

            // COMPUTER ROLL
            cout << "COMPUTER's turn...\nROLLING:" << endl;
            Sleep(400);
            randomNum = rand() % 6 + 1;

            switch (randomNum)
            {
            case 1:
                cout << R"( ╔═════════╗
 ║         ║
 ║    O    ║
 ║         ║
 ╚═════════╝)" << endl; compSum += 1; break;
            case 2:
                cout << R"( ╔═════════╗
 ║       O ║
 ║         ║
 ║ O       ║
 ╚═════════╝)" << endl; compSum += 2; break;
            case 3:
                cout << R"( ╔═════════╗
 ║       O ║
 ║    O    ║
 ║ O       ║
 ╚═════════╝)" << endl; compSum += 3; break;
            case 4:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║         ║
 ║ O     O ║
 ╚═════════╝)" << endl; compSum += 4; break;
            case 5:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║    O    ║
 ║ O     O ║
 ╚═════════╝)" << endl; compSum += 5; break;
            case 6:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║ O     O ║
 ║ O     O ║
 ╚═════════╝)" << endl; compSum += 6; break;
            }
            Sleep(1000);

            system("cls"); // clear before player roll

            // PLAYER ROLL
            cout << "PLAYER's turn...\nROLLING:" << endl;
            Sleep(400);
            randomNum = rand() % 6 + 1;

            switch (randomNum)
            {
            case 1:
                cout << R"( ╔═════════╗
 ║         ║
 ║    O    ║
 ║         ║
 ╚═════════╝)" << endl; playerSum += 1; break;
            case 2:
                cout << R"( ╔═════════╗
 ║       O ║
 ║         ║
 ║ O       ║
 ╚═════════╝)" << endl; playerSum += 2; break;
            case 3:
                cout << R"( ╔═════════╗
 ║       O ║
 ║    O    ║
 ║ O       ║
 ╚═════════╝)" << endl; playerSum += 3; break;
            case 4:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║         ║
 ║ O     O ║
 ╚═════════╝)" << endl; playerSum += 4; break;
            case 5:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║    O    ║
 ║ O     O ║
 ╚═════════╝)" << endl; playerSum += 5; break;
            case 6:
                cout << R"( ╔═════════╗
 ║ O     O ║
 ║ O     O ║
 ║ O     O ║
 ╚═════════╝)" << endl; playerSum += 6; break;
            }
            Sleep(1000);
        }

        system("cls"); // clear before showing total scores

        cout << "\nComputer's total score: " << compSum << endl;
        cout << "Player's total score: " << playerSum << endl;

        if (playerSum > compSum) cout << "PLAYER WINS!" << endl;
        else if (playerSum < compSum) cout << "COMPUTER WINS!" << endl;
        else cout << "IT'S A TIE!" << endl;

        cout << "\nDo you want to play again? (y/n) >>> ";
        cin >> exitGame;
    }

    cout << "BABAI!" << endl;
    return 0;
}
