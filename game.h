#ifndef GAME_H
#define GAME_H

class Game {
private:
    int month, year, bombs, time;
    bool won;
    enum class Reasons {NOT_TRACKING, LOGIC, MISCLICK, MISCOUNT, CHANCE} reason;
public:
    /*
     * Default Constructor
     * Requires: Nothing
     * Modifies: month, year, bombs, time, reason, won
     * Creates a new game where all integer variables are set to 0, won is set to false, and reason is set to NOT_TRACKING.
     */
    inline Game();

    /*
     * Overloaded Constructor
     * Requires: Six integers
     * Modifies: month, year, bombs, time, reason, won
     * Creates a new game using the values passed into the function. The integer values for reason and won are static cast onto the variables.
     */
    inline Game(const int &month, const int &year, const int &bombs, const int &time, const int &reason, const int &won);

    /*
    * Set time
    * Requires: Two integers
    * Modifies: month, year
    * Sets the date to the specified month and year.
    */
    inline void setDate(const  int &month, const  int &year);

    /*
    * Set bombs
    * Requires: Nothing
    * Modifies: bombs, sometimes won and reason.
    * Prompts user for number of bombs remaining when game ended. That value is then subtracted from 100 and the resulting is assigned to bombs. If all bombs were found, won is set to true and reason is set to NOT_TRACKING.
    */
    inline void setBombs();

    /*
    * Set time
    * Requires: One integer
    * Modifies: time
    * Prompts user for the amount of time (seconds) the game lasted and sets time to the specified value.
    */
    inline void setTime();

    /*
    * Set reason
    * Requires: Nothing
    * Modifies: reason
    * Prompts user for the reason the game was lost (from a list of options) and sets reason to the specified choice.
    */
    inline void setReason();

    /*
     * Get month
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the month the game was played (1-12).
     */
    inline int getMonth() const;

    /*
     * Get year
     * Requires: Nothing
     * Modifies: Nothing
     * Returns the year the game was played.
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
     * Returns the reason the game was lost and NOT_TRACKING if the game was won or if the user chose not to track this.
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
        bool less = false;
        if (g1.getTime() > g2.getTime()) {
            if (g1.getBombs() <= g2.getBombs()) {
                less = true;
            }
        }
        else if (g1.getBombs() < g2.getBombs()) {
            if (g1.getTime() >= g2.getTime()) {
                less = true;
            }
        }
        return less;
    }

    friend bool operator > (const Game &g1, const Game &g2) {
        bool greater = false;
        if (g1.getTime() < g2.getTime()) {
            if (g1.getBombs() >= g2.getBombs()) {
                greater = true;
            }
        }
        else if (g1.getBombs() > g2.getBombs()) {
            if (g1.getTime() <= g2.getTime()) {
                greater = true;
            }
        }
        return greater;
    }

    friend bool operator == (const Game &g1, const Game &g2) {
        return (g1.getTime() == g2.getTime() && g1.getBombs() != g2.getBombs());
    }

    friend bool operator != (const Game &g1, const Game &g2) {
        return (g1.getTime() != g2.getTime() || g1.getBombs() != g2.getBombs());
    }

    friend bool operator <= (const Game &g1, const Game &g2) {
        bool less = false;
        if (g1.getBombs() == g2.getBombs()) {
            if (g1.getTime() <= g2.getTime()) {
                less = false;
            }
        }
        else if (g1.getBombs() <= g2.getBombs()) less = true;
        return less;
    }

    friend bool operator >= (const Game &g1, const Game &g2) {
        bool greater = false;
        if (g1.getBombs() == g2.getBombs()) {
            if (g1.getTime() > g2.getTime()) greater = false;
            if (g1.getTime() < g2.getTime()) greater = true;
        }
        if (g1.getTime() == g2.getTime()) {
            if (g1.getBombs() > g2.getBombs()) greater = true;
            if (g1.getBombs() < g2.getBombs()) greater = false;
        }
        else if (g1.getBombs() >= g2.getBombs()) greater = true;
        return greater;
    }
};

#endif //GAME_H
