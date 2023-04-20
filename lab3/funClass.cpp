#include "funClass.h"

void createText(Text* texts, int n) {
    for (int i = 0; i < n; i++) {
        string s = "";
        cout << "Enter text for object " << i + 1 << " (type \"stop\" on a new line to stop):\n";
        while (true) {
            string line;
            getline(cin, line);
            if (line == "stop") {
                break;
            }
            s += line + "\n";
        }
        texts[i].setText(s);
    }
}

void appendText(Text* texts, int n) {
    for (int i = 0; i < n; i++) {
        string addS = "";
        cout << "Do you want to append additional text to object " << i + 1 << " ? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y') {
            cout << "Enter text for object " << i + 1 << " (type \"stop\" on a new line to stop):\n";
            while (true) {
                string addLine;
                getline(cin, addLine);
                if (addLine == "stop") {
                    break;
                }
                addS += addLine + "\n";
            }
            texts[i].appendText(addS);
        }
    }
}


void printText(Text* texts, int n) {
    cout << "\nTexts created with your content!\n\tYour texts are:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Text for object " << i + 1 << ": " << texts[i].getText() << endl;
    }
}

void isdigitText(Text* texts, int n) {
    double smallestPercent = 101;
    int smallestIndex = 0;
    for (int i = 0; i < n; i++) {
        double percent = texts[i].percentDigits();
        if (percent < smallestPercent) {
            smallestPercent = percent;
            smallestIndex = i;
        }
    }

    cout << "Text " << smallestIndex + 1 << " with the smallest percentage of digits:";
    cout << texts[smallestIndex].getText() << endl;
    cout << "Percent of digits: " << smallestPercent << "%" << endl;
}