#include "binary.h"

void isValidBinaryFileName(const std::string& filename) {
    if (filename.length() > 4 && filename.length() <= 100) {
        if (filename.substr(filename.length() - 4) == ".bin") {
            for (size_t i = 0; i < filename.length() - 4; ++i) {
                char c = filename[i];
                if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') &&
                    !(c >= '0' && c <= '9') && c != '_') {
                    throw("Некоректні символи у назві файлу " + filename);
                }
            }
        }
        else throw("Неправильне розширення файлу " + filename);
    }
    else throw("Завелика/замала назва файлу " + filename);
}
void isValidDate(const std::string& day, const std::string& month, const std::string& year) {
    bool flag = true;
    if (day.length() <= 2 && month.length() <= 2 && year.length() <= 4) {
        for (size_t i = 0; i < day.length(); ++i) {
            char c = day[i];
            if (!(c >= '0' && c <= '9')) {
                flag = false;
            }
        }
        for (size_t i = 0; i < month.length(); ++i) {
            char c = month[i];
            if (!(c >= '0' && c <= '9')) {
                flag = false;
            }
        }
        for (size_t i = 0; i < year.length(); ++i) {
            char c = year[i];
            if (!(c >= '0' && c <= '9')) {
                flag = false;
            }
        }
        if (flag) {
            int d = stoi(day);
            int m = stoi(month);
            int y = stoi(year);
            if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1900 || y > 2023) {
                flag = false;
            }
        }
    }
    else {
        flag = false;
    }
    if (!flag) {
        throw ("Неправильно введена дата " + day + "." + month + "." + year);
    }
}


void isValidGroup(const std::string& grop) {
    bool flag = true;
    if (grop.length() <= 100) {
        for (size_t i = 0; i < grop.length(); ++i) {
            char c = grop[i];
            if (!(c >= '0' && c <= '9')) {
                throw("Неправильна введена група " + grop);
            }
        }
    }
    else throw("Неправильна введена група " + grop);
}

void createBinaryFile(std::string filename) {
    isValidBinaryFileName(filename);
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (!outFile) {
        throw("Помилка при створенні бінарного файлу " + filename);
    }
    outFile.close();
}

void saveToFile(std::string filename, Students obj) {
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    if (!inFile) {
        throw("Помилка відкриття бінарного файлу " + filename);
    }
    inFile.close();
    isValidBinaryFileName(filename);
    std::fstream file(filename, std::ios::app | std::ios::binary);
    
    file.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
    file.seekp(0, std::ios::end);
    file.close();
}

std::string readFile(const std::string& filename) {
    isValidBinaryFileName(filename);
    std::ifstream inFile(filename, std::ios::in | std::ios::binary);
    if (!inFile) {
        throw("Помилка відкриття бінарного файлу " + filename);
    }

    std::string text = "";

    Students student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        text = text + "Ім'я: " + student.getName() + "\n";
        text = text + "Дата народження: " + std::to_string(student.getDay()) + "." + std::to_string(student.getMonth()) + "." + std::to_string(student.getYear()) + "\n";
        text = text + "Номер групи: " + std::to_string(student.getGroup()) + "\n";
        
    }

    inFile.close();
    return text;
}

void rewriteFile(const std::string& filename1, const std::string& filename2) {
    isValidBinaryFileName(filename1);
    isValidBinaryFileName(filename2);
    std::ifstream inFile(filename1, std::ios::in | std::ios::binary);
    if (!inFile) {
        throw("Помилка відкриття бінарного файлу " + filename1);
    }
    std::ifstream Outfile(filename2, std::ios::in | std::ios::binary);
    if (!Outfile) {
        throw("Помилка відкриття бінарного файлу " + filename2);
    }
    Outfile.close();
    std::fstream file(filename2, std::ios::app | std::ios::binary);
    if (!file) {
        throw("Помилка відкриття бінарного файлу " + filename2);
    }

    Students student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(student))) {
        if (student.isStudentMinor()) {
            file.write(reinterpret_cast<const char*>(&student), sizeof(student));
            file.seekp(0, std::ios::end);
        }
    }
    file.close();
    inFile.close();
}

Students::Students() {
    name[0] = 0;
    day = 0;
    month = 0;
    year = 0;
    group = 0;
}

void Students::setName(const char* n) {
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';
}

void Students::setDate(const std::string& day, const std::string& month, const std::string& year) {
    isValidDate(day, month, year);
    int d = std::stoi(day);
    int m = std::stoi(month);
    int y = std::stoi(year);
    this->day = d;
    this->month = m;
    this->year = y;
}

void Students::setGroup(const std::string& group) {
    isValidGroup(group);
    int g = std::stoi(group);
    this->group = g;
}

const char* Students::getName() const {
    return name;
}

int Students::getDay() const {
    return day;
}

int Students::getMonth() const {
    return month;
}

int Students::getYear() const {
    return year;
}

int Students::getGroup() const {
    return group;
}

bool Students::isStudentMinor() {
    auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    tm* currentDateTime = localtime(&currentTime);
    int currentDay = currentDateTime->tm_mday;
    int currentMonth = currentDateTime->tm_mon + 1;
    int currentYear = currentDateTime->tm_year + 1900;

    int age = currentYear - year;

    if (age < 18) {
        return true;
    }
    else if (age == 18) {
        if (currentMonth < month) {
            return true;
        }
        else if (currentMonth == month && currentDay < day) {
            return true;
        }
    }

    return false;
}