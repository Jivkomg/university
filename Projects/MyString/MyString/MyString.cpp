//
//  MyString.cpp
//  MyString
//
//  Created by Zhivko Georgiev on 29.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#include "MyString.h"
#include <iostream>
//#include <cmath>

//default
MyString::MyString():size(0) {
    values = new char[1];
    values[0] = '\0';
}

//copy-constructor
MyString::MyString(const MyString& rhs):size(rhs.size) {
    values = new char[rhs.size];
    for(int i = 0; i < rhs.size; i++){
        values[i] = rhs[i];
    }
}

MyString::MyString(const char* rhs):size((int)strlen(rhs) + 1) {
    size_t len = strlen(rhs) + 1;
    values = new char[len];
    strcpy(values, rhs);
}

MyString::MyString(const char c):size(1) {
    values = new char[1];
    values[0] = c;
}

//MyString::MyString(const int number):size((bool)number * (int) log10(abs(number)) + 3 ) {
//    size_t len = (bool)number * (int) log10(abs(number)) + 1;
//    values = new char[len + 2];
//    std::string s = std::to_string(number);
//    const char* chars = s.c_str();
//    strcpy(values, chars);
//}



const int MyString::length() const { 
    return size;
}


//explicit MyString::operator int() const {
//    <#code#>;
//}

//explicit MyString::operator double() const {
//    <#code#>;
//}

void MyString::append(const MyString& rhs) {
//    size_t newSize = rhs.size + size;
//    char* newValues = new char[newSize];
//    for(int i = 0; i < size; i++){
//        newValues[i] = values[i];
//    }
//    for(int i = size; i < newSize; i++){
//        newValues[i] = rhs.values[i];
//    }
//    delete[] values;
    char* temp = values;
    size += rhs.size;
    values = new char[size];
    for (int i = 0; i < size - rhs.size; i++)
    {
        values[i] = temp[i];
    }
    for (int i = size - rhs.size, j = 0; i < size; i++, j++)
    {
        values[i] = rhs[j];
    }
    delete temp;
}

MyString MyString::concatenate(const MyString& rhs) const {
    MyString temp = *this;
    temp.append(rhs);
    return temp;
}

void MyString::print() const { 
    std::cout << values;
}

//bool MyString::ContainsAny(char *, int count) const {
//    <#code#>;
//}

bool MyString::contains(const MyString& str) const {
    return this->indexOf(str) != -1;
}

//int MyString::Count(const MyString &) const { 
//    <#code#>;
//}

int MyString::indexOf(char c) const {
    return this->indexOf(c, 0);
}

int MyString::indexOf(char c, int startIndex) const {
    if(startIndex > size){
        return -1;
    }
    for(int i = 0; i < size; i++){
        if(values[i] == c){
            return i;
        }
    }
    return -1;
}

int MyString::indexOf(const MyString& str) const {
    return this->indexOf(str, 0);
}

int MyString::indexOf(const MyString& str, int startIndex) const {
    if(startIndex >= size){
        return -1;
    }
    int index = indexOf(str[0], startIndex);
    MyString temp;
    while (index != -1){
        if (this->substring(index, str.length()) == str){
            break;
        }
        index = this->indexOf(str[0], index + 1);
    }
    return index;

}

//int MyString::FirstIndexOfAny(char *chars, int count) const { 
//    <#code#>;
//}
//
//int MyString::LastIndexOf(char) const { 
//    <#code#>;
//}

MyString MyString::substring(int start, int len) const {
    if (start < 0) {
        return MyString();
    }
    if (start + len > size)
    {
        len = size - start;
    }
    MyString sub;
    for (int i = 0; i < len; i++)
    {
        if (i >= size)
        {
            return sub;
        }
        sub += values[i + start];
    }
    return sub;

}

MyString MyString::substring(int start) const { 
    return substring(start, size);
}

//std::vector<MyString> MyString::Split(char delimiter) const {
//    <#code#>;
//}

void MyString::insertAt(int index, const MyString &rhs) {
    MyString tmp = this->substring(0, index);
    tmp.append(rhs);
    tmp.append(this->substring(index));
    *this = tmp;
}

MyString& MyString::operator=(const MyString& rhs) {
    if(this != &rhs){
        size = rhs.size;
        delete[] values;
        values = new char[rhs.size + 1];
        for(int i = 0; i < rhs.size; i++){
            values[i] = rhs[i];
        }
        
    }
    return *this;
}

const char MyString::operator[](int index) const {
    if(index < size){
        return values[index];
    }
    else{
        std::cout << "No items" << std::endl;
        return '\0';
    }
}

MyString MyString::operator+(const MyString& rhs) const {
    return this->concatenate(rhs);
}

MyString MyString::operator+(const char* rhs) const {
    return *this + MyString(rhs);
}

MyString& MyString::operator+=(const MyString& rhs) {
    this->append(rhs);
    return *this;
}

MyString& MyString::operator+=(const char * rhs) {
    this->append(MyString(rhs));
    return *this;
}

bool MyString::operator==(const MyString& rhs) const {
    if(size != rhs.size){
        return false;
    }
    for(int i = 0; i < size; i++){
        if(values[i] != rhs.values[i]){
            return false;
        }
    }
    return true;
}

bool MyString::operator!=(const MyString& rhs) const {
    if(*this == rhs){
        return false;
    }
    else return true;
}
std::ostream& operator<<(std::ostream& out, MyString& str){
    return out << str.values;
}
std::istream& operator>>(std::istream& in, MyString& str){
    std::string temp;
    in >> temp;
    str.size = (int)temp.length() + 1;
    str.values = new char[str.size];
    str.values[temp.length()] = '\0';
    strcpy(str.values, &temp[0]);
    return in;
}

//void MyString::Remove(const MyString &str) {
//    this->Replace(str, "");
//}

//void MyString::Replace(const MyString &oldStr, const MyString& newStr) {
//    <#code#>;
//}

//int MyString::ToInt() const { 
//    <#code#>;
//}
//
//double MyString::ToDouble() const { 
//    ;
//}
//
//bool MyString::TryParseToDouble() const { 
//    <#code#>;
//}
//
//bool MyString::TryParseToInt() const { 
//    <#code#>;
//}

//char *MyString::ToCharArray() const {
//    <#code#>;
//}
MyString::~MyString() {
    delete[] values;
}
