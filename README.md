# IOBoi
Welcome to IOBoi!
This is a game-playing program that reads custom made cartridges.

>NOTE: The project is the "Game Console" not the games themselves.

When using the program, you have the option to include the cartridge name in the execution (./ioboi [cartridge]) or after you run IOBoi it will prompt for it.
When typing in the cartridge names, make sure to include the ".txt" at the end ("Example.txt") otherwise the program can't recognise it.

You also have the option create your own game if you wish. To do so, you can use the template included in the program files. The template will show you how to layout your game
so that IOBoi can recognize it.

>NOTE: The program has many global variables. The reason is because they are constantly being updated and read in. This is the only way to ensure the program works.

There are many administrative commands that you are able to use to test the programs abilities.
To execute and admin command, you must use this format: "*examplecommand" when it prompts for a command.
The following are current admin commands:
"clear" -Clears the screen.
"showinfo" -Shows information about the current tile.
"checkpos" -Checks the current psotion and updates all variables from the cartridge.
"checkavail" -Checks and displays current available commands.
"drawmap" -Draws the map of the current tile if map is enabled for it.
"quit" -Shuts down the console without confirmation.
"go S" -Travels south and updates all variables.
"go N" -Travels north and updates all variables.
"go E" -Travels east and updates all variables.
"go W" -Travels west and updates all variables.
"pos" -Displays current position.
"//" -Will execute the next command externally in the console. Enter command when it prompts for it.
