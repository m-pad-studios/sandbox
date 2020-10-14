#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "adt_exception.hpp"

namespace data_structures
{
	template <class T>
	class Array final
	{
	public:
		explicit Array() = default;
		~Array();
		explicit Array(const size_t& length, const int& start_index = 0) noexcept(false);
		explicit Array(const T* storage, const size_t& length, const int& start_index = 0) noexcept(false);

		Array(const Array& copy) noexcept(false);
		Array& operator=(const Array& rhs) noexcept(false);
		Array(Array&& copy) noexcept;
		Array& operator=(Array&& rhs) noexcept;

		T& operator[](const int& index) noexcept(false);
		T operator[](const int& index) const noexcept(false);
		explicit operator bool() const noexcept;

		bool operator==(const Array<T>& rhs) noexcept;

		int StartIndex() const noexcept;
		size_t Length() const noexcept;

		void StartIndex(const int& start_index) noexcept;
		void Length(const size_t& length) noexcept(false);

	private:
		T* storage_{ nullptr };
		size_t length_{ 0 };
		int start_index_{ 0 };
		

		T* AllocateStorage(const size_t& length_);
	
	};


	template <class T>
	Array<T>::~Array()
	{
		delete[] storage_;
	}

	template <class T>
	Array<T>::Array(const size_t& length, const int& start_index) noexcept(false)
	{
		length_ = length;
		start_index_ = start_index;

		storage_ = AllocateStorage(length_);
	}

	template <class T>
	Array<T>::Array(const T* storage, const size_t& length, const int& start_index) noexcept(false)
	{
		length_ = length;
		start_index_ = start_index;

		storage_ = AllocateStorage(length_);

		for (auto i = 0u; i < length_; ++i)
		{
			storage_[i] = storage[i];
		}
	}

	template <class T>
	Array<T>::Array(const Array& copy) noexcept(false)
	{
		*this = copy;
	}

	template <class T>
	Array<T>& Array<T>::operator=(const Array& rhs) noexcept(false)
	{
		if (this != &rhs)
		{
			delete[] storage_;
			
			length_ = rhs.Length();
			start_index_ = rhs.StartIndex();

			storage_ = AllocateStorage(length_);

			for (auto i = 0u; i < length_; ++i)
			{
				storage_[i] = rhs.storage_[i];
			}

			return *this;
		}

	}

	template <class T>
	Array<T>::Array(Array&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	Array<T>& Array<T>::operator=(Array&& rhs) noexcept
	{
		if (this != &rhs)
		{
			delete[] storage_;
			
			length_ = rhs.Length();
			start_index_ = rhs.StartIndex();

			storage_ = rhs.storage_;

			rhs.storage_ = nullptr;
		}
		return *this;
	}

	template <class T>
	T& Array<T>::operator[](const int& index) noexcept(false)
	{
		const auto actual_index = index - start_index_;

		if (actual_index >= length_ || actual_index < 0)
		{
			throw AdtException("Out of bounds!");
		}
		return storage_[actual_index];
		
	}
	//Couldn't figure out how to un-duplicate this code here...I thought you did it in class
	//With the lambda const auto should_throw = [&] but I can't remember
	template <class T>
	T Array<T>::operator[](const int& index) const noexcept(false)
	{
		const auto actual_index = index - start_index_;

		if (actual_index >= length_ || actual_index < 0)
		{
			throw AdtException("Out of bounds!");
		}
		return storage_[actual_index];
	}

	template <class T>
	Array<T>::operator bool() const noexcept
	{
		return length_ > 0;
	}

	template <class T>
	bool Array<T>::operator==(const Array<T>& rhs) noexcept
	{
		if (length_ != rhs.Length() || start_index_ != rhs.StartIndex())
		{
			return false;
		}
		
		for (auto i = 0u; i < length_; ++i)
		{
			if (storage_[i] != rhs[i])
			{
				return false;
			}
			
		}
		return true;
	}

	template <class T>
	int Array<T>::StartIndex() const noexcept
	{
		return start_index_;
	}

	template <class T>
	size_t Array<T>::Length() const noexcept
	{
		return length_;
	}

	template <class T>
	void Array<T>::StartIndex(const int& start_index) noexcept
	{
		start_index_ = start_index;
	}

	template <class T>
	void Array<T>::Length(const size_t& length) noexcept(false)
	{
		T * temp_storage = AllocateStorage(length);
		size_t smaller_length = length_ < length ? length_ : length;
		
		for(auto i = 0u; i < smaller_length; ++i)
		{
			temp_storage[i] = storage_[i];
		}

		delete[] storage_;
		
		storage_ = temp_storage;
		
		length_ = length;
	}

	template <class T>
	T* Array<T>::AllocateStorage(const size_t& length)
	{
		T* storage = nullptr;
		try
		{
			storage = new T[length] {};
		}
		catch (const std::bad_alloc & exception)
		{
			throw(AdtException(exception.what()));
		}
		return storage;
	}
}

#endif
