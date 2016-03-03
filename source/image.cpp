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

std::string Image::takeNameFile()
{
	// Variable for get file name from user
	std::string fileName;
	std::cout << "Digite o diretorio '/' nome da imagem '.' formato desta: ";
	std::cin >> fileName;
	
	return fileName;
}

void Image::openImage(std::fstream &file, std::string fileName)
{
	 file.open(fileName.c_str());
	
	 if (file.is_open())
	 {
	 
	 } else {
	 	std::cout << "Erro ao abrir o arquivo" << std::endl;
	 	exit(1);
	 }
}

int* Image::getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName)
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

	file.close();
	openImage(file,fileName);

	despisesHeader(file);
	
	for (int i = 0; i < numberLines; ++i)
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

void Image::despisesHeader(std::fstream &file)
{
	std::string text;
	const int numberLinesOfHeader = 3;
	for (int iii = 0; iii < numberLinesOfHeader; ++iii)
	{
		getline(file,text);
		if (text[0] == '#')
		{
			getline(file,text);
		}
	}
}

void Image::writeImage(int** pixeisImage){
	std::ofstream outfile("copy.pgm");

	outfile << getImageType() << std::endl;
	outfile << getNumberColumnsHeader() << " " << getNumberLinesHeader() << std::endl;
	outfile << getMaxLevelGray() << std::endl;
	
	int* numberElementsColumns = getNumberElementsColumnsImageFile();
 	std::cout << numberElementsColumns[0] << " " << numberElementsColumns[1] << std::endl;
 	for (int i = 0; i <= getNumberLinesImageFile(); ++i)
 	{
 		for (int j = 0; j < numberElementsColumns[i]; ++j)
 		{
 			outfile << pixeisImage[i][j] << " ";
		}
		outfile << std::endl;
 	}
 	outfile.close();
}

int** Image::copyImage(std::fstream &file, std::string fileName){
	
	file.close();
	openImage(file,fileName);

	despisesHeader(file);

	int numberLines = getNumberLinesImageFile();

	// Array containing the image pixels
	int **imagePixeis = (int**)malloc(numberLines * sizeof(int*));
	
	int* numberElementsColumns = getNumberElementsColumnsImageFile();
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