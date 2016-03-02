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
	std::string typeImage;
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

	std::string getTypeImage();
	void setTypeImage(std::string typeImage);
	
};

#endif