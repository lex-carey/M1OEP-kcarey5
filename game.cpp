#include "game.h"

#include <thread>

#include "iostream"

using namespace std;

Game::Game() {
    month = 0;
    year = 0;
    bombs = 0;
    time = 0;
    reason = reasons::NOT_TRACKING;
    won = false;
}

void Game::setDate(const int &month, const int &year) {
    this->month = month;
    this->year = year;
}

void Game::setBombs() {
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
    if (bombs == 100) won = true;
    cout << chosen_bombs << " bomb(s) remaining. " << bombs << " bomb(s) cleared." << endl;
    if (won) cout << "Congrats on your win!" << endl;
    this_thread::sleep_for(chrono::milliseconds(600));
}

void Game::setTime() {
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
    switch (chosen_reason) {
        case 0:
            reason = reasons::NOT_TRACKING;
            cout << "Chosen reason: Not Tracking" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 1:
            reason = reasons::LOGIC;
            cout << "Chosen reason: Logic Error" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 2:
            reason = reasons::MISCLICK;
            cout << "Chosen reason: Misclick" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 3:
            reason = reasons::MISCOUNT;
            cout << "Chosen reason: Miscounted Bombs" << endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            break;
        case 4:
            reason = reasons::CHANCE;
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
        case reasons::NOT_TRACKING:
            return 0;
        case reasons::LOGIC:
            return 1;
        case reasons::MISCLICK:
            return 2;
        case reasons::MISCOUNT:
            return 3;
        case reasons::CHANCE:
            return 4;
    }
}

bool Game::getWon() const {
    return won;
}


