//Main temporaria para fazer teste de metodos 
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "image.hpp"
#include "imageP2.hpp"
#include "imageP5.hpp"

int main(int argc, char const *argv[])
{
	Image img;
	std::fstream fileImage;
	std::string fileName = img.takeNameFile();
	img.openImage(fileImage,fileName);

	img.readHeader(fileImage);
	int num = img.getNumberLinesImage(fileImage);
	img.setNumberLinesImageFile(num);
	
	// std::cout << img.getImageType() << std::endl;
 	
  	std::string text = img.getImageType();
	std::cout << text.c_str() << std::endl;
	text.c_str();
  	int teste = 0;
 	int characterText = 0;
	do{
	 	std::cout << text[characterText] << " ";
	 	teste = text[characterText];
	 	std::cout << teste << std::endl;
	 	
	 	characterText++;
	} while(text[characterText]!='\0');

	 

 	if (img.getImageType() == "P5")
	{
		ImageP5 imgP5;
		int* v = imgP5.getNumberElementsPerColumnImage(fileImage,num,fileName);
		img.setNumberElementsColumnsImageFile(v);
		unsigned char** matrixImage = NULL;
		matrixImage = imgP5.copyImage(fileImage,fileName,img);
		imgP5.writeImage(matrixImage, img);
	
	} else if (img.getImageType() == "P2\r" || img.getImageType() == "P2")
	{
		std::cout << "Entrou!!!" << std::endl;

		ImageP2 imgP2;
		int* v = imgP2.getNumberElementsPerColumnImage(fileImage,num,fileName);
		img.setNumberElementsColumnsImageFile(v);
		int** matrixImage = NULL;
		matrixImage = imgP2.copyImage(fileImage,fileName,img);
		imgP2.writeImage(matrixImage, img);
	
	} else {
	 	std::cout << "Formato de imagem " << img.getImageType() << std::endl;
	}

	//std::cout << "Deu certo!!! " << std::endl;

	fileImage.close();
	return 0;
}
	
