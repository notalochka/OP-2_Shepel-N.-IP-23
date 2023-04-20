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
        cout << "\n�����! �� �������� ��� ������ � ���������� �������!" << endl;
        while (flag != 0) {
            menu();
            cout << "����� ������ ������ � �������: ";
            cin >> flag;
            switch (flag) {
            case 0:
            {
                flag = 0;
                cout << "����� �� ������!" << endl;
            }
            break;
            case 1:
            {
                fileNamePtr = createFilePointer();
                appendFilePtr(fileNamePtr);
                cout << "\n� ���� ������� ����� �����:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 2:
            {
                cout << "����� ����� �����: ";
                cin >> fileNamePtr;
                cout << "\n���� �����:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 3:
            {
                cout << "����� ����� �����: ";
                cin >> fileNamePtr;
                cout << "\n\t���� �����:" << endl;
                readFilePtr(fileNamePtr);
                appendFilePtr(fileNamePtr);
                cout << "\n\t��������� ���� �����:" << endl;
                readFilePtr(fileNamePtr);
            }
            break;
            case 4:
            {
                cout << "�� ������� ����� ����?" << endl;
                outputFileName_1 = createFilePointer();
                maskInFilePtr(fileNamePtr, outputFileName_1);
                cout << "\n\t���� �������� �����:" << endl;
                readFilePtr(fileNamePtr);
                cout << "\n\t���� ��������� �����:" << endl;
                readFilePtr(outputFileName_1);
            }
            break;
            case 5:
            {
                cout << "�� ������� ����� ����?" << endl;
                outputFileName_2 = createFilePointer();
                longestWordPtr(outputFileName_1, outputFileName_2);
                cout << "\n\t���� �������� �����:" << endl;
                readFilePtr(outputFileName_1);
                cout << "\n\t���� ��������� �����:" << endl;
                readFilePtr(outputFileName_2);
            }
            break;
            case 6:
            {
                cout << "\n\t���� �������� �����:" << endl;
                readFilePtr(fileNamePtr);
                cout << "\n\t���� ��������� �����:" << endl;
                readFilePtr(outputFileName_1);
                cout << "\n\t���� ��������� �����:" << endl;
                readFilePtr(outputFileName_2);
            }
            break;

            }
        }
        break;
    case 2:
    {
        cout << "\n�����! �� �������� ��� ������ � ���������� �������!" << endl;
        while (flag != 0) {
            menu();
            cout << "����� ������ ������ � �������: ";
            cin >> flag;
            switch (flag) {
            case 0:
            {
                flag = 0;
                cout << "����� �� ������!" << endl;
            }
            break;
            case 1:
            {
                createFileStream(fileNameStr);
                appendFileStr(fileNameStr);
                cout << "\n� ���� ������� ����� �����:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 2:
            {
                cout << "����� ����� �����: ";
                cin >> fileNameStr;
                cout << "\n���� �����:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 3:
            {
                cout << "����� ����� �����: ";
                cin >> fileNameStr;
                cout << "\n���� �����:" << endl;
                readFileStr(fileNameStr);
                appendFileStr(fileNameStr);
                cout << "\n��������� ���� �����:" << endl;
                readFileStr(fileNameStr);
            }
            break;
            case 4:
            {
                cout << "�� ������� ����� ����?" << endl;
                createFileStream(outputFile_1);
                maskInFileStr(fileNameStr, outputFile_1);
                cout << "\n\t���� �������� �����:" << endl;
                readFileStr(fileNameStr);
                cout << "\n\t���� ��������� �����:" << endl;
                readFileStr(outputFile_1);
            }
            break;
            case 5:
            {
                cout << "�� ������� ����� ����?" << endl;
                createFileStream(outputFile_2);
                longestWordStr(outputFile_1, outputFile_2);
                cout << "\n\t���� �������� �����:" << endl;
                readFileStr(outputFile_1);
                cout << "\n\t���� ��������� �����:" << endl;
                readFileStr(outputFile_2);
            }
            break;
            case 6:
            {
                cout << "\n\t���� �������� �����:" << endl;
                readFileStr(fileNameStr);
                cout << "\n\t���� ��������� �����:" << endl;
                readFileStr(outputFile_1);
                cout << "\n\t���� ��������� �����:" << endl;
                readFileStr(outputFile_2);
            }
            break;
            }
        }
    }
    break;
    default:
    {
        cout << "�������� ����� ������ � ������!" << endl;
    }
    break;
    }
    }
}

//cd D:\__�������������\��� �������\labaratorna_1\x64\Debug
// -mode FileStream