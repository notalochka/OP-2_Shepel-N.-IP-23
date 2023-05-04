#include "figure.h"

TPyramid::TPyramid() {
	baseArea = 0;
	height = 0;
	baseLenth = 0;
	sides = 0;
}

void TPyramid::setBaseArea(float newBaseArea) { baseArea = newBaseArea; }
void TPyramid::setHeight(float newHeight) { height = newHeight; }
void TPyramid::setBaseLenth(float newBaseLenth) { baseLenth = newBaseLenth; }
void TPyramid::setSides(float newSides) { sides = newSides; }

float TPyramid::getBaseArea() { return baseArea; }
float TPyramid::getHeight() { return height; }
float TPyramid::getBaseLenth() { return baseLenth; }
float TPyramid::getSides() { return sides; }

float TPyramid::area() {
	return baseArea + sides * (0.5 * baseLenth * height);
}
float TPyramid::volume() {

	return (height * baseArea) / 3;
}


TCylinder::TCylinder() {
	radius = 0;
	height = 0;
}

float TCylinder::getRadius() { return radius; }
float TCylinder::getHeight() { return height; }

void TCylinder::setRadius(float newRadius) { radius = newRadius; }
void TCylinder::setHeight(float newHeight) { height = newHeight; }

float TCylinder::area() {
	return 2 * pi * radius * (height + radius);
}
float TCylinder::volume() {
	return pi * radius * radius * height;
}