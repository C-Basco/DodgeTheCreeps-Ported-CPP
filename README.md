# DodgeTheCreeps-Ported-CPP

## Description
Dodge the Creeps is a 2D game developed using the Godot engine utilizing the GDextension framework to run C++ code.  </br>
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
- Wrote code in C++
- compiled code using mingw-w64 that supports GCC
- Used scons to build c++ plugin

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

## GDExtension Plugin Gameplay
### Overview
In this section, we'll explore the gameplay mechanics and features enabled by the GDExtension plugin in your Godot project. The GDExample node provided by the plugin serves as a versatile tool for creating dynamic animations and interactions within your game.

### GDExample Node
The GDExample node, derived from the Sprite2D class, serves as the centerpiece of dynamic animations in your game. It offers the following features:

- Dynamic Movement: The node utilizes sine and cosine functions to generate dynamic movement patterns, creating visually appealing animations.
- Custom Properties: Through the use of custom properties like amplitude and speed, developers can fine-tune the behavior of the node to suit specific gameplay requirements.
- Signal Emission: The node emits signals, such as position_changed, allowing for seamless integration with other nodes and scripts in your game.

### Integrating GDExample into Gameplay
Here's how you can integrate the GDExample node into your gameplay:

- Node Placement: Add the GDExample node to your scene hierarchy in the Godot editor.
- Property Adjustment: Fine-tune the properties of the GDExample node, such as amplitude and speed, to achieve the desired animation behavior.
- Signal Handling: Connect the position_changed signal emitted by the GDExample node to other nodes or scripts to trigger specific actions based on its position changes.

### Example Use Cases
- Dynamic Obstacles: Use the GDExample node to create dynamic obstacles that move in sinusoidal patterns, adding challenge and variety to your game levels.
- Animated Collectibles: Utilize the dynamic movement capabilities of the GDExample node to create visually appealing animated collectible items that players can interact with.
- Environmental Effects: Implement environmental effects such as floating platforms or swaying foliage using the GDExample node to enhance the immersive experience of your game world.

### Customization and Expansion
Feel free to customize the GDExample node further or extend its functionality to suit your specific gameplay needs. You can modify the node's behavior by adjusting its properties, adding new methods, or implementing additional signals as required by your game design.
