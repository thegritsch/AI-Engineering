#pragma once
namespace MyUniquePtr
{
	template <class T>
	class UniquePtr
	{
	private:
		T* ptr = nullptr;

	public:
		UniquePtr() : ptr(nullptr) // default constructor
		{
		}

		UniquePtr(T* ptr) : ptr(ptr)
		{
		}

		UniquePtr(const UniquePtr& obj) = delete; // copy constructor is deleted
		UniquePtr& operator=(const UniquePtr& obj) = delete; // copy assignment is deleted

		UniquePtr(UniquePtr&& dyingObj) // move constructor
		{

			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}

		void operator=(UniquePtr&& dyingObj) // move assignment
		{
			cleanup(); // cleanup any existing dataS

			// Transfer ownership of the memory pointed by dyingObj to this object
			this->ptr = dyingObj.ptr;
			dyingObj.ptr = nullptr;
		}

		T* operator->() // deferencing arrow operator
		{
			return this->ptr;
		}

		T& operator*()
		{
			return *(this->ptr);
		}

		T* Release()
		{
			this->ptr = nullptr;
			return this->ptr;
		}

		void Reset()
		{
			delete this->ptr;
			this->ptr = nullptr;
		}

		void swap(T* other)
		{
			cleanup();
			this->ptr = other;
		}
		~UniquePtr() // destructor
		{
			cleanup();
		}

	private:
		void cleanup()
		{
			if (ptr != nullptr)
				delete ptr;
		}
	};
}

