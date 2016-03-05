#ifndef IMAGEP5_H
#define IMAGEP5_H
#include "image.hpp"

class ImageP5 : public Image
{
public:
	ImageP5();
//	~imageP2();

// Read file
	unsigned char** copyImage(std::fstream &file,std::string fileName, Image &img);

// Write in file
	void writeImage(unsigned char** imagePixeis, Image &img, const char* outfileName);

};


#endif