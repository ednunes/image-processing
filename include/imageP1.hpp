#ifndef IMAGEP1_H
#define IMAGEP1_H
#include "image.hpp"

class ImageP1 : public Image
{
public:
	ImageP1();
//	~imageP1();

// Read file
	int** copyImage(std::fstream &file,std::string fileName, Image &img);

// Write in file
	void writeImage(int** imagePixeis, Image &img, const char* outfileName);
};

#endif