#define _CRT_SECURE_NO_WARNINGS

#include "bin.h"

using namespace std;


void menu() {
    cout << "\n**********************************************************************************************************" << endl;
    cout << "\t1 = створити бінарний файл" << endl;
    cout << "\t2 = додати каталог книг у файл" << endl;
    cout << "\t3 = виконати завдання" << endl;
    cout << "\t0 = закінчити програму" << endl;
    cout << "**********************************************************************************************************" << endl;
    cout << "\nОбери варіант роботи з файлами: ";
}

string createBinaryFile() {
    string filename;
    cout << "Введіть ім'я файлу: ";
    cin >> filename;
    ofstream outFile(filename, ios::out | ios::binary);
    if (!outFile) {
        cerr << "Помилка при створенні бінарного файлу." << filename << endl;
        exit(1);
    }
    outFile.close();
    cout << "Бінарний файл " << filename << " успішно створено!" << endl;
    return filename;
}

struct Book {
    char title[100];
    char date_written[100];
    int year_published;
};

void addBookToCatalog(const string& filename) {
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Помилка відкриття бінарного файлу. " << filename << endl;
        exit(1);
    }

    int k;
    cout << "\nВведіть кількість книг: "; cin >> k;
    for (int i = 0; i < k; i++) {
        Book book;
        cout << "\nВведіть назву книги: ";
        cin.ignore(); // Пропускаємо символ нового рядка в буфері введення
        cin.getline(book.title, 100);
        cout << "Введіть дату написання книги (наприклад 10.10.2010): ";
        cin.getline(book.date_written, 100);
        cout << "Введіть рік видання(якщо твір не видано, то - 0): ";
        cin >> book.year_published;

        file.seekp(0, ios::end);
        file.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    file.close();
}

void readCatalog(const string& filename) {
    ifstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cerr << "Помилка відкриття бінарного файлу. " << filename << endl;
        exit(1);
    }

    Book book;
    char month_str[3];
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        cout << "Назва: " << book.title << endl;
        cout << "Дата написання: " << book.date_written << endl;
        cout << "Рік видання: " << book.year_published << endl;
        cout << endl;
    }

    inFile.close();
}
