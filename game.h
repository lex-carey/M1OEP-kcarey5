#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {
private:
    int month, year, bombs, time, reason;
    bool won;
public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: month, year, bombs, time, reason, won
     * Creates a new game where all integer variables are set to 0 and won is set to false.
     */
    inline Game();

    /*
    * Set time
    * Requires: Two integers
    * Modifies: month, year
    * Sets the date to the specified month and year
    */
    inline void setDate(const  int &month, const  int &year);

    /*
    * Set bombs
    * Requires: One integer
    * Modifies: bombs
    * Subtracts the passed value from 100 and assigns that value to bombs. Minesweeper tells you the number of bombs remaining out of 100, this gives the number actually found. If all bombs were found, won is set to true.
    */
    inline void setBombs(const int &bombs);

    /*
    * Set time
    * Requires: One integer
    * Modifies: time
    * Sets time (taken to complete the game) to the specified value.
    */
    inline void setTime(const int &time);

    /*
     * Get month
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the month the game was played (0-11).
     */
    inline int getMonth() const;

    /*
     * Get year
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the year the game was played (number of years since 1900).
     */
    inline int getYear() const;

    /*
     * Get bombs
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the number of bombs found during the game.
     */
    inline int getBombs() const;

    /*
     * Get time
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the duration of the game in seconds.
     */
    inline int getTime() const;

    /*
     * Get reason
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the reason the game was lost, or 'Won' if the game was won.
     */
    inline int getReason() const;

    /*
     * Get reason
     * Requires: Nothing
     * Modifies: Nothing
     * Returns true if the game was won, false otherwise.
     */
    inline bool getWon() const;

    friend bool operator < (const Game &g1, const Game &g2) {
        return g1.getTime() < g2.getTime();
    }

    friend bool operator > (const Game &g1, const Game &g2) {
        return g1.getTime() > g2.getTime();
    }

    friend bool operator == (const Game &g1, const Game &g2) {
        return g1.getTime() == g2.getTime();
    }

    friend bool operator != (const Game &g1, const Game &g2) {
        return g1.getTime() != g2.getTime();
    }

    friend bool operator <= (const Game &g1, const Game &g2) {
        return g1.getTime() <= g2.getTime();
    }

    friend bool operator >= (const Game &g1, const Game &g2) {
        return g1.getTime() >= g2.getTime();
    }
};

#endif //GAME_H
