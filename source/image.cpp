#include "image.hpp"

Image::Image(){
	imageType = "Sem Tipo";
	numberColumnsHeader = 0;
	numberLinesHeader = 0;
	maxGrayLevel = 0;
	numberElementsColumnsImageFile = NULL;
	numberLinesImageFile = 0; 
}

std::string Image::takeNameFile()
{
	// Variable for get file name from user
	std::string fileName;
	//std::cout << "Digite o diretorio '/' nome da imagem '.' formato desta: ";
	//std::cin >> fileName;

	// Clean buffer
	//char c;
	//while ((c = getchar()) != '\n' && c != EOF);
	
	return "img/oi.pbm";
}


int* Image::getNumberElementsPerColumnImage(std::fstream &file, int numberLines, std::string fileName)
{
	int* numberElementsColumns = new int[numberLines];
	
	// Columns number starts with 1 because it is 0, there is no column
	int numberColumns = 1;
	// Its a counter of caracter of string
	int characterText = 0;
   
	file.close();
	openImage(file,fileName);

	despisesHeader(file,getImageType());
	if (getImageType() == "P2\r" or getImageType() == "P2" or getImageType() == "P1" or getImageType() == "P1\r")
	{
		for (int i = 0; i < numberLines; ++i)
		{
			// Variable for save line string
			std::string text;

			getline(file, text);		
			do{
				// Some images have two spaces between the elements so if this will cause it to recognize the spaces and ignore them
				// And causes them do not count the number of columns.
				// Some of these images is to the end of the string '\r' or '\0'
				// This in consequence would eventually count another value in the amount of lines, because this last term in if this will not happen
				if ((text[characterText]!=' ' and text[characterText+1]==' ') and (text[characterText+2]!='\0' and text[characterText+2]!='\r'))
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
	}
	if (getImageType() == "P5"){
		for (int i = 0; i < numberLines; ++i)
		{
			// Variable for save line string
			std::string text;
			getline(file, text);
			do
			{
				numberColumns++;
			} while(text[numberColumns]!='\0');
		
			numberElementsColumns[i] = numberColumns;
			numberColumns = 0;
		}
	}
	return numberElementsColumns;
}


void Image::openImage(std::fstream &file, std::string fileName)
{
	 file.open(fileName.c_str());
	
	 if (file.is_open())
	 {
	 	// Do nothing
	 } else {
	 	std::cout << "Erro ao abrir o arquivo" << std::endl;
	 	exit(1);
	 }
}

void Image::despisesHeader(std::fstream &file, std::string imageType)
{
	std::string text;
	int numberLinesOfHeader = 0;
	if (imageType != "P1")
	{
		numberLinesOfHeader = 3;
	} else {
		numberLinesOfHeader = 2;
	
	}
	std::cout << "numberLinesOfHeader " << numberLinesOfHeader << " "<< imageType << std::endl;
	 	
	for (int iii = 0; iii < numberLinesOfHeader; ++iii)
	{
		getline(file,text);
		if (text[0] == '#')
		{
			getline(file,text);
		}
	}
}
int Image::getNumberLinesImage(std::fstream &file){
	
	std::string text = "Sem texto";
	int numberLines = 0;
	
	while(getline(file, text))
	{
		numberLines++;
	}
	std::cout << numberLines << std::endl;
	return numberLines;
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
		
		if (getImageType()!="P1")
		{
			// Read max level gray
			getline(fileImage,text);
			int maxGrayLevel = strtol(text.c_str(),&ptr_end,10);
			setMaxGrayLevel(maxGrayLevel);
		}
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

void Image::setMaxGrayLevel(int maxGrayLevel)
{
	this->maxGrayLevel = maxGrayLevel;
}
int Image::getMaxGrayLevel()
{
	return maxGrayLevel;
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