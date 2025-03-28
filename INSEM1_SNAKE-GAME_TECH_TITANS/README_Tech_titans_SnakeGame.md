# Janv1_TechTitans_SnakeGame_Project_1
# Snake Game in C++

This is a simple **Snake Game** written in **C++** that runs in a Windows console. The game allows you to control a snake that grows longer as it eats food, while avoiding collisions with the walls and itself. The game ends if the snake hits the wall or its own body.

## Features

- **Snake Movement**: Move the snake in four directions using `W`, `A`, `S`, and `D` keys.
- **Food**: The snake eats food represented by `*` to grow longer.
- **Wall Boundaries**: The snake cannot pass through walls (represented by `#`).
- **Score**: The score increases as the snake eats food.
- **Console-based**: The game runs in a Windows console window.

## Analysed Data Structure

# Object Structure
# Snake Object Structure:
The snake is represented using a linked list of SnakeNode objects. Each SnakeNode holds a Point object representing the coordinates of a segment of the snake's body. The Snake class manages this list, with the head of the snake pointing to the first node, and each node pointing to the next segment. The last node in the list points to nullptr, marking the end of the snake. This linked list structure allows the snake to move and grow dynamically, as new nodes are added to the tail when the snake eats food.

# Board Object Structure:
The Board class represents the game area. It contains a grid that tracks the game state and a Snake object to manage the snake’s position and movement. It also keeps a Point object for the food’s position, which is randomly placed on the grid. The Board class is responsible for updating the grid, handling user input, and keeping track of the score. It redraws the grid each frame, places new food when eaten, and updates the score accordingly.

# How the Objects Work Together
Initialization: The game begins with the Board class initializing the grid, creating the snake (starting with 3 segments), and placing the first food on the grid at a random location.

User Input: The Board listens for WASD key presses, which change the snake’s direction. The snake’s movement is then updated based on the new direction.

Game Loop: The game runs continuously, where the Board class:

Updates the snake's movement by calling the move function of the Snake class.
Redraws the grid with the updated positions of the snake and food.
Increases the score and grows the snake when it eats food.
Ends the game if the snake collides with a wall or itself.
# Conclusion
The game uses several key data structures:

Point: Represents coordinates for the snake and food.
SnakeNode: Represents each segment of the snake’s body in the linked list.
Snake: Manages the snake's movement, direction, and growth.
Board: Manages the grid, handles input, tracks the game state, and displays the score.
By using a linked list for the snake’s body, the game allows for dynamic movement and growth, making it easier to manage the snake’s length as the game progresses. The structure of these objects ensures efficient handling of game mechanics, including input processing, collision detection, and updating the game display

## How to Run

### Prerequisites

- A C++ compiler (like **MinGW** or **Visual Studio**)
- Windows operating system (as the game uses Windows-specific libraries)

### Steps to Run the Game

1. **Clone the repository**:

    ```bash
    git clone https://github.com/JanviVPatel/Janv1
    ```

2. **Navigate to the project folder**:

    ```bash
    cd tech_titans
    ```

3. **Compile the code**:

    If using `g++` (MinGW or similar), run:

    ```bash
    g++ -o tech_titans.cpp
    ```

    Or if using Visual Studio, open the project in Visual Studio and build the solution.

4. **Run the game**:

    On the command line:

    ```bash
    ./tech_titans
    ```

    The game will open in a Windows console window.

## Controls

- `W` or `w`: Move the snake **up**.
- `A` or `a`: Move the snake **left**.
- `S` or `s`: Move the snake **down**.
- `D` or `d`: Move the snake **right**.

## How to Play

1. Use the `W`, `A`, `S`, and `D` keys to move the snake in the desired direction.
2. The snake will eat food (`*`) and grow longer with each piece it consumes.
3. Avoid running into the wall (`#`) or the snake's own body.
4. The game will display your score at the bottom of the screen.
5. The game ends if the snake collides with the wall or itself.

## Game Over

- The game will display "Game Over!" and your final score when the snake collides with a wall or itself.

## Code Structure

- **Snake Class**: Represents the snake, stores its position, and handles movement and direction changes.
- **Board Class**: Responsible for rendering the game grid, drawing the snake and food, and handling user input.
- **Point Struct**: Represents a 2D point (used for storing the position of the snake's body and food).
- **SnakeNode Struct**: Represents a single node in the snake's body.

## Dependencies

- The game is written in **C++** and uses the following libraries:
    - `<bits/stdc++.h>`: For various C++ standard libraries.
    - `<conio.h>`: For handling keyboard input (specifically `kbhit()` and `getch()`).
    - `<windows.h>`: For controlling the console, getting screen buffer info, and handling cursor positions.

## License

This project is open-source and available under the [MIT License](LICENSE).

---

Enjoy playing the game, and feel free to modify the code as you wish!

## Group Name

TECH TITANS

## Group Member's Name

1.Patel Janvi - 202401447<br/>
2.Patel Shreya - 202401450<br/>
3.Patel Vishwa - 202401451<br/>
4.Vanshi Parikh - 202401443<br/>
