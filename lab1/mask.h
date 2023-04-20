#pragma once

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef MASK_N
#define MASK_N

using namespace std;

string reverse_word(const string& word);
bool match_mask(const string& word, const string& mask);
void filter_words(vector<string>& words, const string& mask);
vector<string> split_line(const string& line);
void maskInFileStr(string filename, string outputFile);
void maskInFilePtr(char* fileName, char* outputFileName);
void longestWordStr(const string& infilename, const string& outfilename);

#endif // !MASK_N
