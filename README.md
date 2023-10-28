# Battleship

<h1 align="center">
  Alassane WADE Battleship Game
</h1>
                                                   o
                                      Allsel.23  --|--
                                                  / \
                                                  
                                       "⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿. "


I created the famous game of Battleship in C Language.
This game can be played by using the terminal of your computer.

As a player, you can place randomly or manually your boat and shoot the IA's
boats.


<img width="1306" alt="Screen Shot 2021-03-15 at 8 29 18 PM" src="https://github.com/alassane8/BattleShip/blob/main/BattleShip/Capture.PNG">

# Instructions

To play the Battleship follow the following instructions :

1. Install Visual Studio Code:
If you haven't already installed Visual Studio Code, you can download it from the official website: https://code.visualstudio.com/.


2. Download and Install GCC (GNU Compiler Collection) :

The process may vary depending on your operating system. Here are instructions for some common operating systems:

a. Installing GCC on Linux (Ubuntu/Debian):

GCC is often pre-installed on most Linux distributions, but if it's not, you can easily install it using the package manager.
Open a terminal and run the following command to install GCC:

```bash
sudo apt update
sudo apt install gcc
```

b. Installing GCC on Linux (Fedora):

For Fedora or other Red Hat-based distributions, use the following commands:

```bash
sudo dnf install gcc
``` 

c. Installing GCC on Linux (openSUSE):
For openSUSE, use the following commands:

```bash
sudo zypper install gcc
```

d. Installing GCC on macOS:

On macOS, you can install GCC using the package manager called Homebrew. If you don't have Homebrew installed, you can install it first by running the following command:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
```

Once Homebrew is installed, you can install GCC:

```bash
brew install gcc
```

e. Installing GCC on Windows:

On Windows, you can use the MinGW (Minimalist GNU for Windows) distribution to get GCC. 
You can follow these steps: https://dev.to/gamegods3/how-to-install-gcc-in-windows-10-the-easier-way-422j

3. Compile code :

You can use the GCC compiler:

```bash
gcc -o BattleshipColor.exe main1.c
```

Run the Executable:

After a successful compilation, you can run the generated .exe file from the terminal:

```bash
./BattleshipColor.exe
```
4. Have fun !

You are now ready to play !

# Rules

Here are the rules of the game:

At the start of the game, Player 1 randomly or manually places all the ships on
the grid. Player 1 does not see the AI grid.

Player 1 shoots at (h,7), corresponding to the square of the enemy grid
at the crossing of the letter h and of number 7.
If Player 1 or the AI fires at an enemy ship, the letter 'T' will appear on the
hit space.

The shooter can play twice in a row to attempt to hit the enemy once more.
If player 1 or the AI does not hit a ship, the message '0' will appear on the
failed space.
The 'T' and '0' marks are used to remember missed shots ('0') and hits ('T').

Each turn, Player 1 can either fire into the enemy's grid, activate air support
which fires 5 shots in the enemy's grid, activate satellite view in
order to see enemy's shipsor launch a flare.
Player 1 is able to save the current game and return to the main menu.
A battleship game ends when one of the players has no ships remaining.

# Informations about the ships

Here are the boats you can place:
Aircraft Carrier, Cruiser, Destroyer and Submarine.
- The unique Aircraft Carrier with the letter P takes up 7 spaces.
- 2 Cruisers with the letter C take up 5 spaces.
- 3 Destroyers with the letter D take 3 spaces.
- 4 Submarines with the letter S take up 1 space.

# Area for improvement

- Comment the code more:
Make sure to add descriptive comments for each function, method, and code section. Explain the purpose of each line of code, the algorithms used, and any complex logic. This will facilitate the understanding of your code by both yourself and other developers.

- Manual placement of ships:
Add a feature that allows players to manually place their ships on the grid. You can ask players to specify the starting and ending coordinates for each ship, and ensure that the placement is valid.

- Player 1 vs. Player 2:
Divide the game into two separate parts for each player. Each player should have their own grid and their own ships to place. Make sure that players do not see the opponent's grid.

- Sinking ships:
Add logic to handle shots and the destruction of ships. When a shot hits a ship, mark the square as hit. When all squares of a ship have been hit, the ship is sunk.

- End of the game:
Implement logic to detect the end of the game. The game can end when all of a player's ships have been sunk. Announce the winner and conclude the game appropriately.