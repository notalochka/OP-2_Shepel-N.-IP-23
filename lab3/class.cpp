#include "class.h"

string Text::getText() const {
    return text;
}
void Text::setText(string s) {
    text = s;
}
void Text::appendText(string s) {
    text += s;
}
double Text::percentDigits() {
    int count = 0;
    for (char c : text) {
        if (isdigit(c)) {
            count++;
        }
    }
    return (double)count / text.length() * 100;
}
