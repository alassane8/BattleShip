<h1 align="center">
Alassane WADE Battleship Game
</h1>  

<h2 align="center">
 "⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿. "
</h2>                                      

Game of Battleship in C Language.
It can be played by using any terminal of your computer (Windows Power shell, Command Prompt...)

As a player, you can place randomly or manually your boat and fire at the IA's boats.

<img width="1306" alt="Screen Shot 2021-03-15 at 8 29 18 PM" src="https://github.com/alassane8/BattleShip/blob/main/code/Capture.PNG">

## Instructions
To play the Battleship follow the following instructions :

## Open a terminal in full screen.
- Clone this github repository in the path of your choice: 
```bash
git clone https://github.com/alassane8/BattleShip.git
```
- Go to the BattleShip folder :
```bash
cd BattleShip/code
```
- Run the Executable: 
```bash
./BattleshipColor.exe
```

## Have fun !
You are now ready to play !

## Rules
Here are the rules of the game: 

At the start of the game, Player 1 randomly or manually places all the ships on
the grid. Player 1 does not see the AI grid.

Player 1 shoots at (h,7), corresponding to the square of the enemy grid
at the crossing of the letter h and of number 7.
If Player 1 or the AI fires at an enemy ship, the letter 'X' will appear on the
hit space.

The shooter can play twice in a row to attempt to hit the enemy once more.
If player 1 or the AI does not hit a ship, the message '0' will appear on the
failed space.
The 'X' and '0' marks are used to remember missed shots ('0') and hits ('X').

Each turn, Player 1 can either fire into the enemy's grid, activate air support
which fires 5 shots in the enemy's grid, activate satellite view in
order to see enemy's shipsor launch a flare.
Player 1 is able to save the current game and return to the main menu.
A battleship game ends when one of the players has no ships remaining.

## Informations about the ships
Here are the boats you can place:
Aircraft Carrier, Cruiser, Destroyer and Submarine.
- The unique Aircraft Carrier with the letter P takes up 7 spaces.
- 2 Cruisers with the letter C take up 5 spaces.
- 3 Destroyers with the letter D take 3 spaces.
- 4 Submarines with the letter S take up 1 space.

## Area for improvement
Here, you can find the features I am currently working on in this repository.
This allows you to be aware of the changes that are to come and see what needs to be improve. 