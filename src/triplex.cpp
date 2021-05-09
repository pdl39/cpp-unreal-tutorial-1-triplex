#include <iostream>
#include <ctime>
#include "classes/Nums.h"

using namespace std;

bool PlayGame(int currentLevel);
Nums getUserGuesses();
bool checkResult(int NumSum, int NumProduct, int GuessSum, int GuessProduct);

int main() {
    int currentLevel = 1;
    const int maxLevel = 5;
    bool gameover = false;

    while (currentLevel <= maxLevel) {
        bool levelCompleted = PlayGame(currentLevel);
        cin.clear();   // clear all error flags. the failed input still remains on stream in buffer, so we must use cin.ignore as well.
        cin.ignore();  // discard stream in the buffer.

        if (levelCompleted)
            ++currentLevel;
        else {
            gameover = true;
            break;
        }
    }

    if (gameover) {
        cout << "GAME OVER\n\n";
        return 1;
    } else {
        cout << "You have become a master of Triple X.\n"
             << "ALL LEVELS CLEARED!\n";
        return 0;
    }
}

bool PlayGame(int currentLevel) {
    cout << "Let's Play Triple X!\n";
    cout << "Current Level: " << currentLevel << "\n\n";

    srand(time(NULL));

    const int Num1 = rand() % currentLevel + currentLevel;
    const int Num2 = rand() % currentLevel + currentLevel;
    const int Num3 = rand() % currentLevel + currentLevel;

    const int NumSum = Num1 + Num2 + Num3;
    const int NumProduct = Num1 * Num2 * Num3;

    int Life = 3;
    bool Result;
    do {
        cout << "You have " << Life << " lives\n\n";
        cout << "Enter 3 numbers greater than 0 that satisfy the following conditions: \n";
        cout << "- Sum of the 3 numbers = " << NumSum << "\n";
        cout << "- Product of the 3 numbers = " << NumProduct << "\n";

        Nums Guesses = getUserGuesses();
        const int GuessSum = Guesses.first();
        const int GuessProduct = Guesses.second();

        Result = checkResult(NumSum, NumProduct, GuessSum, GuessProduct);
        if (!Result) {
            --Life;
            cout << "Remaining Life: " << Life << "\n\n";
        }
        if (Life == 0) break;
    } while (!Result);

    if (Life == 0) {
        cout << "You are out of Life! T.T\n";
        return false;
    } else {
        return true;
    }
}

Nums getUserGuesses() {
    int Guess1, Guess2, Guess3;

    cin >> Guess1;
    cin >> Guess2;
    cin >> Guess3;

    cout << "\nYou entered: " << Guess1 << ", " << Guess2 << ", " << Guess3 << "\n\n";

    while (Guess1 == 0 || Guess3 == 0 || Guess3 == 0) {
        cout << "You must enter only numbers greater than 0.\n";
        cout << "Please try again.\n";
        cin.clear();
        cin.ignore(100, '\n');

        cin >> Guess1;
        cin >> Guess2;
        cin >> Guess3;
    }

    const int GuessSum = Guess1 + Guess2 + Guess3;
    const int GuessProduct = Guess1 * Guess2 * Guess3;

    const Nums Guesses{GuessSum, GuessProduct};

    return Guesses;
}

bool checkResult(int NumSum, int NumProduct, int GuessSum, int GuessProduct) {
    if (GuessSum == NumSum && GuessProduct == NumProduct) {
        cout << "\nLEVEL CLEARED!!!\n\n\n";
        cout << "Press Enter to Continue.\n\n\n";
        cin.clear();
        cin.ignore(100, '\n');
        return true;
    } else {
        cout << "\nFailed... Your guesses result in the following: \n";
        cout << "Sum = " << GuessSum << "\n";
        cout << "Product = " << GuessProduct << "\n\n";
        cout << "Please try again to acquire the following: \n";
        cout << "Sum = " << NumSum << "\n";
        cout << "Product = " << NumProduct << "\n\n\n";
        cout << "Press Enter to Continue.\n\n\n";
        cin.get();
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
}

bool Retry(Nums nums) {
    return true;
}