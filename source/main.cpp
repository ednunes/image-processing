//Main temporaria para fazer teste de metodos 
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "image.hpp"
#include "imageP2.hpp"
#include "imageP5.hpp"
#include "filter.hpp"
#include "negative_filter.hpp"

int main(int argc, char const *argv[])
{
	Image img;
	std::fstream fileImage;
	std::string fileName = img.takeNameFile();
	img.openImage(fileImage,fileName);

	img.readHeader(fileImage);
	int num = img.getNumberLinesImage(fileImage);
	img.setNumberLinesImageFile(num);

	NegativeFilter negFilter;
 	if (img.getImageType() == "P5")
	{
		ImageP5 imgP5;
		int* v = img.getNumberElementsPerColumnImage(fileImage,num,fileName);
		img.setNumberElementsColumnsImageFile(v);
		unsigned char** matrixImage = NULL;
		matrixImage = imgP5.copyImage(fileImage,fileName,img);
		imgP5.writeImage(matrixImage, img, "copyP5.pgm");
	
		matrixImage = negFilter.applyNegativeFilter(matrixImage,v,num,img.getMaxGrayLevel());
		imgP5.writeImage(matrixImage, img, "negativep5.pgm");
		
	} else if (img.getImageType() == "P2\r" || img.getImageType() == "P2")
	{
		ImageP2 imgP2;
		int* v = img.getNumberElementsPerColumnImage(fileImage,num,fileName);
		img.setNumberElementsColumnsImageFile(v);
		int** matrixImage = NULL;
		matrixImage = imgP2.copyImage(fileImage,fileName,img);
		imgP2.writeImage(matrixImage, img, "copy1.pgm");

		matrixImage = negFilter.applyNegativeFilter(matrixImage,v,num,img.getMaxGrayLevel());
		imgP2.writeImage(matrixImage, img, "negative1.pgm");
	
	} else {
	 	std::cout << "Formato de imagem: " << img.getImageType() << ", desconhecido!!!" << std::endl;
	}

	std::cout << "Deu certo!!!" << std::endl;

	fileImage.close();
	return 0;
}
	
