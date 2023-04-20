#define _CRT_SECURE_NO_WARNINGS

#include "lword.h"
#include "mask.h"

using namespace std;

void longestWordPtr(char* infilename, char* outfilename) {
    FILE* inFile = fopen(infilename, "r");
    FILE* outFile;
    string line;
    vector<string> words;
    string word;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), inFile)) {
        string line(buffer);
        words = (split_line(line));

        // Знаходимо найдовше слово у векторі та переставляємо його на початок відповідного рядка
        auto maxIt = max_element(words.begin(), words.end(),
            [](const string& a, const string& b) {
                return a.length() < b.length();
            });

        if (maxIt != words.end()) {
            string longestWord = *maxIt;
            words.erase(maxIt);
            words.insert(words.begin(), longestWord);
        }
        outFile = fopen(outfilename, "a");
        for (const auto& word : words) {
            fprintf(outFile, "%s ", word.c_str(), "\n");
        }
        fclose(outFile);
    }
    fclose(inFile);
}