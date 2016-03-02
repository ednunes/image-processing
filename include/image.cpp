#include "image.hpp"

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