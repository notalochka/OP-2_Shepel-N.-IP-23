#pragma once
#include <iostream>
#include <string>
#define pi 3.1415

#ifndef FIGURE
using namespace std;

class TFigure {
public:
	virtual float area() = 0;
	virtual float volume() = 0;
};

class TPyramid : public TFigure {
	float baseArea;
	float height;
	float baseLenth;
	float sides;
public:
	TPyramid();
	
	void setBaseArea(float newBaseArea);
	void setHeight(float newHeight);
	void setBaseLenth(float newBaseLenth);
	void setSides(float newSides);

	float getBaseArea();
	float getHeight();
	float getBaseLenth();
	float getSides();

	float area() override;
	float volume() override;

};

class TCylinder : public TFigure {
	float radius;
	float height;
public:
	TCylinder();

	float getRadius();
	float getHeight();

	void setRadius(float newRadius);
	void setHeight(float newHeight);

	float area() override;
	float volume() override;
};

#endif // !FIGURE

