#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3;  // Generate a number between 0 and 2
    if (choice == 0) return "Rock";
    else if (choice == 1) return "Paper";
    else return "Scissors";
}

string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "It's a tie!";
    } else if ((userChoice == "Rock" && computerChoice == "Scissors") ||
               (userChoice == "Paper" && computerChoice == "Rock") ||
               (userChoice == "Scissors" && computerChoice == "Paper")) {
        return "You win!";
    } else {
        return "You lose!";
    }
}

int main() {
    string userChoice;
    string computerChoice;
    string result;
    char playAgain;

    srand(time(0));  // Initialize random seed

    do {
        cout << "Enter Rock, Paper, or Scissors: ";
        cin >> userChoice;

        // Convert user input to lowercase for consistency (optional)
        for (auto &c : userChoice) {
            c = tolower(c);
        }

        // Get computer's choice
        computerChoice = getComputerChoice();

        // Display choices
        cout << "You chose: " << userChoice << endl;
        cout << "Computer chose: " << computerChoice << endl;

        // Determine the winner
        result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        // Ask if the user wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;

    return 0;
}
