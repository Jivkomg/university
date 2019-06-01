/**
 *
 * Solution to homework assignment 2
 * Introduction to programming course
 * Faculty of Mathematics and Informatics of Sofia University
 * Winter semester 2018/2019
 *
 * @author Zhivko Georgiev
 * @idnumber 62304
 * @task 2
 * @compiler GCC
 *
 */


#include <iostream>
using namespace std;

int stringLength(const char* str){
    if(str == nullptr){
        return -1;
    }
    int counter = 0;
    while(*str != 0){
        counter ++;
        str++;
    }
    return counter;
}

const int MAX_STRING_LENGTH = 100;

int lengthLongestRepeatingSubstring(const char* source, const char* substring, int &index){
    index = -1;
    int sourceLength = stringLength(source);
    int substringLength = stringLength(substring);

    bool isSearchedPosition = true;
    
    int maxLength = 0;
    int currentLength = 0;
    
    int currentIndex = 0;
    
    if(sourceLength < substringLength){
        return maxLength;
    }
    
    for (int i = 0; i <= sourceLength;) {
        if(source[i] == substring[0]){
            if(isSearchedPosition){
                currentIndex = i;
                isSearchedPosition = false;
            }
            for (int j = 0; j < substringLength; j++, i++) {
                if(source[i] == substring[j] && j == substringLength - 1){
                    currentLength++;
                }
                if(source[i] != substring[j]){
                    isSearchedPosition = true;
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        index = currentIndex;
                        currentLength = 0;
                    }
                    break;
                }
            }
        }
        else {
            i++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                index = currentIndex;
            }
            currentLength = 0;
            isSearchedPosition = true;
        }
    }
    maxLength *= substringLength;
    return maxLength;
}

void readString(char *str)
{
    do
    {
        std::cin.getline(str, MAX_STRING_LENGTH, '\n');
    } while (str[0] == '\0');

}

int main() {
    char string[MAX_STRING_LENGTH] = "";
    char subString[MAX_STRING_LENGTH] = "";
    readString(string);
    readString(subString);
    
    int index = -1;
    int length = lengthLongestRepeatingSubstring(string, subString, index);
    
    cout << "Index: " << index << endl;
    cout << "Length: " << length << endl;
    return 0;
}
