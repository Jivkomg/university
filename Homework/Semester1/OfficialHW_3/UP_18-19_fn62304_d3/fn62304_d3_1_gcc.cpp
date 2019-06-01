/**
 *
 * Solution to homework assignment 3
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 1
 * @compiler VC
 *
 */

#include <iostream>
#include <windows.h>

using namespace std;

void pushX(int num) {
    for (int i = 0;i < num; i++) {
        cout << " ";
    }
}
void pushY(int num) {
    for(int i = 0; i < num;i++) {
        cout << endl;
    }
}

const int ROWS = 5;
const int COL = 39;
const int HIGHT = 10;
const int SCREEN_WIDTH = 80;
const int TIME = 200;

void showMovingText(char movingText[ROWS][COL+1]) {
    for (int i = 0; i < COL; i++) {
        system("cls");
        pushY(HIGHT);
        for (int j = 0; j < ROWS; j++) {
            for (int k = COL - 1 - i; k < COL; k++) {
                cout << movingText[j][k];
            }
            cout << endl;
        }
        Sleep(TIME);
    }
}
void animateMovingText(char movingText[ROWS][COL + 1]) {
    for (int i = 1; i < SCREEN_WIDTH - COL; i++) {
        system("cls");
        pushY(HIGHT);
        for (int j = 0; j < ROWS; j++) {
            pushX(i);
            for (int k = 0; k < COL; k++) {
                cout << movingText[j][k];
            }
            cout << endl;
        }
        Sleep(TIME);
    }
}
void deleteMovingText(char movingText[ROWS][COL + 1]) {
    for (int i = 1; i < SCREEN_WIDTH - COL; i++) {
        system("cls");
        pushY(HIGHT);
        for (int j = 0; j < ROWS; j++) {
            pushX(SCREEN_WIDTH - COL + i);
            for (int k = 0; k < COL - i - 1; k++) {
                cout << movingText[j][k];
            }
            cout << endl;
        }
        Sleep(TIME);
    }
}
int main() {
    char hello[ROWS][COL+1]=
    {   "H   H   EEEEE  L      L           O    ",
        "H   H   E      L      L         O   O  ",
        "HHHHH   EEEEE  L      L       O       O",
        "H   H   E      L      L         O   O  ",
        "H   H   EEEEE  LLLLL  LLLLL       O    "};
    
    showMovingText(hello);
    animateMovingText(hello);
    deleteMovingText(hello);
    return 0;
}
