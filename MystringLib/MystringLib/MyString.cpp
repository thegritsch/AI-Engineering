#include "MyString.h"
#include <string.h>
using namespace MystringLib;

MyString::MyString(const char* characters)
{
	unsigned int length = 0;
	while (*(characters + length) != '\0')
	{
		++length;
	}
	this->charString = new char[length + 1];
	memcpy(this->charString, characters, sizeof(char) * (length + 1));
}

void MyString::Concatenate(const char* characters)
{
	unsigned int length = 0;
	while (*(characters + length) != '\0')
	{
		++length;
	}
	unsigned int thisLength = this->getLength();
	unsigned int newLength = thisLength + length;

	char* newString = new char[newLength + 1];
	memcpy(newString, this->charString, thisLength);
	memcpy(newString + thisLength, characters, length + 1);

	delete[] this->charString;
	this->charString = newString;
}

void MyString::Concatenate(const MyString other)
{
	Concatenate(other.c_str());
}

char *MyString::c_str() const
{
	return this->charString;
}

unsigned int MyString::getLength() const
{
	unsigned int length = 0;
	while (*(this->charString + length) != '\0')
	{
		++length;
	}
	return length;
}
