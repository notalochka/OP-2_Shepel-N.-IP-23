#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>
#include <chrono>
#include <ctime>
#include <sstream>

#ifndef BINARY


void isValidBinaryFileName(const std::string& filename);
void isValidDate(const std::string& day, const std::string& month, const std::string& year);

void isValidGroup(const std::string& grop);

void createBinaryFile(std::string filename);


class Students {
    char name[100];
    int day;
    int month;
    int year;
    int group;

public:
    Students();
    void setName(const char* n);
    void setDate(const std::string& day, const std::string& month, const std::string& year);
    void setGroup(const std::string& group);
    const char* getName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    int getGroup() const;
    bool isStudentMinor();
};


void saveToFile(std::string filename, Students obj);

std::string readFile(const std::string& filename);

void rewriteFile(const std::string& filename1, const std::string& filename2);
#endif // !BINARY