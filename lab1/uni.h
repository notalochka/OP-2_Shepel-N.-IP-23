#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef UNI_H
#define UNI_H

using namespace std;

void menu();
char* createFilePointer();
void createFileStream(string& fileNameStr);
void appendFilePtr(char* fileName);
void appendFileStr(const string& fileName);
void readFilePtr(char* fileNamePtr);
void readFileStr(const string& fileName);

#endif // !UNI_H
