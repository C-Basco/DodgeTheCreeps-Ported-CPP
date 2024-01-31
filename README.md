# DodgeTheCreeps-Ported-CPP

## Description
Dodge the Creeps is a 2D game developed using the Godot engine as part of a tutorial/introduction to Godot. This project utilizes the GDextension framework to build a plugin encapsulating custom C++ code to create a player node. </br>

Rack up points while you avoid the creeps that randomly spawn. Survive the chaos as they travel in all different directions. Once you collide with one of them - thats it, game over!</br>
Lets see how long you last!

- Extend Godot functionality with code to create custom functionality packaged into a plugin and integrated into Godot project
- Coded in C++ to define behaviour of custom nodes
- Interacted with Godot API to code game logic in C++
- Applied C++ bindings for GDExtension to "extend" nodes and other built-in classes in Godot using C++

## Technologies used
### Built with
![image](https://github.com/C-Basco/DodgeTheCreeps-Ported-CPP/assets/66858285/f69e0294-29f1-4b17-a54b-f86f907aac5b)
<img src="https://godotengine.org/assets/press/logo_large_color_light.png" width="200" height="100" >
<img src="https://scons.org/images/SCons.png" width="100" height="75" >

### Compiled with
<img src="https://raw.githubusercontent.com/ratfactor/mingw-w64-logo/main/mingw-w64.svg" alt="Min-GW-w64" width="100" height="75" >

#### Technology rundown
- Used Godot Engine specific technology, GDExtension, to interact with native shared libraries at runtime.
- Coded custom node in C++
- compiled code using mingw-w64 that supports GCC
- Used scons to build c++ plugin
- Built the Game inside the Godot engine creating scenes and game logic. 

## Gameplay
#### Objective
In "Dodge the Creeps", the players objective is to avoid the creeps for as long as possible. When you get hit, the game ends.

#### Controls
- Use the arrow keys to move the player around the screen
- Click on a button to begin the game

#### Players Actions
- Move around the screen to avoid the creeps

#### Game Mechanics
- Creeps spawn randomly across the game window
- Creeps move in a straight path, however the are in different directions and random with each spawn
- The timer determines player score. The longer you last, the more points
- The timer doesn't run out but creep spawn randomness creates difficulty in avoiding them. This allows for an engaging challenge.

## GDExtension Plugin : Player Node

#### Overview
The GDExtension plugin enhances gameplay by enabling dynamic movement, animation, and collision detection for the player character. The `Player` class serves as the centerpiece of player interaction in the game.

#### Description

The Player node represents the main character controlled by the player. It handles user input for movement and collision detection with the creeps.

#### Implementation

The Player node is implemented as a custom class `Player` derived from the `Area2D` class provided by Godot. The implementation files include `player.h` and `player.cpp`.

##### Features

- **Movement**: The player can move in four directions (up, down, left, right) using keyboard input.
- **Animation**: The player's movement is accompanied by sprite animations controlled by an `AnimatedSprite2D` node.
- **Collision Detection**: The player's collision shape (`CollisionShape2D`) interacts with the creeps to detect collisions.

#### Methods

- `set_speed`: Sets the movement speed of the player.
- `get_speed`: Retrieves the current movement speed of the player.
- `start`: Initializes the player's position and shows the player on the screen.

#### Signals

- `hit`: Signal emitted when the player collides with a creep.

### Setting up GDExtension plugin 

**Prerequisits** :
  -  Godot4 executable
  -  C++ compiler
  -  Scons as a build tool
  -  copy of godot-cpp repo

       ```
          mkdir gdextension_cpp_example
          cd gdextension_cpp_example
          git clone -b 4.1 https://github.com/godotengine/godot-cpp
       ```
#### File structure overview
```
|
+--first2d/                # game/demo to test the extension
|   |
|   +--art/                #holds all sprite images to be used
|   |
|   +--bin/
|   |   |
|   |   +--player.gdextension  
|   +--fonts/
|   │
|   ├─ HUD.gd
│   ├─ hud.tscn
│   ├─ icon.svg
│   ├─ icon.svg.import
│   ├─ main.gd
│   ├─ main.tscn
│   ├─ mob.gd
│   ├─ mob.tscn
│   ├─ player.gd
│   ├─ player.tscn
│   └─ project.godot
|
+--godot-cpp/             # C++ bindings
|
+--src/                   # source code of the extension we are building
|   |
|   +--register_types.cpp
|   +--register_types.h
|   +--player.cpp
|   +--player.h
|
+-- SConstruct
|
```

#### Structure rundown
  -  `first2d` is the Godot game project folder that holds our scenes and other folders used to build the game in Godot. 
  - `godot-cpp` which holds all the bindings
  - `src/` folder holds our source code which includes:
      - `player.h` and `player.cpp` custom class player
      - `register.h` and `register.cpp` files that tells Godot about all the classes in our GDExtension plugin
  - `SConstruct` is a hardcoded file prewritten and it is used by SCons when building
  - `player.gdextension` is placed in the game folder created when I made a new project in Godot. Inside first2d project bin folder we place the .gdextension file which will lets Godot know what dynamic libraries should be loaded for each platform and the entry function for the module.


### How It Ties in with the Game

The Player node is essential for the core gameplay of "Dodge the Creeps." It allows the player to control the character's movement and interact with the game environment. By avoiding collisions with the creeps, the player can progress through the game and achieve a higher score.

#### Integrating Player into Gameplay
To integrate the `Player` class into gameplay:

1. **Node Placement**: Add the `Player` node to your scene hierarchy in the Godot editor.
2. **Property Adjustment**: Fine-tune the properties of the `Player` node, such as speed and animation, to achieve desired gameplay behavior.
3. **Signal Handling**: Connect signal emitted by the `Player` node to other nodes or scripts to trigger specific actions based on game events. In this case it is `hit` signal.
4. **Attatch Child Nodes**: Can Attatch child nodes in Godot editor to add functionality

## Game Design

