#include "imageP2.hpp"

ImageP2::ImageP2(){}

int* ImageP2::getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName)
{
	int* numberElementsColumns = new int[numberLines];
	
	// Variable for save line string
	std::string text;
	// Columns number starts with 1 because it is 0, there is no column
	int numberColumns = 1;
	// Its a counter of caracter of string
	int characterText = 0;
	// Strtol pointer, marks the end of the integer
    char* ptr_end = NULL;

	file.close();
	openImage(file,fileName);

	despisesHeader(file);

	for (int i = 0; i < numberLines; ++i)
	{
		getline(file, text);		
		strtol(text.c_str(), &ptr_end, 10);	
		do{
			if (text[characterText]!=' ' && text[characterText+1]==' ')
			{
				strtol(ptr_end, &ptr_end, 10);		

				numberColumns++;
				characterText++;

			} else {
				ptr_end = (ptr_end+1);
				characterText++;
				
			}
		} while(text[characterText]!='\0');
		
		numberElementsColumns[i] = numberColumns;
		numberColumns = 1;
		characterText = 0;
	}

	return numberElementsColumns;
}

void ImageP2::writeImage(int** imagePixeis, Image &img, const char* outfileName){
	std::ofstream outfile(outfileName);

	outfile << img.getImageType() << std::endl;
	outfile << img.getNumberColumnsHeader() << " " << img.getNumberLinesHeader() << std::endl;
	outfile << img.getMaxGrayLevel() << std::endl;
	
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

int** ImageP2::copyImage(std::fstream &file, std::string fileName, Image &img){
	file.close();
	openImage(file,fileName);

	despisesHeader(file);

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