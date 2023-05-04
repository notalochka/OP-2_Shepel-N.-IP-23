#pragma once
#include <iostream>
#include <iomanip>
#include "figure.h"

using namespace std;

#ifndef FUNFIGURE

void createPyramids(TPyramid* pyramids, int n);

void printPyramids(TPyramid* pyramids, int n);

void createCylinders(TCylinder* cylinders, int m);

void printCylinders(TCylinder* cylinders, int m);

void findMaxVCylinder(TCylinder* cylinders, int m);

void findMinSPiramid(TPyramid* pyramids, int n);
#endif // !FUNFIGURE