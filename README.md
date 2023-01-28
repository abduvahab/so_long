# so_long (115/125)

![image](https://user-images.githubusercontent.com/100579404/215267282-62aca28f-3d30-4e4c-9f78-fdb4a16d81ca.png)


# Description

This is a 42 School's project. The project consists in creating a little 2D game with the MiniLibX, the school's graphic library.

# The Game
To play this game you can use any map of your choice as long follow the following rues:

- The extension need be .ber
- Its must be rectangular, surrounded by wall 1
- Must have only one exit, only one player and at least one collectible

# Control of play
- make
- ./so_long maps/*.ber 
example : ./so_long maps/test.ber

You can use AWSD to move UP, DOWN, LEFT, RIGHT.

For restart the game press ESC or click on the red cross of window. If you touch the enemy you loose the game. To win the game its necessary pick up all collectible and pass for the exit.

# How to execute the game
To start the game you need run the command   make   root directory. This will compile the executable file so_long, to execute its necessary run   ./so_long map_files/map.ber or any map of your choice.
