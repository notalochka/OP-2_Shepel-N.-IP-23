#include <iostream>
#include <string>
#include <Windows.h>
#include "multiset.h"
#include "multiset.cpp"

using namespace std;


void menu();

template<typename T>
void performSetOperations();

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int type;
    cout << "³���!\n��� ������ � �������� ������� ������ ��� ��������\n\t1 = int\n\t2 = float\n\t3 = double\n\t4 = string\n������ �����: ";
    cin >> type;
    if (type == 1) {
        performSetOperations<int>();
    }
    else if (type == 2) {
        performSetOperations<float>();
    }
    else if (type == 3) {
        performSetOperations<double>();
    }
    else if (type == 4) {
        performSetOperations<string>();
    }
    else cout << "��� ������� �����������!" << endl;

    return 0;
}

void menu() {
    cout << "**********************************************************" << endl;
    cout << "������ �������� ��� ���������:" << endl;
    cout << "1 = ��������� ������ �������� � �������" << endl;
    cout << "2 = �������� ������������ �������� ������" << endl;
    cout << "3 = ��������� ����� �������" << endl;
    cout << "4 = ��'������� ���� ������" << endl;
    cout << "5 = ������� �������" << endl;
    cout << "6 = ʳ���� ������" << endl;
    cout << "**********************************************************" << endl;
    cout << "������ ����� ������ � ��������: ";
}

template<typename T>
void performSetOperations() {
    int n;
    cout << "������ ����� �������: ";
    cin >> n;
    Multiset<T> set;
    for (int i = 0; i < n; i++) {
        T value;
        cout << "������ " << i + 1 << " �������: ";
        cin >> value;
        set.insert(value);
    }

    int variant = 0;
    while (variant != 6) {
        menu();
        cin >> variant;
        if (variant == 1) {
            T value;
            cout << "������ �������: ";
            cin >> value;
            set.insert(value);
        }
        else if (variant == 2) {
            T value;
            cout << "������ �������: ";
            cin >> value;
            cout << "����� " << value << ": " << (set.search(value) ? "��������" : "�� ��������") << endl;
        }
        else if (variant == 3) {
            if (!set.empty()) {
                typename Multiset<T>::MultisetIterator it(set.begin());
                while (it != set.end()) {
                    cout << it->data << "; ";
                    ++it;
                }
                cout << it->data << ".";
                cout << endl;
            }
            else cout << "������� �����" << endl;
        }
        else if (variant == 4) {
            int n2;
            cout << "��� ������� ������� �������� ���� �������, � ���� ������ ��'�������� �������" << endl;
            cout << "������ ����� ����� �������: ";
            cin >> n2;
            Multiset<T> set2;
            for (int i = 0; i < n2; i++) {
                T value;
                cout << "������ " << i + 1 << " �������: ";
                cin >> value;
                set2.insert(value);
            }
            Multiset<T> unionSet = set.unionSet(set2);
            cout << "���� ��'������� ������: ";
            typename Multiset<T>::MultisetIterator it(unionSet.begin());
            while (it != unionSet.end()) {
                cout << it->data << "; ";
                ++it;
            }
            cout << it->data << ".";
            cout << endl;
            string saveToFirst;
            cout << "������ �������� ��� ��'������ ������� � ����� �������?\n������ ��� ��� Ͳ: "; cin >> saveToFirst;
            if (saveToFirst == "YES" || saveToFirst == "Yes" || saveToFirst == "yes" || saveToFirst == "���" || saveToFirst == "���" || saveToFirst == "���") {
                set = unionSet;
            }
            unionSet.clear();
            set2.clear();
        }
        else if (variant == 5) {
            if (!set.empty()) {
                set.clear();
                cout << "������� �������" << endl;
            }
            else cout << "������� ��� � ������!" << endl;
        }
    }
    if (!set.empty()) set.clear();
}