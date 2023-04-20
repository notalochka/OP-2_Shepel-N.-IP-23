#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>

#ifndef BIN_H
#define BIN_H

using namespace std;

void menu();

struct Book;
string createBinaryFile();
void addBookToCatalog(const string& filename);
void readCatalog(const string& filename);


#endif // !BIN_H
