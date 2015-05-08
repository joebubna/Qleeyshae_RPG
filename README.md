# Qleeyshae_RPG

An ASCII based RPG game.


##### CREATED BY ######
Josiah Bubna -- joebubna@gmail.com
Kyle Jacobsen -- Suubersnake@gmail.com
Chris -- aethyrium@gmail.com
Daniel -- kuwala@gmail.com


##### GAME INSTRUCTIONS #####
Move around the map by using the Numpad. To enter a building, cave, etc, hit the "5" key on the numpad.
All the other important commands are shown on the screen.


##### HOW TO MAKE A MAP USING THE MAPBUILDER TOOL ######
Step 1: Create a visual view of your map.
Instructions:
Map can be any size, just make sure you put a forward slash at the end of every line.
Once created, save the map in the maps folder of the game in a folder with the name of the map. 
You can save this visual map with any name you like, but I recommend a standard name such as "vmap.txt".

Examples of Save Path: 
Path-to-Game\maps\MyMapName\vmap.txt
Path-to-Game\maps\cave1\vmap.txt
Path-to-Game\maps\cave2\vmap.txt

Example of visual map:
# # . # # /
# . . . # /
. . . . . /
. . . . . /
. . ~ . . /
. . . . . /
. . . . . /
# . . . # /
# # . # # /

Additional Info:
Putting non-terrain characters (*, Y) will result in the default terrain type being loaded in that mapsquare.

Warning:
DO NOT put spaces in the name of your maps.

Step 2: Run the Map Builder program.
Instructions:
1. The program will ask you for the location of a visual map in relation to itself.
Example:
If MapBuilder.exe is in "path-to-game", then you would enter something like "maps/cave1/vmap.txt" at this prompt.

2. The program will ask you for the default terrain type for the map it is processing.
Example:
If the map is a cave, you would enter "rock", if the map is outdoors, you would enter "grass".

3. The program will ask you for the location you want to save the terrain file it is going to make. Note: this also determines the output file's name.
Example:
If the map you are running is Cave1, you would type "maps/cave1/terrain.txt".

Step 3: Create the info.txt file for the map you are creating.
This file contains the Width, Height, MapType, Starting_X, and Starting_Y attributes for the game engine.

Example:
19 19 cave 0 0

The above tells us that the map is a 19 by 19 map of type "cave" and that the default starting location for the player is the top left corner 
at location 0,0.

Step 4: Create your Warps.
Instructions:
To make a new map accessible in the game, obviously you need to have a warp point to it from some map already accessible in the game.
(This can be the main map, or another map which you can get to "somehow" from the main map through one or several other warp points).

Start by opening the "warps.txt" file of the already existing map that you want to have a warp point to your new map from.
You can add new warps points to this file by following this pattern:
X Loc of Warp, Y loc of Warp, Name of map to warp to, X point on map to warp to, Y point on map to warp to

Example from "maps/main/warps.txt":
0 0 cave1 3 3
^ This means the map "main" will have a warp point in its top left corner that warps you to a map named "cave1" and places you at mapsquare (3,3) in that map.

Once you have a way to get to your new map, you probably want to be able to get back out of it, so you will need to open (or create new)
the warps file of your new map (I.E. maps/cave1/warps.txt) and add into it a warp that takes you back to the map you came from or to some other already existing map
that you can get back to the main map from.

Step 5: Add in your people and buildings.
I'm not going to cover this here just yet.
