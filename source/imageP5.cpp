#include "imageP5.hpp"

ImageP5::ImageP5(){}

int* ImageP5::getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName)
{
	int* numberElementsColumns = new int[numberLines];
	
	// Variable for save line string
	std::string text;
	// Columns number starts with 1 because it is 0, there is no column
	int numberColumns = 1;
   
	file.close();
	openImage(file,fileName);

	despisesHeader(file);
	
	for (int i = 0; i < numberLines; ++i)
	{
		getline(file, text);
		do
		{
			numberColumns++;
		} while(text[numberColumns]!='\0');
	
		numberElementsColumns[i] = numberColumns;
		numberColumns = 0;
	}
	return numberElementsColumns;
}

void ImageP5::writeImage(unsigned char** pixeisImage, Image &img){
	std::ofstream outfile("copy.pgm");

	outfile << img.getImageType() << std::endl;
	std::cout << img.getImageType() << std::endl;

	outfile << img.getNumberColumnsHeader() << " " << img.getNumberLinesHeader() << std::endl;
	std::cout << img.getNumberColumnsHeader() << " " << img.getNumberLinesHeader() << std::endl;

	outfile << img.getMaxLevelGray() << std::endl;
	std::cout << img.getMaxLevelGray() << std::endl;
	
	int* numberElementsColumns = img.getNumberElementsColumnsImageFile();
 	int numberLines = img.getNumberLinesImageFile();
 	for (int i = 0; i < numberLines; ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			outfile << pixeisImage[i][j];
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