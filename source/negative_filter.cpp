#include "negative_filter.hpp"

// Filter for image type P2
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
// Filter for image type P5
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
// Filter for image type P1
int** NegativeFilter::applyNegativeFilter(int** imagePixeis, int* numberElementsColumns, int numberLines)
{
	int** filter = imagePixeis;
	for (int i = 0; i < numberLines; ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			if (filter[i][j] == 0)
 			{
 				filter[i][j] = 1;
 			} else {
 			 	filter[i][j] = 0;
 			}
		}
 	}
 	return filter;
}