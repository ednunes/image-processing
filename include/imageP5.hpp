#ifndef IMAGEP5_H
#define IMAGEP5_H
#include "image.hpp"

class ImageP5 : public Image
{
public:
	ImageP5();
//	~imageP2();

// Read file
	int* getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName);
	unsigned char** copyImage(std::fstream &file,std::string fileName, Image &img);

// Write in file
	void writeImage(unsigned char** pixeisImage, Image &img);

};


#endif