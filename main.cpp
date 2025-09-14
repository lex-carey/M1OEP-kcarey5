#include "game.cpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    bool quit = false;
    char correct = 'n';
    Game myGame = Game();
    vector<Game> games;
    vector<Game> topGames;
    int average_bombs = 0, average_time = 0, games_won = 0;
    ifstream log("log.csv");
    if (log) {
        int month, year, bombs, time, reason, won;
        char comma;
        while (log) {
            log >> month;
            log >> comma;

            log >> year;
            log >> comma;

            log >> bombs;
            log >> comma;

            log >> time;
            log >> comma;

            log >> reason;
            log >> comma;

            log >> won;
            log >> ws;

            games.push_back(Game(month, year, bombs, time, reason, won));

            if (log.peek() == EOF) log.close();
        }
    }
    ifstream fileIn("topgames.csv");
    if (fileIn)
    {
        int month, year, bombs, time, reason, won;
        char comma;
        while (fileIn) {
            fileIn >> month;
            fileIn >> comma;

            fileIn >> year;
            fileIn >> comma;

            fileIn >> bombs;
            fileIn >> comma;

            fileIn >> time;
            fileIn >> comma;

            fileIn >> reason;
            fileIn >> comma;

            fileIn >> won;
            fileIn >> ws;

            topGames.push_back(Game(month, year, bombs, time, reason, won));

            if (fileIn.peek() == EOF) fileIn.close();
        }
    }
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
                    time_t now = time(nullptr);
                    tm *localTime = localtime(&now);
                    myGame.setDate((1 + localTime->tm_mon),(1900 + localTime->tm_year));
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
                    games.push_back(myGame);
                    ofstream updatedLog("log.csv");
                    for (const Game &game : games) {
                        updatedLog << game.getMonth() << "," << game.getYear() << "," << game.getBombs() << ","
                        << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
                    }
                    updatedLog.close();
                    if (topGames.size() == 0){
                        topGames.push_back(myGame);
                        ofstream fileOut("topgames.csv");
                        for (const Game &game : topGames){
                            fileOut << game.getMonth() << "," << game.getYear() << "," << game.getBombs() << ","
                            << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
                        }
                        fileOut.close();
                    }
                    else {
                        if (myGame >= topGames.back()) {
                            topGames.push_back(myGame);
                            ofstream fileOut("topgames.csv");
                            for (const Game &topGame : topGames) {
                                fileOut << topGame.getMonth() << "," << topGame.getYear() << "," << topGame.getBombs() << ","
                                << topGame.getTime() << "," << topGame.getReason() << "," << topGame.getWon() << "\n";
                            }
                            fileOut.close();
                        }
                    }
                    if (correct == 'y') cout << "Your game has been logged. Thank you. Please note you will have to exit the program for your stats to update." << endl;
                    if (correct == 'n') cout << "Okay, let's start over." << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }
                correct = 'n';
                break;
            case Functions::VIEW_STATS:
                cout << "Chosen to view stats." << endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "Updating Stats . . . " << endl;
                for (const Game &game : games) {
                    average_bombs += game.getBombs();
                    average_time += game.getTime();
                }
                for (const Game &game : games) {
                    if (game.getWon()) games_won++;
                }
                average_bombs = average_bombs/games.size();
                average_time = average_time/games.size();
                this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "You have played " << games.size() << " games of Minesweeper so far!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
                cout << "Your average game time is " << average_time
                << " seconds, and your average number of bombs cleared is " << average_bombs << "." << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                if (games_won > 0) cout << "You have won " << games_won << " games of Minesweeper so far. Keep it up!" << endl;
                else cout << "It looks like you haven't won any games yet. Keep trying and you'll get your first!" << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
                cout << "Your best game was on " << topGames.back().getMonth() << "/" << topGames.back().getYear() << "."
                << " You cleared " << topGames.back().getBombs() << " bombs in " << topGames.back().getTime() << " seconds!" << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout << "Well, those are all the stats I have for you right now. Feel free to log more games and check back for updates!" << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                break;
            case Functions::QUIT:
                quit = true;
            }
    }
    cout << "Goodbye!";
    this_thread::sleep_for(chrono::milliseconds(1500));
    return 0;
}