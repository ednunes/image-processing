#include "image.hpp"

Image::Image(){
	imageType = "Sem Tipo";
	numberColumnsHeader = 0;
	numberLinesHeader = 0;
	maxLevelGray = 0;
	numberElementsColumnsImageFile = NULL;
	numberLinesImageFile = 0; 
}

int Image::getNumberLinesImage(std::fstream &file){
	
	std::string text = "Sem texto";
	int numberLines = 0;
	
	while(getline(file, text))
	{
		numberLines++;
	}
	return numberLines;
}

int* Image::getNumberElementsPerColumnImage(std::fstream &file, int numberLines)
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
    // Image pixel
	int elementPixelImage = 0;
	
	for (int i = 0; i <= numberLines; ++i)
	{
		getline(file, text);
		
		elementPixelImage = strtol(text.c_str(), &ptr_end, 10);	
		
		do{
			elementPixelImage = strtol(ptr_end, &ptr_end, 10);		
			if (elementPixelImage)
			{	
				numberColumns++;
			}
			characterText++;

		} while(text[characterText]!='\0');

		numberElementsColumns[i] = numberColumns;
		numberColumns = 1;
		characterText = 0;
	}

	return numberElementsColumns;
}

void Image::readHeader(std::fstream &fileImage){
	// Variable for save line string
	std::string text;
	
	// Read image type and check if is a type valid
	getline(fileImage,text);
	if (text[0] == 'P')
	{	
		setImageType(text);	
		
		// Check if has coments
		getline(fileImage,text);
		if (text[0]=='#')
		{
			getline(fileImage,text);
		}
		else
		{
			//Do nothing
		}
		// Strtol pointer, marks the end of the integer
		char* ptr_end;
		
		int numberColumnImage = strtol(text.c_str(),&ptr_end,10);
		setNumberColumnsHeader(numberColumnImage);
		
		int numberLinesImage = strtol(ptr_end,&ptr_end,10);
		setNumberLinesHeader(numberLinesImage);
		
		// Read max level gray
		getline(fileImage,text);
		int maxLevelGray = strtol(text.c_str(),&ptr_end,10);
		setMaxLevelGray(maxLevelGray);
	
	} else {
		std::cout << "Erro ao ler o cabecalho, formato desconhecido!!!" << std::endl;
	}
}

void Image::setImageType(std::string imageType)
{
	this->imageType = imageType;
}
std::string Image::getImageType()
{
	return imageType;
}

void Image::setNumberColumnsHeader(int numberColumnsHeader)
{
	this->numberColumnsHeader = numberColumnsHeader;
}
int Image::getNumberColumnsHeader()
{
	return numberColumnsHeader;
}

void Image::setNumberLinesHeader(int numberLinesHeader)
{
	this->numberLinesHeader = numberLinesHeader;
}
int Image::getNumberLinesHeader()
{
	return numberLinesHeader;
}

void Image::setMaxLevelGray(int maxLevelGray)
{
	this->maxLevelGray = maxLevelGray;
}
int Image::getMaxLevelGray()
{
	return maxLevelGray;
}

void Image::setNumberLinesImageFile(int numberLinesImageFile)
{
	this->numberLinesImageFile = numberLinesImageFile;
}
int Image::getNumberLinesImageFile()
{
	return numberLinesImageFile;
}

void Image::setNumberElementsColumnsImageFile(int* numberElementsColumnsImageFile)
{
	this->numberElementsColumnsImageFile = numberElementsColumnsImageFile;
}

int* Image::getNumberElementsColumnsImageFile()
{
	return numberElementsColumnsImageFile;
}