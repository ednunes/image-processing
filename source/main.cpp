//Main temporaria para fazer teste de metodos 
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "image.hpp"


int main(int argc, char const *argv[])
{
	Image img;

	std::fstream fileImage;
	std::string fileName = img.takeNameFile();
	img.openImage(fileImage,fileName);

	img.readHeader(fileImage);
		
	int num = 0;
	num = img.getNumberLinesImage(fileImage);
	img.setNumberLinesImageFile(num);
	
	int* v = NULL;
	v = img.getNumberElementsPerColumnImage(fileImage,num,fileName);
	img.setNumberElementsColumnsImageFile(v);
	
	
	int** matrixImage = NULL;
	matrixImage = img.copyImage(fileImage,fileName);

	img.writeImage(matrixImage);

	fileImage.close();
	return 0;
}