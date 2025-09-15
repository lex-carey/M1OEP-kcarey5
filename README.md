# Minesweeper Stats Tracker
All code for this project was authored by Alexis Carey for the M1OEP.

## Project Summary
This is a program I created to be able to track my Minesweeper statistics. It's a game I've been playing for a couple years now so I think it would be cool to be able to track my improvement. When the program is run, you are met with a menu where you can either choose to log a new game or view your game stats. The program guides you through the process of logging a new game.

I used all the concepts in the module 1 concepts menu:
* Class separated into header and .cpp files
  * I created the Game class, which has 6 fields. To acheive what I wanted to in what made the most sense to me, I have not included a method that is not a constructor, getter/setter, or a destructor. That being said, multiple of my setter methods are much more complex than a traditional setter method would typically be (involves user-inputted data and includes input validation), so I feel like I implemented this concept well.
* Overloaded Operators
  * I overloaded all the comparison operators for my class in order to be able to determine what was a "better" or "worse" game. That being said I only ended up using one in my main method, but I intend to use more in the future when I create more statistics. More bombs cleared in a shorter amount of  time is better, therefore a better game would be "greater than" a worse one.
* Enumerated Types
  * I used two enumerated variables in this program. One is the Game class's reason variable, which logs the reason a game has been lost. The user is given five options to choose from (NOT_TRACKING, LOGIC, MISCLICK, MISCOUNT, CHANCE) when logging their game. The other is the function variable, which is used to determine what the main method is doing at the time. The user is prompted to pick one of three options (LOG_GAME, VIEW_STATS, QUIT) upon running the program which will guide what the main method does.

I see the next step for this project being spending more time creating new statistics. It would also be nice to be able to view statistics by month or year in the future, but I didn't have the time to implement that within this timeframe. I'm not very good with graphics but as I get better with that I think it would also be cool to actually create a way to play Minesweeper and have the program automatically log the games played.

## Bugs
I currently know of no unresolved bugs. Everything that I found during my testing I was able to fix. Please let me know if you find something if you end up running this program!

## Grading
I believe I implemented every idea I had for this program to the best of my ability. The program is interactive and all input is validated. I honestly think I did enough here to earn full marks in every section. In my opinion, everything included in this program is used in a way that makes sense, and I hope you think this is a good level of complexity because I'm very proud of it. As addressed above, I realize I didn't exactly meet the requirements for implementing a class but I didn't see any functionality worth adding, and I think trying to create something would have taken away from the program. I believe my setters for bombs, time, and reason are robust enough to compensate for this.