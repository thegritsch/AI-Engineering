#include "MyString.h"
#include <string.h>
using namespace MystringLib;

String::String(const char* characters)
{
	unsigned int length = 0;
	while (*(characters + length) != '\0')
	{
		++length;
	}
	this->charString = new char[(unsigned long long)length + 1];
	memcpy(this->charString, characters, sizeof(char) * ((size_t)length + 1));
}

String::String(const String& other)
{
	unsigned int length = other.getLength();
	this->charString = new char[(unsigned long long)length + 1];
	memcpy(this->charString, other.c_str(), length + 1);
}


String::String(String&& other) noexcept
{
	unsigned int length = other.getLength();
	this->charString = new char[(unsigned long long)length + 1];
	memcpy(this->charString, other.c_str(), length + 1);
}

String::~String()
{
	delete[] this->charString;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		unsigned int length = other.getLength();
		this->charString = new char[(unsigned long long)length + 1];
		memcpy(this->charString, other.c_str(), length + 1);
	}
	return *this;
}


String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		unsigned int length = other.getLength();
		this->charString = new char[(unsigned long long)length + 1];
		memcpy(this->charString, other.c_str(), length + 1);
	}
	return *this;
}

String& String::operator+=(const String& other)
{
	concatenate(other);
	return *this;
}

String& String::operator+=(const char*& other)
{
	concatenate(other);
	return *this;
}

String String::operator+(const String& other)
{
	return *this += other;
}

String String::operator+(const char*& other)
{
	return *this += other;
}
void String::concatenate(const char* characters)
{
	unsigned int length = 0;
	while (*(characters + length) != '\0')
	{
		++length;
	}
	unsigned int thisLength = this->getLength();
	unsigned int newLength = thisLength + length;

	char* newString = new char[(unsigned long long)newLength + 1];
	memcpy(newString, this->charString, thisLength);
	memcpy(newString + thisLength, characters, (size_t)length + 1);

	delete[] this->charString;
	this->charString = newString;
}

void String::concatenate(const String other)
{
	concatenate(other.c_str());
}

char *String::c_str() const
{
	return this->charString;
}

unsigned int String::getLength() const
{
	unsigned int length = 0;
	while (*(this->charString + length) != '\0')
	{
		++length;
	}
	return length;
}
