#define _CRT_SECURE_NO_WARNINGS

#include "uni.h"

using namespace std;

void menu() {
    cout << "\n*********************************************************" << endl;
    cout << "\t1 = створити файл" << endl;
    cout << "\t2 = відкрити свій файл" << endl;
    cout << "\t3 = додати текст у файл" << endl;
    cout << "\t4 = виконати завдання 1 (слово-маска)" << endl;
    cout << "\t5 = виконати завдання 2 (найдовше слово)" << endl;
    cout << "\t6 = подивитись повний результат виконання завдань" << endl;
    cout << "\t0 = закінчити програму" << endl;
    cout << "*********************************************************" << endl;
}

char* createFilePointer() {
    FILE* filePtr;
    static char fileName[100];
    cout << "Введіть ім'я файлу: ";
    cin >> fileName;
    cout << "Створюємо файл... " << endl;
    filePtr = fopen(fileName, "w");
    if (filePtr == nullptr) {
        cout << "Помилка створення файлу!" << endl;
        return nullptr;
    }
    else {
        cout << "Файл успішно створено!" << endl;
        fclose(filePtr);
        return _strdup(fileName);
    }
}

void createFile(string& fileNameStr) {
    cout << "Введіть ім'я файлу: ";
    cin >> fileNameStr;
    ofstream fileStream(fileNameStr);
   
    fileStream.close();
}

void appendFilePtr(char* fileName) {
    FILE* filePtr;
    char ch;
    string line[100];
    int i = 0;
    filePtr = fopen(fileName, "a");
    if (filePtr == NULL) {
        cout << "Помилка відкриття файлу" << endl;
        return;
    }
    else {
        cout << "\nВведіть текст (натисніть CTRL+D щоб закінчити ввід):\n";
        while ((ch = getchar()) != 4) {
            line[i] += ch;
            if (ch == '\n') {
                i++;
            }
        }

        for (int j = 1; j <= i; j++) {
            fprintf(filePtr, "%s", line[j].c_str());
        }
    }
    fclose(filePtr);
}

void appendFileStr(const string& fileName) {
    string line;
    char ch;
    ofstream fout(fileName, ios::app);
    if (!fout.is_open()) {
        cerr << "Помилка відкриття файлу \"" << fileName << "\"" << endl;
        return;
    }
    else {
        cout << "\nВведіть текст (натисніть CTRL+D щоб закінчити ввід):\n";
        cin.ignore();
        while ((ch = getchar()) != 4) {
            if (ch == '\n') {
                fout << line << '\n';
                line.clear();
            }
            else {
                line += ch;
            }
        }

        if (!line.empty()) {
            fout << line;
        }

        fout.close();
    }
}

void readFilePtr(char* fileNamePtr) {
    FILE* file = fopen(fileNamePtr, "r+");
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        cout << buffer;
    }
    fclose(file);
    cout << "\n";
}

void readFileStr(const string& fileName) {
    ifstream inFile(fileName);
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

