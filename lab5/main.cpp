/* 
32. Спроектувати клас TFigure, який представляє просторову геометричну фігуру 
з методами обчислення площі її поверхні та об'єму. 
На основі цього класу створити класи-нащадки TPyramid та ТCylinder. 
Створити n пірамід i m циліндрів.
Знайти циліндр з найбільшим об'ємом і піраміду - з найменшою площею поверхні.
*/

#include <iostream>
#include <iomanip>
#include "figure.h"
#include "funFigure.h"

using namespace std;


int main() {
	int n, m;

	cout << "Enter a number of pyramids: ";
	cin >> n;
	cout << "Enter a number of cylinders: ";
	cin >> m;

	TPyramid* pyramids = new TPyramid[n];
	TCylinder* cylinders = new TCylinder[m];
	
	createPyramids(pyramids, n);
	printPyramids(pyramids, n);
	createCylinders(cylinders, m);
	printCylinders(cylinders, m);
	findMaxVCylinder(cylinders, m);
	findMinSPiramid(pyramids, n);
	
	return 0;
}