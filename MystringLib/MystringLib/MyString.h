#pragma once
#include <stdio.h>
#include <iterator>
#include <cstddef>
namespace MystringLib
{
	class String {
	public:
		class Iterator
		{
			
		public:
			using iterator_category = std::bidirectional_iterator_tag;
			using difference_type = std::ptrdiff_t;
			using value_type = char;
			using pointer = char*;
			using reference = char&;

			Iterator(pointer ptr) : m_pointer(ptr)
			{

			}

			reference operator*() const { return *m_pointer; }
			pointer operator->() { return m_pointer; }

			// Prefix increment
			Iterator& operator++() { m_pointer++; return *this; }

			// Postfix increment
			Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }



			friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_pointer == b.m_pointer; };
			friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_pointer != b.m_pointer; };

		private:
			pointer m_pointer;
		};
		//Constructor from char array
		String(const char* characters);
		//copy constructor
		String(const String& other);
		//move constructor
		String(String&& other) noexcept;
		//move assignment operator
		String& operator=(String&& other) noexcept;
		String& operator=(const String& other);
		char* c_str() const;
		unsigned int getLength() const;
		void concatenate(const String other);
		void concatenate(const char* characters);
		//internally uses concatenate
		String& operator+=(const String& rhs);
		String& operator+=(const char*& rhs);
		String  operator+(const String& other);
		String  operator+(const char*& other);

		Iterator begin() const { return &charString[0]; }
		Iterator end() const {
			char* temp = &charString[0];
			while (*temp != '\0')
				++temp;
			return temp;
		}
		//conversion function to char*
		operator const char* () const{ return charString; }
		~String();
	private:
		char* charString;

	};
}