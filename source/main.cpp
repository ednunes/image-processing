//Main temporaria para fazer teste de metodos 
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "image.hpp"
#include "imageP2.hpp"

int main(int argc, char const *argv[])
{
	Image img;
	ImageP2 imgP2;
	std::fstream fileImage;
	std::string fileName = img.takeNameFile();
	img.openImage(fileImage,fileName);

	img.readHeader(fileImage);
		
	int num = 0;
	num = imgP2.getNumberLinesImage(fileImage);
	img.setNumberLinesImageFile(num);
	
	int* v = NULL;
	v = imgP2.getNumberElementsPerColumnImage(fileImage,num,fileName);
		
	img.setNumberElementsColumnsImageFile(v);
	
	//O problema esta aqui
	int** matrixImage = NULL;
	matrixImage = imgP2.copyImage(fileImage,fileName,img);

	imgP2.writeImage(matrixImage, img);

	std::cout << "Deu certo!!! " << std::endl;

	fileImage.close();
	return 0;
}