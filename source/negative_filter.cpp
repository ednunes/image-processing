#include "negative_filter.hpp"

int** NegativeFilter::applyNegativeFilter(int** imagePixeis, int* numberElementsColumns, int numberLines, int maxGrayLevel)
{
	int** filter = imagePixeis;
	for (int i = 0; i < numberLines; ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			 filter[i][j] = maxGrayLevel - filter[i][j];
		}
 	}
 	return filter;
}
unsigned char** NegativeFilter::applyNegativeFilter(unsigned char** imagePixeis, int* numberElementsColumns, int numberLines, int maxGrayLevel)
{
	unsigned char** filter = imagePixeis;
	for (int i = 0; i < numberLines; ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			 filter[i][j] = maxGrayLevel - filter[i][j];
		}
 	}
 	return filter;
}