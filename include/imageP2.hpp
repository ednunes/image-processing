#ifndef IMAGEP2_H
#define IMAGEP2_H
#include "image.hpp"

class ImageP2 : public Image
{
public:
	ImageP2();
//	~imageP2();

// Read file
	int* getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName);
	int** copyImage(std::fstream &file,std::string fileName, Image &img);

// Write in file
	void writeImage(int** pixeisImage, Image &img);
};

#endif