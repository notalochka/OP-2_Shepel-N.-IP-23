#define _CRT_SECURE_NO_WARNINGS

#include "bin.h"

using namespace std;


void menu() {
    cout << "\n**********************************************************************************************************" << endl;
    cout << "\t1 = �������� ������� ����" << endl;
    cout << "\t2 = ������ ������� ���� � ����" << endl;
    cout << "\t3 = �������� ��������" << endl;
    cout << "\t0 = �������� ��������" << endl;
    cout << "**********************************************************************************************************" << endl;
    cout << "\n����� ������ ������ � �������: ";
}

string createBinaryFile() {
    string filename;
    cout << "������ ��'� �����: ";
    cin >> filename;
    ofstream outFile(filename, ios::out | ios::binary);
    if (!outFile) {
        cerr << "������� ��� �������� �������� �����." << filename << endl;
        exit(1);
    }
    outFile.close();
    cout << "�������� ���� " << filename << " ������ ��������!" << endl;
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
        cerr << "������� �������� �������� �����. " << filename << endl;
        exit(1);
    }

    int k;
    cout << "\n������ ������� ����: "; cin >> k;
    for (int i = 0; i < k; i++) {
        Book book;
        cout << "\n������ ����� �����: ";
        cin.ignore(); // ���������� ������ ������ ����� � ����� ��������
        cin.getline(book.title, 100);
        cout << "������ ���� ��������� ����� (��������� 10.10.2010): ";
        cin.getline(book.date_written, 100);
        cout << "������ �� �������(���� ��� �� ������, �� - 0): ";
        cin >> book.year_published;

        file.seekp(0, ios::end);
        file.write(reinterpret_cast<const char*>(&book), sizeof(Book));
    }
    file.close();
}

void readCatalog(const string& filename) {
    ifstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cerr << "������� �������� �������� �����. " << filename << endl;
        exit(1);
    }

    Book book;
    char month_str[3];
    while (inFile.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        cout << "�����: " << book.title << endl;
        cout << "���� ���������: " << book.date_written << endl;
        cout << "г� �������: " << book.year_published << endl;
        cout << endl;
    }

    inFile.close();
}
