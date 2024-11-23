#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "Guess the number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (abs(userGuess - randomNumber) < 10 && userGuess != randomNumber) {
            cout << "You're getting close! Keep trying." << endl;
        } 
        else if (userGuess < randomNumber - 10) {
            cout << "Too low! Try again." << endl;
        } 
        else if (userGuess > randomNumber + 10) {
            cout << "Too high! Try again." << endl;
        } 
        else {
            cout << "Correct! The number was " << randomNumber << "." << endl;
            cout << "You guessed it in " << attempts << " attempts!" << endl;
        }

    } while (userGuess != randomNumber);  

    return 0;
}
