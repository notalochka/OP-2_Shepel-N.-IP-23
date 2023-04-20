#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>

#ifndef PROCESSBOOK_H
#define PROCESSBOOK_H

using namespace std;

struct Book;
void checkWinterBooks(const string& filename);
void lastCenturyBooks(const string& fIn, const string& fOut);
#endif // !PROCESSBOOK_H
