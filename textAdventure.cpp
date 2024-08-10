#include <iostream>
#include <string>

using namespace std;

// Function declarations
void displayIntro();
void enterRoom1();
void enterRoom2();
void enterRoom3();
void endGame(bool won);

// Global variables to keep track of player's status
bool hasKey = false;
bool hasTreasure = false;

int main() {
    displayIntro();
    enterRoom1();

    return 0;
}

// Function definitions
void displayIntro() {
    cout << "Welcome to the Simple Adventure Game!\n";
    cout << "You are in a mysterious house with three rooms.\n";
    cout << "Your goal is to find the treasure and escape.\n\n";
}

void enterRoom1() {
    cout << "You are in Room 1.\n";
    cout << "There is a locked door to Room 2.\n";
    cout << "What would you like to do?\n";
    cout << "1. Search the room.\n";
    cout << "2. Try to open the door to Room 2.\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You found a key!\n";
        hasKey = true;
        enterRoom1();
    } else if (choice == 2) {
        if (hasKey) {
            cout << "You use the key to unlock the door to Room 2.\n";
            enterRoom2();
        } else {
            cout << "The door is locked. You need to find the key first.\n";
            enterRoom1();
        }
    } else {
        cout << "Invalid choice. Try again.\n";
        enterRoom1();
    }
}

void enterRoom2() {
    cout << "You are in Room 2.\n";
    cout << "There is a treasure chest in the room.\n";
    cout << "What would you like to do?\n";
    cout << "1. Open the chest.\n";
    cout << "2. Go to Room 3.\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "You found the treasure!\n";
        hasTreasure = true;
        enterRoom2();
    } else if (choice == 2) {
        enterRoom3();
    } else {
        cout << "Invalid choice. Try again.\n";
        enterRoom2();
    }
}

void enterRoom3() {
    cout << "You are in Room 3.\n";
    cout << "There is an exit door here.\n";
    cout << "What would you like to do?\n";
    cout << "1. Exit the house.\n";
    cout << "2. Go back to Room 2.\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        if (hasTreasure) {
            endGame(true);
        } else {
            cout << "You need to find the treasure before you can leave!\n";
            enterRoom3();
        }
    } else if (choice == 2) {
        enterRoom2();
    } else {
        cout << "Invalid choice. Try again.\n";
        enterRoom3();
    }
}

void endGame(bool won) {
    if (won) {
        cout << "Congratulations! You found the treasure and escaped the house!\n";
    } else {
        cout << "You lost. Better luck next time!\n";
    }
}