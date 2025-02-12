#include <bits/stdc++.h>
#include <conio.h>
//i am using kbhit,system("cls"),getch() functions of this this file conio.h
#include <windows.h>
using namespace std;


const char DIR_UP = 'U';
const char DIR_DOWN = 'D';
const char DIR_LEFT = 'L';
const char DIR_RIGHT = 'R';

//global variable for grid
const int GRID_WIDTH = 100;
const int GRID_HEIGHT = 20;

struct Point {
    int xCoord;
    int yCoord;
    Point() {}
    Point(int x, int y) : xCoord(x), yCoord(y) {}
};

struct SnakeNode {
    Point pos;
    SnakeNode* next;
    SnakeNode(int x, int y) : pos(x, y), next(nullptr) {}
};

class Snake {
    int length;
    char direction;
    SnakeNode* head;

public:
    Snake(int x, int y) {
        head = new SnakeNode(x, y);                 // Head of the snake
        head->next = new SnakeNode(x - 1, y);       // Second node
        head->next->next = new SnakeNode(x - 2, y); // Third node
        length = 3; // snake's Initial length is 3
        direction = DIR_RIGHT;
    }

    ~Snake() {
        SnakeNode* current = head;
        while (current != nullptr) {
            SnakeNode* next = current->next;
            delete current;
            current = next;
        }
    }

    int getLength() { return length; }
    SnakeNode* getHead() { return head; }
    //To change Snake's direction
    void changeDirection(char newDirection) {
        if (newDirection == DIR_UP && direction != DIR_DOWN) {
            direction = newDirection;
        } else if (newDirection == DIR_DOWN && direction != DIR_UP) {
            direction = newDirection;
        } else if (newDirection == DIR_LEFT && direction != DIR_RIGHT) {
            direction = newDirection;
        } else if (newDirection == DIR_RIGHT && direction != DIR_LEFT) {
            direction = newDirection;
        }
    }

    bool move(Point food) {
        vector<Point> positions;
        SnakeNode* current = head;
        while (current != nullptr) {
            //To save snake's all node adress in positions vector
            positions.push_back(current->pos);
            current = current->next;
        }
      //to switch snake's direction according user direction
        switch (direction) {
            case DIR_UP:
                head->pos.yCoord--;
                break;
            case DIR_DOWN:
                head->pos.yCoord++;
                break;
            case DIR_RIGHT:
                head->pos.xCoord++;
                break;
            case DIR_LEFT:
                head->pos.xCoord--;
                break;
        }

       //to check that snake's head isn't collide with wall 
        if (head->pos.xCoord <= 0 || head->pos.xCoord >= GRID_WIDTH - 1 ||
            head->pos.yCoord <= 0 || head->pos.yCoord >= GRID_HEIGHT - 1) {
            return false;
        }
        
        //update all node's address with their above nodes
        current = head->next;
        for (int i = 1; current != nullptr; i++) {
            current->pos = positions[i - 1];
            current = current->next;
        }
        
        //to check that snake's head isn't collide with it's own body
        current = head->next;
        while (current != nullptr) {
            if (head->pos.xCoord == current->pos.xCoord &&
                head->pos.yCoord == current->pos.yCoord) {
                return false;
            }
            current = current->next;
        }

        //to add the new node at tail
        if (food.xCoord == head->pos.xCoord && food.yCoord == head->pos.yCoord) {
            current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new SnakeNode(positions.back().xCoord, positions.back().yCoord);
            length++;
        }

        return true;
    }
};

class Board {
    Snake* snake;
    const char SNAKE_BODY = 'O';
    Point food;
    const char FOOD = '*';
    const char WALL = '#';
    int score;
    HANDLE console;
    COORD cursorPosition;
    char grid[GRID_HEIGHT][GRID_WIDTH];

public:
    Board() {
        console = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(console, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(console, &cursorInfo);


        snake = new Snake(GRID_WIDTH / 2, GRID_HEIGHT / 2);
        score = 0;
        initializeGrid();
        spawnFood();
    }

    ~Board() {
        delete snake;
    }

    //initialize new grid with wall
    void initializeGrid() {

        for (int i = 0; i < GRID_HEIGHT; i++) {
            for (int j = 0; j < GRID_WIDTH; j++) {
                if (i == 0 || i == GRID_HEIGHT - 1 || j == 0 || j == GRID_WIDTH - 1) {
                    grid[i][j] = WALL;
                } else {
                    grid[i][j] = ' ';
                }
            }
        }
    }

    int getScore() { return score; }

    //to create food at random position
    void spawnFood() {
        do {
            food.xCoord = 1 + (rand() % (GRID_WIDTH - 2));
            food.yCoord = 1 + (rand() % (GRID_HEIGHT - 2));
        } while (isSnakePosition(food.xCoord, food.yCoord));
    }

    //to check that food should not create at any snake's body position 
    //if it will create at any snake's node position , spawn food function will create random position again
    bool isSnakePosition(int x, int y) {
        SnakeNode* current = snake->getHead();
        while (current != nullptr) {
            if (current->pos.xCoord == x && current->pos.yCoord == y) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void displayCurrentScore() {
        gotoxy(2, GRID_HEIGHT);
        cout << "Score: " << score;
    }

    void gotoxy(int x, int y) {
        cursorPosition.X = x;
        cursorPosition.Y = y;
        SetConsoleCursorPosition(console, cursorPosition);
    }

    void draw() {

        for (int i = 1; i < GRID_HEIGHT - 1; i++) {
            for (int j = 1; j < GRID_WIDTH - 1; j++) {
                grid[i][j] = ' ';
            }
        }


        SnakeNode* current = snake->getHead();
        while (current != nullptr) {
            if (current->pos.xCoord > 0 && current->pos.xCoord < GRID_WIDTH - 1 &&
                current->pos.yCoord > 0 && current->pos.yCoord < GRID_HEIGHT - 1) {
                grid[current->pos.yCoord][current->pos.xCoord] = SNAKE_BODY;
            }
            current = current->next;
        }


        grid[food.yCoord][food.xCoord] = FOOD;

        
        gotoxy(0, 0);  //set cursor at position (0,0)
        for (int i = 0; i < GRID_HEIGHT; i++) {
            for (int j = 0; j < GRID_WIDTH; j++) {
                cout << grid[i][j];
            }
            cout << "\n";
        }

        displayCurrentScore();
    }

    bool update() {
        //isAlive function will check that our snake isn't collide with wall or own body
        //if snake will collide with wall or own body than function will return true
        bool isAlive = snake->move(food);
        if (!isAlive) {
            return false;
        }

        if (food.xCoord == snake->getHead()->pos.xCoord &&
            food.yCoord == snake->getHead()->pos.yCoord) {
            score++;
            spawnFood();
        }
        return true;
    }

    void getInput() {
        //kbhit will return true if user will enter anything with keyboard 
        //kbhit is the function of conio.h header file
        if (kbhit()) {
            int key = getch();
            if (key == 'w' || key == 'W') {
                snake->changeDirection(DIR_UP);
            } else if (key == 'a' || key == 'A') {
                snake->changeDirection(DIR_LEFT);
            } else if (key == 's' || key == 'S') {
                snake->changeDirection(DIR_DOWN);
            } else if (key == 'd' || key == 'D') {
                snake->changeDirection(DIR_RIGHT);
            }
        }
    }
};

int main() {
    srand(time(0));
    system("cls");
    Board* board = new Board();

    while (board->update()) {
        board->getInput();
        board->draw();
        Sleep(150);
    }

    cout << "\nGame Over!" << endl;
    cout << "Final Score: " << board->getScore() << endl;

    delete board;
    return 0;
}
