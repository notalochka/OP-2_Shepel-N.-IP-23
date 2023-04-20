#include <iostream>
#include "class.h"
#include "funClass.h"

using namespace std;

int main() {
    int n;
    cout << "Enter the number of objects to create: ";
    cin >> n;

    Text* texts = new Text[n];
    createText(texts, n);
    printText(texts, n);
    appendText(texts, n);
    printText(texts, n);
    isdigitText(texts, n);
    
    delete[] texts;

    return 0;
}

