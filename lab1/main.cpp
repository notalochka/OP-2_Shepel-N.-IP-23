#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

#include "uni.h"
#include "mask.h"
#include "lword.h"

using namespace std;


int set_mode(int argc, char** argv) {
    if (argc != 3) return 0;

    string flag{ argv[1] },
        mode{ argv[2] };

    if (flag != "-mode") return 0;

    if (mode == "FilePointer") return 1;
    if (mode == "FileStream") return 2;

    return 0;
}



int main(int argc, char** argv) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int flag;
    flag = 1;
    char* fileNamePtr = nullptr;
    char* outputFileName_1 = nullptr;
    char* outputFileName_2 = nullptr;
    string fileNameStr, outputFile_1, outputFile_2;
    switch (set_mode(argc, argv))
    {
    case 1: {
        cout << "\nПривіт! Це програма для роботи з текстовими файлами!" << endl;
        while (flag != 0) {
            menu();
            cout << "Обери варіант роботи з файлами: ";
            cin >> flag;
            switch (flag) {
            case 0:
            {
                flag = 0;
                cout << "Дякую за роботу!" << endl;
            }
            break;
            case 1:
            {
                fileNamePtr = createFilePointer();
                appendFilePtr(fileNamePtr);
                cout << "\nУ файл доданий такий текст:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 2:
            {
                cout << "Введи назву файлу: ";
                cin >> fileNamePtr;
                cout << "\nВміст файлу:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 3:
            {
                cout << "Введи назву файлу: ";
                cin >> fileNamePtr;
                cout << "\n\tВміст файлу:" << endl;
                readFilePtr(fileNamePtr);
                appendFilePtr(fileNamePtr);
                cout << "\n\tОновлений вміст файлу:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 4:
            {
                cout << "Як назвати новий файл?" << endl;
                outputFileName_1 = createFilePointer();
                maskInFilePtr(fileNamePtr, outputFileName_1);
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFilePtr(fileNamePtr);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFilePtr(outputFileName_1);
            }
            break;
            case 5:
            {
                cout << "Як назвати новий файл?" << endl;
                outputFileName_2 = createFilePointer();
                longestWordPtr(outputFileName_1, outputFileName_2);
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFilePtr(outputFileName_1);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFilePtr(outputFileName_2);
            }
            break;
            case 6:
            {
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFilePtr(fileNamePtr);
                cout << "\n\tВміст проміжного файлу:" << endl;
                readFilePtr(outputFileName_1);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFilePtr(outputFileName_2);
            }
            break;

            }
        }
        break;
    case 2:
    {
        cout << "\nПривіт! Це програма для роботи з текстовими файлами!" << endl;
        while (flag != 0) {
            menu();
            cout << "Обери варіант роботи з файлами: ";
            cin >> flag;
            switch (flag) {
            case 0:
            {
                flag = 0;
                cout << "Дякую за роботу!" << endl;
            }
            break;
            case 1:
            {
                createFileStream(fileNameStr);
                appendFileStr(fileNameStr);
                cout << "\nУ файл доданий такий текст:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 2:
            {
                cout << "Введи назву файлу: ";
                cin >> fileNameStr;
                cout << "\nВміст файлу:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 3:
            {
                cout << "Введи назву файлу: ";
                cin >> fileNameStr;
                cout << "\nВміст файлу:" << endl;
                readFileStr(fileNameStr);
                appendFileStr(fileNameStr);
                cout << "\nОновлений вміст файлу:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 4:
            {
                cout << "Як назвати новий файл?" << endl;
                createFileStream(outputFile_1);
                maskInFileStr(fileNameStr, outputFile_1);
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFileStr(fileNameStr);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFileStr(outputFile_1);
            }
            break;
            case 5:
            {
                cout << "Як назвати новий файл?" << endl;
                createFileStream(outputFile_2);
                longestWordStr(outputFile_1, outputFile_2);
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFileStr(outputFile_1);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFileStr(outputFile_2);
            }
            break;
            case 6:
            {
                cout << "\n\tВміст вхідного файлу:" << endl;
                readFileStr(fileNameStr);
                cout << "\n\tВміст проміжного файлу:" << endl;
                readFileStr(outputFile_1);
                cout << "\n\tВміст вихідного файлу:" << endl;
                readFileStr(outputFile_2);
            }
            break;
            }
        }
    }
    break;
    default:
    {
        cout << "Невідомий режим роботи з файлом!" << endl;
    }
    break;
    }
    }
}

//cd D:\__Програмування\Мои проекты\labaratorna_1\x64\Debug
// -mode FileStream