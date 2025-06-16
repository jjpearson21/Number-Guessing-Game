#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printWelcomeMessage()
{
    cout << "Welcome to the Random Number Guessing Game!" << endl;
    cout << "I am thinking of a number between 0-100..." << endl;
}

int generateRandomNumber()
{
    return rand() % 101;
}

int getUserGuess()
{
    int userGuess;
    while (true)
    {
        cout << "Enter Guess (0–100): ";
        cin >> userGuess;

        if (cin.fail() || userGuess < 0 || userGuess > 100)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 0 and 100." << endl;
        }
        else
        {
            return userGuess;
        }
    }
}
void playGame()
{
    int target = generateRandomNumber();
    int guess;
    int counter = 0;

    do
    {
        guess = getUserGuess();
        counter++;
        if (guess == target)
        {
            cout << "Congrats! You have correctly guessed the number!" << endl;
            cout << "It only took you " << counter << " tries!" << endl;
        }
        else if (guess < target)
        {
            cout << "Too low!" << endl;
        }
        else if (guess > target)
        {
            cout << "Too high!" << endl;
        }
    } while (guess != target);
}

bool askToPlayAgain()
{
    char choice;
    cout << "Would you like to play again? (y/n)" << endl;
    cin >> choice;

    while (choice != 'y' && choice != 'n')
    {
        cout << "Please enter a valid answer: ";
        cin >> choice;
    }
    if (choice == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    srand(time(0));

    printWelcomeMessage();

    do
    {
        playGame();
    } while (askToPlayAgain() == true);

    cout << "Thank you for playing!" << endl;

    return 0;
}
