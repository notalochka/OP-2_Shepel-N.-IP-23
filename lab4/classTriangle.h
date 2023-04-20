#pragma once
#include <iostream>
#include <cmath>

#ifndef CLASSTRIANGLE
using namespace std;

class Triangle {
	double x1, y1, x2, y2, x3, y3;
public:
	Triangle();
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	Triangle(const Triangle& other) : x1(other.x1), y1(other.y1), x2(other.x2), y2(other.y2), x3(other.x3), y3(other.y3) {}

	double getX1() const;
	double getY1() const;
	double getX2() const;
	double getY2() const;
	double getX3() const;
	double getY3() const;

	void setX1(double newX1);
	void setY1(double newY1);
	void setX2(double newX2);
	void setY2(double newY2);
	void setX3(double newX3);
	void setY3(double newY3);

	Triangle operator ++();
	Triangle operator ++(int value);
	Triangle operator+=(double num);
	void printTriangle(string s);
	double calcPerimeter();
};

void findMaxTriangle(Triangle T1, Triangle T2, Triangle T3);
#endif // !CLASSTRIANGLE
