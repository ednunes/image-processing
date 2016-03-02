#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class Image
{
private:
	// Type that defines the image
	// Value contained in the header, in first position
	std::string imageType;
	// Number of columns in image
	// Value contained in the header, in second position
	int numberColumnsHeader;
	// Number of lines in image
	// Value contained in the header, in third posistion
	int numberLinesHeader;
	// Number of max level in image
	// Value contained in the header in fourth position
	int maxLevelGray;
	// Number of columns in image file
	// Value to be determined by mapping
	int* numberElementsColumnsImageFile;
	// Number of lines in image
	// Value to be determined by mapping
	int numberLinesImageFile; 
	
public:
	//Image();
	//~Image();


	std::string getImageType();
	void setImageType(std::string imageType);
	
	int getNumberColumnsHeader();
	void setNumberColumnsHeader(int numberColumnsHeader);

	int getNumberLinesHeader();
	void setNumberLinesHeader(int numberLinesHeader);

	int getMaxLevelGray();
	void setMaxLevelGray(int maxLevelGray);

	int getNumberLinesImageFile();
	void setNumberLinesImageFile(int numberLinesImageFile);


};

#endif