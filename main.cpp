#include "game.cpp"
#include <ctime>
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;



int main() {
    bool quit = false;
    char correct = 'n';
    Game myGame = Game();
    cout << "Welcome to the Minesweeper Stats Tracker. " << endl;
    while (!quit)
    {
        cout << "What would you like to do?" << endl <<
            "0 = Log Game" << endl <<
            "1 = View Stats" << endl <<
            "2 = Exit" << endl <<
            "Choice: ";
        int chosen_function;
        while (!(cin >> chosen_function) || 2 < chosen_function || chosen_function < 0) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "Invalid input, please choose a valid option." << endl <<
                    "0 = Log Game" << endl <<
                    "1 = View Stats" << endl <<
                    "2 = Exit" << endl <<
                    "Choice: ";
        }
        enum class Functions {LOG_GAME, VIEW_STATS, QUIT} function = static_cast<Functions>(chosen_function);
        switch (function) {
            case Functions::LOG_GAME:
                cout << "Chosen to log game." << endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                while (correct == 'n') {
                    myGame.setTime();
                    myGame.setBombs();
                    if (!myGame.getWon()) myGame.setReason();
                    cout << "Is this information correct? (y/n): ";
                    while (!(cin >> correct)) {
                        cin.clear();
                        string junk;
                        getline(cin, junk);
                        cout << "Invalid input, please type 'y' for yes or 'n' for no." << endl;
                    }
                    cout << "Your game has been logged. Thank you." << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }
                break;
            case Functions::VIEW_STATS:
                cout << "Chosen to view stats." << endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "Which stats would you like to view?" << endl;
                break;
            case Functions::QUIT:
                quit = true;
            }
    }
    cout << "Goodbye!" << endl;
    return 0;
}

void chooseFunction()
{

}