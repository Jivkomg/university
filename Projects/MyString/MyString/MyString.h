//
//  MyString.h
//  MyString
//
//  Created by Zhivko Georgiev on 29.03.19.
//  Copyright © 2019 Zhivko Georgiev. All rights reserved.
//

#ifndef MyString_h
#define MyString_h

#include <iostream>

class MyString{
private:
    int size;
    char* values;
//    int capacity;
    
public:
    MyString();
    MyString(const MyString&);
    MyString(const char*);
    MyString(const char);
//    MyString(const int);
    MyString& operator=(const MyString&);
    const int length() const;
    void append(const MyString&);
    MyString concatenate(const MyString&) const;
    void print()const;
    //Gets an array of chars and the chars count. Returns true if any of the chars is contained at least once in the string.
//    bool ContainsAny(char*, int count) const;
    bool contains(const MyString&) const;
//    int Count(const MyString&) const;
    int indexOf(char) const;
    int indexOf(char ch, int startIndex)const;
    int indexOf(const MyString&)const;
    int indexOf(const MyString&, int) const;
//    int FirstIndexOfAny(char*, int) const;
//    int LastIndexOf(char) const;
    MyString substring(int, int) const;
    MyString substring(int) const;
//    std::vector<MyString> Split(char delimiter = ' ')const;
    void insertAt(int index, const MyString& str);
//    void Remove(const MyString& str);
//    void Replace(const MyString& oldStr, const MyString& newStr);
//    int ToInt() const;
//    double ToDouble() const;
//    bool TryParseToDouble() const;
//    bool TryParseToInt() const;
//    char* ToCharArray() const;
    const char operator[](int)const;
    MyString operator+(const MyString&) const;
    MyString operator+(const char*)const;
    MyString& operator+=(const MyString&);
    MyString& operator+=(const char*);
    bool operator==(const MyString&) const;
    bool operator!=(const MyString&) const;
    friend std::istream& operator>>(std::istream& is, MyString& s);
    friend std::ostream& operator<<(std::ostream& os, MyString& s);
//    friend MyString operator+(const char*, const MyString&);

//    explicit operator int() const;
//    explicit operator double() const;
    ~MyString();
};
//    MyString(); //default
//    MyString(const char* values);
//    MyString(int size,const char* values);
//
//    MyString(const MyString&); //copy
//
//
//    void append(const char character);
//    void resize();
//    void insert(int pos, char* string);
//    void replace(int pos, char character);
//    bool compare(char* string) const;
//    void erase(char character);
//    void swap();
//    bool empty() const;
//    char begin() const;
//    char end() const;
//    int substring(MyString&,int,int) const;
//    //    int getSize() const;
//    int length() const;
//    int find(const char*);
//    int getCapacity() const;
//
//    MyString& operator=(const MyString& myString);
//    MyString& operator=(const char*);
//
//    char& operator[](int pos);
//    bool operator==(const MyString& myString);
//    MyString& operator+=(const MyString& myString);
//    friend MyString& operator+(const MyString& myString);
//    friend bool operator<(const MyString&, const MyString&);
//    friend bool operator<(const MyString&, const MyString&);
//
//    friend std::ostream& operator<<(std::ostream&, const MyString&);
//    friend std::istream& operator>>(std::istream&, MyString&);
//
//    char operator[](const MyString& myString);
    
//    ~MyString();




#endif /* MyString_h */
