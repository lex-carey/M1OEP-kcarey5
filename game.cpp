#include "game.h"
#include <thread>
#include "iostream"
using namespace std;

Game::Game() {
    month = 0;
    year = 0;
    bombs = 0;
    time = 0;
    reason = Reasons::NOT_TRACKING;
    won = false;
}

Game::Game(const int &month, const int &year, const int &bombs, const int &time, const int &reason, const int &won) {
    this->month = month;
    this->year = year;
    this->bombs = bombs;
    this->time = time;
    this->reason = static_cast<Reasons>(reason);
    this->won = static_cast<bool>(won);
}

void Game::setDate(const int &month, const int &year) {
    this->month = month;
    this->year = year;
}

void Game::setBombs() {
    //every Minesweeper map contains 100 bombs
    cout << "How many bombs were remaining? (Pick an integer between 0 and 100): ";
    int chosen_bombs;
    while (!(cin >> chosen_bombs) || 100 < chosen_bombs || chosen_bombs < 0)
    {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Invalid input, please choose an integer between 0 and 100: ";
    }
    bombs = 100 - chosen_bombs;
    //if all bombs were cleared won is true and reason is set to NOT_TRACKING
    if (bombs == 100) {
        won = true;
        reason = Reasons::NOT_TRACKING;
    }
    cout << chosen_bombs << " bomb(s) remaining. " << bombs << " bomb(s) cleared." << endl;
    if (won) cout << "Congrats on your win!" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
}

void Game::setTime() {
    //999 seconds is the maximum tracked time on Minesweeper
    cout << "How long (in seconds) did the game take? (Please pick an integer between 0 and 999): ";
    int chosen_time;
    while (!(cin >> chosen_time) || 999 < chosen_time || chosen_time < 0)
    {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Invalid input, please choose an integer between 0 and 999: ";
    }
    cout << "Your game took " << chosen_time << " seconds!" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    time = chosen_time;
}

void Game::setReason() {
    //these are the all reasons I've found that I've lost games before so this is what I included
    //numbers correspond to enum's int values
    cout << "Why did you lose the game?" << endl <<
            "0 = Not Tracking Loss Reasons" << endl <<
            "1 = Logic Error" << endl <<
            "2 = Misclick" << endl <<
            "3 = Miscounted Bombs" << endl <<
            "4 = Chance" << endl <<
            "Reason: ";
    int chosen_reason;
    while (!(cin >> chosen_reason) || 4 < chosen_reason || chosen_reason < 0)
    {
        cin.clear();
        string junk;
        getline(cin, junk);
        cout << "Invalid input, please choose an integer between 0 and 4." << endl <<
                "Reason: " << endl;
    }
    //setting reason
    switch (chosen_reason) {
        case 0:
            reason = Reasons::NOT_TRACKING;
            cout << "Chosen reason: Not Tracking" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 1:
            reason = Reasons::LOGIC;
            cout << "Chosen reason: Logic Error" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 2:
            reason = Reasons::MISCLICK;
            cout << "Chosen reason: Misclick" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 3:
            reason = Reasons::MISCOUNT;
            cout << "Chosen reason: Miscounted Bombs" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 4:
            reason = Reasons::CHANCE;
            cout << "Chosen reason: Chance" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
    }
}

int Game::getMonth() const {
    return month;
}

int Game::getYear() const {
    return year;
}

int Game::getBombs() const {
    return bombs;
}

int Game::getTime() const {
    return time;
}

int Game::getReason() const {
    switch (reason) {
        case Reasons::NOT_TRACKING:
            return 0;
        case Reasons::LOGIC:
            return 1;
        case Reasons::MISCLICK:
            return 2;
        case Reasons::MISCOUNT:
            return 3;
        case Reasons::CHANCE:
            return 4;
    }
}

bool Game::getWon() const {
    return won;
}


