# Tetris Console Game

## Overview
This is a classic Tetris implementation for Windows console. The game features colorful graphics, smooth controls, progressive difficulty, and score tracking.

## Game Features
- **7 Tetromino Shapes**: Play with all traditional Tetris pieces (I, O, T, S, Z, J, L)
- **Color-Coded Blocks**: Each piece has its own distinct color
- **Next Piece Preview**: See what piece is coming up next
- **Score System**: Earn more points for clearing multiple lines at once
- **Level Progression**: Speed increases as you clear more lines
- **High Score Tracking**: Your best score is saved between sessions
- **Wall Kick System**: Intelligent rotation that allows pieces to rotate near walls

## How to Play

### Controls
- **Left/Right Arrow**: Move the current piece horizontally
- **Up Arrow**: Rotate the piece clockwise
- **Down Arrow**: Soft drop (accelerate descent)
- **Double-Spacebar**: Hard drop (instant placement)
- **Spacebar**: To Pause The Game 
- **ESC**: Quit the game
- **R**: Restart after game over

### Scoring System
- **Single Line Clear**: 40 points × current level
- **Double Line Clear**: 100 points × current level
- **Triple Line Clear**: 300 points × current level
- **Tetris (Four Line Clear)**: 1200 points × current level

### Level System
- Game starts at Level 1
- Level increases after every 5 lines cleared
- Each level increases the falling speed of the pieces

## Game Rules
1. **Objective**: Arrange falling pieces to create complete horizontal lines
2. **Line Clearing**: When a line is filled completely with blocks, it disappears and all blocks above move down
3. **Game Over**: Occurs when new pieces can no longer enter the playing field
4. **Piece Movement**: Each piece can be moved left, right, down, or rotated as it falls
5. **Locking**: Pieces "lock" in place when they land on a surface or another block

## Technical Details
- Written in C++ for Windows console
- Uses the Windows API for console manipulation and input handling
- Features custom tetromino rotation handling with wall kicks
- Implements persistent high score system using file I/O
- Custom ASCII-based UI with color support

## Building and Running
1. Compile using any C++ compiler that supports Windows-specific libraries:
   ```
   g++ -o tetris.exe tetris.cpp -std=c++11
   ```
2. Run the executable in a Windows console environment
3. For best results, use a console window with at least 80×30 characters

## Implementation Highlights
- **Tetromino Class**: Encapsulates the behavior of different tetromino shapes
- **Game Logic**: Handles piece movement, rotation, collision detection, and line clearing
- **Console Rendering**: Custom console graphics with colored block characters
- **Input Handling**: Real-time keyboard input processing
- **Game State Management**: Tracks current state, scores, levels, and transitions

## Tips and Tricks
- Plan ahead using the "Next Piece" preview
- Create a well (a vertical empty column) for I-pieces to achieve Tetris line clears
- Use hard drop (Spacebar) for precise and quick placements
- Try to keep the stack as low as possible
- Clear multiple lines at once for higher scores

## Known Issues
- The game requires a Windows environment due to console-specific API calls
- Console window must be properly sized for optimal display
- Some keyboard layouts may require different handling for arrow keys

## Future Improvements
- Implement a hold piece feature
- Add ghost piece to show where the current piece will land
- Implement additional game modes (e.g., Marathon, Sprint, Ultra)
- Add sound effects and music

---

Enjoy the game and aim for the highest score possible!

## Group Name

TECH TITANS

## Group Member's Name

1.Patel Janvi - 202401447
2.Patel Shreya - 202401450
3.Patel Vishwa - 202401451
4.Vanshi Parikh - 202401443
