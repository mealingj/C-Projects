#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

int main() {
    // Seed the random number generator
    std::srand(std::time(0)); 
    int randomNumber = std::rand() % 100 + 1; // Generate random number between 1 and 100
    int userGuess = 0;
    int numberOfGuesses = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have selected a number between 1 and 100.\n";
    std::cout << "Can you guess the number?\n";

    // Game loop
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        numberOfGuesses++;

        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again.\n";
        } else {
            std::cout << "Congratulations! You guessed the correct number in " << numberOfGuesses << " tries.\n";
        }
    }

    return 0;
}