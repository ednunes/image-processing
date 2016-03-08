#ifndef NEGATIVE_FILTER_H
#define NEGATIVE_FILTER_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "filter.hpp"

class NegativeFilter : Filter
{
public:
	int** applyNegativeFilter(int** image, int* numberElementsColumns, int numberLines, int maxGrayLevel);
	unsigned char** applyNegativeFilter(unsigned char** image, int* numberElementsColumns, int numberLines, int maxGrayLevel);
	int** applyNegativeFilter(int** image, int* numberElementsColumns, int numberLines);
};

#endif