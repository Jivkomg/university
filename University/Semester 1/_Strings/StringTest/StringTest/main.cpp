////
////  main.cpp
////  StringTest
////
////  Created by Zhivko Georgiev on 18.12.18.
////  Copyright © 2018 Zhivko Georgiev. All rights reserved.
////
//
//#include <iostream>
//int length(const char* str){
////    int i = 0;
////    while(str[i] != 0){
////        i++;
////    }
//    int counter = 0;
//    while(*str != 0){
//        counter ++;
//        str++;
//    }
//    return counter;
//}
//int min(int a, int b){
//    return a < b?a:b;
//}
//void copy(const char* source, char* dest, int destSize){
//    int len = min(length(source),destSize);
//    for(int i = 0; i < len; i++){
//        dest[i] = source[i];
//    }
//    dest[len] = 0;
//}
//
//char* substring(const char* source , const char* substr){
//    int sourceLen = length(source);
//    int substrLen = length(substr);
//    for(size_t i = 0; i <= sourceLen - substrLen + 1; i++){
////        if(){
////
////        }
//    }
//    return nullptr;
//}
//// compare(str1, str2, len(str1))
//// compare(source + i, sub, subLen)
//int compare(const char* str1, const char* str2){
//    int strLength1 = length(str1);
//    int strLength2 = length(str2);
//    int strLength = min(strLength1,strLength2);
//    for(int i = 0; i < strLength; i++)
//    {
//        if(str1[i] > str2[i])
//        {
//            return 1;
//        }
//        else if(str1[i] < str2[i])
//        {
//            return -1;
//        }
//    }
//    if(strLength1 == strLength2)
//    {
//        return 0;
//    }
//    if(strLength1 > strLength2)
//    {
//        return 1;
//    }
//    return -1;
//}
//int main(int argc, const char * argv[]) {
//    std::cout << std::endl;
//    char str[5] = {'a','0', 'c', 'd'};
//    char str2[2];
//    copy(str, str2, 2);
//    strcpy(str, str2);
//    std::cout << str2 <<'\n';
/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Vasil Nikolaev Vasilev
 * @idnumber 62348
 * @task 2
 * @compiler VC
 *
 */

/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Vasil Nikolaev Vasilev
 * @idnumber 62348
 * @task 3
 * @compiler VC
 *
 */

#include <iostream>
using namespace std;

const int rows = 6;

bool isSimple(int matrix[rows][rows])
{
    bool isMatrixSimple = true;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < rows; c++)
        {
            if (matrix[r][c] > 9 || matrix[r][c] < 0)
            {
                return false;
            }
            else
                isMatrixSimple = true;
        }
    }
    return isMatrixSimple;
}

int cntMatrix(int matrix[rows] [rows], int number)
{
    int cntForDigits = 0;
    int digits[rows];
    int cntForRows1 = 0;
    
    int localNumber1 = number;
    
    if (number == 0)
    {
        cntForDigits = 1;
    }
    while (localNumber1 != 0)
    {
        localNumber1 = localNumber1 / 10;
        cntForDigits ++;
    }
    
    int localNumber2 = number;
    for (int i = 0; i < cntForDigits; i++)
    {
        digits[cntForDigits - i - 1] = localNumber2 % 10;
        localNumber2 = localNumber2 / 10;
        
    }
    //check from left to right for rows
    int localCnt = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < rows; c++)
        {
            for (int k = 0; k < cntForDigits; k++)
            {
                if (matrix[r][c + k] == digits[k])
                {
                    if (c+k >= rows && cntForDigits != 1)
                    {
                        if (c + k == rows && k == cntForDigits - 1)
                        {
                            localCnt++;
                        }
                        else
                        {
                            localCnt = localCnt;
                        }
                    }
                    else
                    {
                        localCnt++;
                    }
                }
                else
                {
                    break;
                }
            }
            localCnt = localCnt / cntForDigits;
            cntForRows1 = cntForRows1 + localCnt;
            localCnt = 0;
        }
    }
    /*    if (cntForDigits == 1)
     {
     return cntForRows1 * 4;
     }
     */
    //check from right to left for rows
    int localCnt2 = 0;
    int cntForRows2 = 0;
    for (int r = 0; r < rows; r++)
    {
        for (int c = rows - 1; c >= 0; c--)
        {
            for (int k = 0; k < cntForDigits; k++)
            {
                if (matrix[r][c - k] == digits[k])
                {
                    if (c - k <= 0 && cntForDigits != 1 )
                    {
                        if (c - k == 0 && k == cntForDigits - 1)
                        {
                            localCnt2++;
                        }
                        else
                        {
                            localCnt2 = localCnt2;
                        }
                    }
                    else
                    {
                        localCnt2++;
                    }
                }
                else
                {
                    break;
                }
            }
            localCnt2 = localCnt2 / cntForDigits;
            cntForRows2 = cntForRows2 + localCnt2;
            localCnt2 = 0;
        }
    }
    
    
    //check from up to down for columns
    int localCnt3 = 0;
    int cntForRows3 = 0;
    for (int c = 0; c < rows; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int k = 0; k < cntForDigits; k++)
            {
                if (matrix[r+k][c] == digits[k])
                {
                    if (r + k >= rows && cntForDigits != 1)
                    {
                        if (r + k == rows && k == cntForDigits - 1)
                        {
                            localCnt3++;
                        }
                        else
                        {
                            localCnt3 = localCnt3;
                        }
                    }
                    else
                    {
                        localCnt3++;
                    }
                }
                else
                {
                    break;
                }
            }
            localCnt3 = localCnt3 / cntForDigits;
            cntForRows3 = cntForRows3 + localCnt3;
            localCnt3 = 0;
        }
    }
    
    //check from down to up for columns
    int localCnt4 = 0;
    int cntForRows4 = 0;
    for (int c = 0; c < rows; c++)
    {
        for (int r = rows - 1; r >= 0; r--)
        {
            for (int k = 0; k < cntForDigits; k++)
            {
                if (matrix[r-k][c] == digits[k])
                {
                    if (r - k <= 0 && cntForDigits != 1)
                    {
                        if (r - k == 0 && k == cntForDigits - 1)
                        {
                            localCnt4++;
                        }
                        else
                        {
                            localCnt4 = localCnt4;
                        }
                    }
                    else
                    {
                        localCnt4++;
                    }
                }
                else
                {
                    break;
                }
            }
            localCnt4 = localCnt4 / cntForDigits;
            cntForRows4 = cntForRows4 + localCnt4;
            localCnt4 = 0;
        }
    }
    
    
    return cntForRows1 + cntForRows2 + cntForRows3 + cntForRows4;
}

int main()
{
    int matrix [rows][rows] =
    {
        {5, 4, 3, 8, 0, 6},
        {9, 4, 5, 1, 0, 2},
        {8, 5, 8, 0, 6, 1},
        {0, 9, 6, 8, 4, 2},
        {6, 1, 0, 2, 6, 1},
        {2, 1, 8, 4, 2, 6}
    };
    
    int myNumber = 0;
    cin >> myNumber;
    
    if (cin.fail())
    {
        return -1;
    }
    
    if (isSimple(matrix) == false)
    {
        cout << "error" << endl;
    }
    else
    {
        int n = cntMatrix(matrix, myNumber);
        cout << n;
    }
    
    
    int x;
    cin >> x;
    return 0;
}
