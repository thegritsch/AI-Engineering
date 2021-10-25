#pragma once
#include <stdio.h>

namespace MystringLib
{
	class MyString {
	public:
		MyString(const char *characters);
		char* c_str() const;
		unsigned int getLength() const;
		void Concatenate(const MyString other);
		void Concatenate(const char* characters);
	private:
		char* charString;

	};
}