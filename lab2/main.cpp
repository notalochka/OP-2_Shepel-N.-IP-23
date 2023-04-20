#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cstring>

#include "bin.h"
#include "processBook.h"

using namespace std;

struct Book {
    char title[100];
    char date_written[100];
    int year_published;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inFilename, outFilename;
    cout << "\tВаріант 32" << endl;
    cout << "Створити файл із списком творів автора: назва, дата написання, рік видання (якщо твір не видано, то 0).\nВизначити кількість зимових творів автора.\nПеренести в окремий файл інформацію про твори, написані та видані в минулому столітті.\n" << endl;
    int flag = 1;
    while (flag != 0) {
        menu();
        cin >> flag;
        switch (flag)
        {
        case 0:
        {
            flag = 0;
            cout << "Дякую за роботу!" << endl;
        }break;
        case 1:
        {
            inFilename = createBinaryFile();
            addBookToCatalog(inFilename);
            cout << "\nУ файл доданий такий текст:\n" << endl;
            readCatalog(inFilename);
        }break;
        case 2:
        {
            cout << "\n\tВміст файлу:" << endl;
            readCatalog(inFilename);
            addBookToCatalog(inFilename);
            cout << "\n\tОновлений вміст файлу:" << endl;
            readCatalog(inFilename);
        }break;
        case 3:
        {
            cout << "Як назвати новий файл?" << endl;
            outFilename = createBinaryFile();

            lastCenturyBooks(inFilename, outFilename);
            cout << "\n\tВміст вхідного файлу:" << endl;
            readCatalog(inFilename);
            checkWinterBooks(inFilename);
            cout << "\n\tВміст вихідного файлу:" << endl;
            readCatalog(outFilename);
        }break;
        default:
            break;
        }
    }

    return 0;
}