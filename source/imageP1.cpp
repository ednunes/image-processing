#include "imageP1.hpp"

ImageP1::ImageP1(){}

void ImageP1::writeImage(int** imagePixeis, Image &img, const char* outfileName){
	std::ofstream outfile(outfileName);

	outfile << img.getImageType() << std::endl;
	outfile << img.getNumberColumnsHeader() << " " << img.getNumberLinesHeader() << std::endl;
	
	int* numberElementsColumns = img.getNumberElementsColumnsImageFile();
 	for (int i = 0; i < img.getNumberLinesImageFile(); ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			outfile << imagePixeis[i][j] << " ";
		}
		outfile << std::endl;
 	}
 	outfile.close();
}

int** ImageP1::copyImage(std::fstream &file, std::string fileName, Image &img){
	file.close();
	openImage(file,fileName);

	despisesHeader(file,img.getImageType());

	int numberLines = img.getNumberLinesImageFile();
	
	// Array containing the image pixels
	int **imagePixeis = (int**)malloc(numberLines * sizeof(int*));
	int* numberElementsColumns = img.getNumberElementsColumnsImageFile();
	
	for (int ii = 0; ii < numberLines; ii++)
    {
		// Variable for save line string
		std::string text;
	
    	getline(file,text);
	
    	imagePixeis[ii] = (int*) malloc(numberElementsColumns[ii]* sizeof(int));
        
        // Strtol pointer, marks the end of the integer
    	char* ptr_end = NULL;
        // Image pixel
		int elementPixelImage = 0;

        elementPixelImage = strtol(text.c_str(),&ptr_end,10);
        imagePixeis[ii][0] = elementPixelImage;

        for (int jj = 1; jj < numberElementsColumns[ii]; jj++)
        {
            elementPixelImage = strtol(ptr_end,&ptr_end,10);
            imagePixeis[ii][jj] = elementPixelImage;
        }
    }
    return imagePixeis;
}