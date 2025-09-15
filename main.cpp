#include "game.cpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    bool quit = false;
    //used for LOG_GAME case in switch statement
    char correct = 'n';
    Game myGame = Game();
    vector<Game> games;
    vector<Game> topGames;
    //used for calculating stats
    int average_bombs = 0, average_time = 0, games_won = 0, logic = 0, misclick = 0, miscount = 0, chance = 0;
    //loading game log into games vector
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
    //loading top games into top games vector
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
    //visible beginning of program - menu screen
    cout << "Welcome to the Minesweeper Stats Tracker. " << endl;
    while (!quit)
    {
        cout << "What would you like to do?" << endl <<
            "0 = Log Game" << endl <<
            "1 = View Stats" << endl <<
            "2 = Exit" << endl <<
            "Choice: ";
        int chosen_function;
        //user prompted for a choice until they submit one that works
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
        //represents the different states the program can be in, this is what's being chosen upon start
        enum class Functions {LOG_GAME, VIEW_STATS, QUIT} function = static_cast<Functions>(chosen_function);
        switch (function) {
            case Functions::LOG_GAME:
                cout << "Chosen to log game." << endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                while (correct == 'n') {
                    //next three lines pull month and year from system and set month and year using setDate method
                    time_t now = time(nullptr);
                    tm *localTime = localtime(&now);
                    myGame.setDate((1 + localTime->tm_mon),(1900 + localTime->tm_year));
                    myGame.setTime();
                    myGame.setBombs();
                    //this next line won't happen if the game has been won, reason will be set to NOT_TRACKING
                    if (!myGame.getWon()) myGame.setReason();
                    cout << "Is this information correct? (y/n): ";
                    while (!(cin >> correct)) {
                        cin.clear();
                        string junk;
                        getline(cin, junk);
                        cout << "Invalid input, please type 'y' for yes or 'n' for no." << endl;
                    }
                    //updating game log
                    games.push_back(myGame);
                    ofstream updatedLog("log.csv");
                    for (const Game &game : games) {
                        updatedLog << game.getMonth() << "," << game.getYear() << "," << game.getBombs() << ","
                        << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
                    }
                    updatedLog.close();
                    //game will be put in topGames vector (and subsequently topgames.csv) if there are no top games yet
                    if (topGames.size() == 0){
                        topGames.push_back(myGame);
                        ofstream fileOut("topgames.csv");
                        for (const Game &game : topGames){
                            fileOut << game.getMonth() << "," << game.getYear() << "," << game.getBombs() << ","
                            << game.getTime() << "," << game.getReason() << "," << game.getWon() << "\n";
                        }
                        fileOut.close();
                    }
                    //created game is compared to the last game entered into topGames vector, as this will be the current best game. If new game is better, it is added to topGames and subsequently topgames.csv
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
                    if (correct == 'y') cout << "Your game has been logged. Thank you!" << endl;
                    if (correct == 'n') cout << "Okay, let's start over." << endl;
                    this_thread::sleep_for(chrono::milliseconds(1500));
                }
                //this ensures another game can be added subsequently if the user chooses to do so
                correct = 'n';
                break;
            case Functions::VIEW_STATS:
                cout << "Chosen to view stats." << endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout << "Updating Stats . . . " << endl;
                //tallying numbers for stats
                for (const Game &game : games) {
                    average_bombs += game.getBombs();
                    average_time += game.getTime();
                    if (game.getWon()) games_won++;
                    switch (game.getReason()) {
                        case 1:
                            logic++;
                            break;
                        case 2:
                            misclick++;
                            break;
                        case 3:
                            miscount++;
                            break;
                        case 4:
                            misclick++;
                            break;
                        default: break;
                    }
                }
                average_bombs = average_bombs/games.size();
                average_time = average_time/games.size();
                this_thread::sleep_for(chrono::milliseconds(1000));
                //stats output
                cout << "You have played " << games.size() << " games of Minesweeper so far!" << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(1500));
                cout << "Your average game time is " << average_time
                << " seconds, and your average number of bombs cleared is " << average_bombs << "." << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(3000));
                //following line will only happen if a game has been won
                if (games_won > 0) cout << "You have won " << games_won << " games of Minesweeper so far. Keep it up!" << endl << endl;
                //alternate text for if no games have been won
                else cout << "It looks like you haven't won any games yet. Keep trying and you'll get your first!" << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                //there is an option not to track loss reasons, this ensures that following stats will only be displayed if user chooses to track them.
                if (logic || misclick || miscount || chance) {
                    cout << "Here are your loss stats (ouch)! You've lost " << (games.size() - games_won) << " games so far. " << endl
                    << "You've lost due to a logic error " << logic << " time(s). You've lost to a misclick " << misclick << " time(s) and a miscount " << miscount << " time(s)." << endl
                    << "You've lost due to chance " << chance << " time(s). That one always sucks." << endl << endl;
                    this_thread::sleep_for(chrono::milliseconds(5000));
                }
                cout << "Your best game was on " << topGames.back().getMonth() << "/" << topGames.back().getYear() << "."
                << " You cleared " << topGames.back().getBombs() << " bombs in " << topGames.back().getTime() << " seconds!" << endl << endl;
                this_thread::sleep_for(chrono::milliseconds(2000));
                cout << "Well, those are all the stats I have for you right now. Feel free to log more games and check back for updates!" << endl << endl;
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