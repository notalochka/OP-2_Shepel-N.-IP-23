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
    cout << "Вітаю!\nДля роботи з множиною потрібно ввести тип елементів\n\t1 = int\n\t2 = float\n\t3 = double\n\t4 = string\nВведіть число: ";
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
    else cout << "Тип введено неправильно!" << endl;

    return 0;
}

void menu() {
    cout << "**********************************************************" << endl;
    cout << "Можливі операції над множинами:" << endl;
    cout << "1 = Включення нового елемента в множину" << endl;
    cout << "2 = Перевірка приналежності елемента множині" << endl;
    cout << "3 = Виведення даних множини" << endl;
    cout << "4 = Об'єднання двох множин" << endl;
    cout << "5 = Очистка множини" << endl;
    cout << "6 = Кінець роботи" << endl;
    cout << "**********************************************************" << endl;
    cout << "Введіть режим роботи з множиною: ";
}

template<typename T>
void performSetOperations() {
    int n;
    cout << "Введіть розмір множини: ";
    cin >> n;
    Multiset<T> set;
    for (int i = 0; i < n; i++) {
        T value;
        cout << "Введіть " << i + 1 << " елемент: ";
        cin >> value;
        set.insert(value);
    }

    int variant = 0;
    while (variant != 6) {
        menu();
        cin >> variant;
        if (variant == 1) {
            T value;
            cout << "Введіть елемент: ";
            cin >> value;
            set.insert(value);
        }
        else if (variant == 2) {
            T value;
            cout << "Введіть елемент: ";
            cin >> value;
            cout << "Пошук " << value << ": " << (set.search(value) ? "Знайдено" : "Не знайдено") << endl;
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
            else cout << "Множина пуста" << endl;
        }
        else if (variant == 4) {
            int n2;
            cout << "Для початку потрібно створити нову множину, з якою будемо об'єднувати множини" << endl;
            cout << "Введіть розмір другої множини: ";
            cin >> n2;
            Multiset<T> set2;
            for (int i = 0; i < n2; i++) {
                T value;
                cout << "Введіть " << i + 1 << " елемент: ";
                cin >> value;
                set2.insert(value);
            }
            Multiset<T> unionSet = set.unionSet(set2);
            cout << "Вміст об'єднаних вершин: ";
            typename Multiset<T>::MultisetIterator it(unionSet.begin());
            while (it != unionSet.end()) {
                cout << it->data << "; ";
                ++it;
            }
            cout << it->data << ".";
            cout << endl;
            string saveToFirst;
            cout << "Бажаєте зберегти дані об'єднаної множини в першу множину?\nВведіть ТАК або НІ: "; cin >> saveToFirst;
            if (saveToFirst == "YES" || saveToFirst == "Yes" || saveToFirst == "yes" || saveToFirst == "ТАК" || saveToFirst == "так" || saveToFirst == "Так") {
                set = unionSet;
            }
            unionSet.clear();
            set2.clear();
        }
        else if (variant == 5) {
            if (!set.empty()) {
                set.clear();
                cout << "Множина очищена" << endl;
            }
            else cout << "Множина вже є пустою!" << endl;
        }
    }
    if (!set.empty()) set.clear();
}