#include "imageP5.hpp"

ImageP5::ImageP5(){}

void ImageP5::writeImage(unsigned char** imagePixeis, Image &img, const char* outfileName){
	std::ofstream outfile(outfileName);

	outfile << img.getImageType() << std::endl;
	outfile << img.getNumberColumnsHeader() << " " << img.getNumberLinesHeader() << std::endl;
	outfile << img.getMaxGrayLevel() << std::endl;
	
	int* numberElementsColumns = img.getNumberElementsColumnsImageFile();
 	int numberLines = img.getNumberLinesImageFile();
 	for (int i = 0; i < numberLines; ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			outfile << imagePixeis[i][j];
		}
 	}
 	outfile.close();
}

unsigned char** ImageP5::copyImage(std::fstream &file, std::string fileName, Image &img){
	file.close();
	openImage(file,fileName);

	despisesHeader(file);

	int numberLines = img.getNumberLinesImageFile();

	int* numberElementsColumns = img.getNumberElementsColumnsImageFile();

	unsigned char** imagePixeis = (unsigned char**)malloc(numberLines * sizeof(unsigned char*));
	for (int ii = 0; ii < numberLines; ii++)
    {	
    	// Variable for save line string
		std::string text;
    	getline(file,text);
        
        imagePixeis[ii] = (unsigned char*) malloc(numberElementsColumns[ii]* sizeof(unsigned char));
        for (int jj = 0; jj < numberElementsColumns[ii]; jj++)
        {
            imagePixeis[ii][jj] = text[jj];
        }
    }
    return imagePixeis;
}