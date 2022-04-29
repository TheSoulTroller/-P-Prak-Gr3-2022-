#pragma once
#include <iostream>
#include <cstring>
#include <cstddef>
#include <fstream>
#include <exception>

using std::cin;
using std::cout;
using std::endl;
using std::boolalpha;
using std::exception;

class String
{
    char* symbols;
    int size;
    int capacity;

    void copy(const String& other);
    void resize();
    void downsize();
    void erase();

public:
    String();
    String(const char*);
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    String copyFromToIndex(const int start,int end);
    const int lenght() const;
    bool hasSubstr(const String& find) const;
    void reverse();
    void clearStr();
    bool isEmpty() const;
    String (String&& other);
    void replace(const String& find, const String& replace);

    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    bool operator<=(const String& other) const;
    bool operator>=(const String& other) const;

    String operator+(const String& other);
    String& operator+=(const String& other);
    String operator-(const String& other);
    String& operator-=(const String& other);
    const char& operator[](int index) const;
    char& operator[](int index);
    String& operator=(const char* source);
    friend std::ostream& operator<<(std::ostream& out, const String& str);
    friend std::istream& operator>>(std::istream& in, String& str);
};