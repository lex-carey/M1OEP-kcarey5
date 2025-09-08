#include "game.h"

using namespace std;

Game::Game() {
    month = 0;
    year = 0;
    bombs = 0;
    time = 0;
    reason = 0;
    won = false;
}

void Game::setDate(const int &month, const int &year) {
    this->month = month;
    this->year = year;
}

void Game::setBombs(const int &bombs) {
    this->bombs = 100 - bombs;
    if (this->bombs == 100) won = true;
}

void Game::setTime(const int &time) {
    this->time = time;
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
    return reason;
}

bool Game::getWon() const {
    return won;
}


