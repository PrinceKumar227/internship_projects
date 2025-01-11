#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secretNumber, guess;
    srand(time(0)); // Seed for random number generator
    secretNumber = rand() % 100 + 1; // Generates a number between 1 and 100

    cout << "Guess the number between 1 and 100: ";
    
    do {
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Too low! Try again: ";
        } else if (guess > secretNumber) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You've guessed the correct number!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}
