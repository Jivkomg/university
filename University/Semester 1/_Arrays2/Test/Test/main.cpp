//
//  main.cpp
//  Test
//
//  Created by Zhivko Georgiev on 6.12.18.
//  Copyright © 2018 Zhivko Georgiev. All rights reserved.
//

#include <iostream>
using namespace std;
const int n = 4;
const int m = 2;

void SwapRows(int r1, int r2)
{
    if (r1 == r2) return;
    int firstR1 = r1 * cols;
    int firstR2 = r2 * cols;
    for (int i = 0; i < cols; i++)
    {
        double tmp = b[firstR1 + i];
        b[firstR1 + i] = b[firstR2 + i];
        b[firstR2 + i] = tmp;
    }
}

//with partial pivot
internal void ElimPartial(Vector B)
{
    for (int diag = 0; diag < rows; diag++)
    {
        int max_row = diag;
        double max_val = Math.Abs(this[diag, diag]);
        double d;
        for (int row = diag + 1; row < rows; row++)
            if ((d = Math.Abs(this[row, diag])) > max_val)
            {
                max_row = row;
                max_val = d;
            }
        SwapRows(diag, max_row);
        B.SwapRows(diag, max_row);
        double invd = 1 / this[diag, diag];
        for (int col = diag; col < cols; col++)
            this[diag, col] *= invd;
        B[diag] *= invd;
        for (int row = 0; row < rows; row++)
        {
            d = this[row, diag];
            if (row != diag)
            {
                for (int col = diag; col < cols; col++)
                    this[row, col] -= d * this[diag, col];
                B[row] -= d * B[diag];
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    double systemBi [m][SIZE] = {0, 1, 1, 0,
        1, 7, 0, -8};
    
    double example [2][SIZE] = {2, 4, 0, 8,
        1, 2, 1, 10};
    
    double example2 [4][4] = {2, -1, 5, 10,
        1, 1, -3, -2,
        2, 4, 1, 1};
    
    double example3 [4][4] = {0, 2, 1, 4,
        1, 1, 2, 6,
        2, 1, 1, 7};
    
    gauss(*systemBi, 2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            cout << example2[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
