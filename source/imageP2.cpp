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

	file.close();
	openImage(file,fileName);

	despisesHeader(file);

	for (int i = 0; i < numberLines; ++i)
	{
		getline(file, text);		
		//strtol(text.c_str(), &ptr_end, 10);	
		do{
			// Some images have two spaces between the elements so if this will cause it to recognize the spaces and ignore them
			// And causes them do not count the number of columns.
			// Some of these images is to the end of the string '\r'
			// This in consequence would eventually count another value in the amount of lines, because this last term in if this will not happen
			if ((text[characterText]!=' ' && text[characterText+1]==' ') && text[characterText+2]!='\r')
			{
				numberColumns++;
				characterText++;	
			}
			 else {
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