#include "funFigure.h"

void createPyramids(TPyramid* pyramids, int n) {
	for (int i = 0; i < n; i++) {
		float bA, h, bL;
		float s;
		cout << "---------------------------------------------------------" << endl;
		cout << "Enter a BASE AREA of pyramid " << i + 1 << ": ";
		cin >> bA;
		cout << "Enter a HEIGHT of pyramid " << i + 1 << ": ";
		cin >> h;
		cout << "Enter a BASE LENTH of pyramid " << i + 1 << ": ";
		cin >> bL;
		cout << "Enter a NUMBER OF SIDES OF THE BASE of pyramid " << i + 1 << ": ";
		cin >> s;
		pyramids[i].setBaseArea(bA);
		pyramids[i].setHeight(h);
		pyramids[i].setBaseLenth(bL);
		pyramids[i].setSides(s);

	}
	cout << "*********************************************************" << endl;
}

void printPyramids(TPyramid* pyramids, int n) {
	for (int i = 0; i < n; i++) {
		cout << setw(10) << "Pyramid " << i + 1 << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "BASE AREA: " << pyramids[i].getBaseArea() << endl;
		cout << "HEIGHT: " << pyramids[i].getHeight() << endl;
		cout << "BASE LENTH: " << pyramids[i].getBaseLenth() << endl;;
		cout << "NUMBER of SIDES of the base: " << pyramids[i].getSides() << endl;
		cout << "S: " << pyramids[i].area() << endl;
		cout << "V: " << pyramids[i].volume() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
}

void createCylinders(TCylinder* cylinders, int m) {
	for (int i = 0; i < m; i++) {
		float r, h;
		cout << "---------------------------------------------------------" << endl;
		cout << "Enter a radius of cylinder " << i + 1 << ": ";
		cin >> r;
		cout << "Enter a height of cylinder " << i + 1 << ": ";
		cin >> h;
		cylinders[i].setRadius(r);
		cylinders[i].setHeight(h);

	}
	cout << "*********************************************************" << endl;
}

void printCylinders(TCylinder* cylinders, int m) {
	for (int i = 0; i < m; i++) {
		cout << setw(10) << "Cylinder " << i + 1 << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << "RADIUS: " << cylinders[i].getRadius() << endl;
		cout << "HEIGHT: " << cylinders[i].getHeight() << endl;
		cout << "S: " << cylinders[i].area() << endl;
		cout << "V: " << cylinders[i].volume() << endl;
		cout << "---------------------------------------------------------" << endl;
	}
}

void findMaxVCylinder(TCylinder* cylinders, int m) {
	int index_max = 0;
	float max_v = cylinders[0].volume();
	for (int i = 1; i < m; i++) {
		float current_v = cylinders[i].volume();
		if (max_v < current_v) {
			index_max = i;
		}
	}
	cout << setw(20) << "Cylinder " << index_max + 1 << " with max V - " << cylinders[index_max].volume() << endl;
	cout << "---------------------------------------------------------" << endl;
}

void findMinSPiramid(TPyramid* pyramids, int n) {
	int index_min = 0;
	float min_s = pyramids[0].volume();
	for (int i = 1; i < n; i++) {
		float current_s = pyramids[i].volume();
		if (min_s > current_s) {
			index_min = i;
		}
	}
	cout << setw(20) << "Piramid " << index_min + 1 << " with min S - " << pyramids[index_min].volume() << endl;
}
