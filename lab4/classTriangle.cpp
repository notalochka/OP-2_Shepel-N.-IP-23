#include "classTriangle.h"

Triangle:: Triangle() {
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	x3 = 0;
	y3 = 0;
}

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
}

double Triangle::getX1() const { return x1; }
double Triangle::getY1() const { return y1; }
double Triangle::getX2() const { return x2; }
double Triangle::getY2() const { return y2; }
double Triangle::getX3() const { return x3; }
double Triangle::getY3() const { return y3; }

void Triangle::setX1(double newX1) { x1 = newX1; }
void Triangle::setY1(double newY1) { y1 = newY1; }
void Triangle::setX2(double newX2) { x2 = newX2; }
void Triangle::setY2(double newY2) { y2 = newY2; }
void Triangle::setX3(double newX3) { x3 = newX3; }
void Triangle::setY3(double newY3) { y3 = newY3; }

Triangle Triangle::operator ++() {
	x1++;
	x2++;
	x3++;
	cout << "++Object" << endl;
	return *this;
}

Triangle Triangle::operator ++(int value) {
	Triangle temp = *this;
	y1++;
	y2++;
	y3++;
	cout << "Object++" << endl;
	return temp;
}

Triangle Triangle::operator+=(double num) {
	x1 += num;
	x2 += num;
	x3 += num;
	y1 += num;
	y2 += num;
	y3 += num;
	cout << "Object += " << num << endl;
	return *this;
}
void Triangle::printTriangle(string s) {
	cout << "Coordinates " << s << ": (" << x1 << ", " << y1 << ") (" << x2 << ", " << y2 << ") (" << x3 << ", " << y3 << ")" << endl;
}

double Triangle::calcPerimeter() {
	double side1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double side2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
	double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	return side1 + side2 + side3;
}

void findMaxTriangle(Triangle T1, Triangle T2, Triangle T3) {
	double maxPerimeter = 0;
	Triangle maxTriangle;

	if (T1.calcPerimeter() > maxPerimeter) {
		maxPerimeter = T1.calcPerimeter();
		maxTriangle = T1;
	}

	if (T2.calcPerimeter() > maxPerimeter) {
		maxPerimeter = T2.calcPerimeter();
		maxTriangle = T2;
	}

	if (T3.calcPerimeter() > maxPerimeter) {
		maxPerimeter = T3.calcPerimeter();
		maxTriangle = T3;
	}

	maxTriangle.printTriangle("of max tringle");
	cout << "max Perimeter - " << maxTriangle.calcPerimeter() << endl;
}