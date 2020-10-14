#ifndef PRIORITY_ARRAY_DEQUE
#define PRIORITY_ARRAY_DEQUE

#include "array.hpp"



namespace data_structures
{

	template <class T>
	class ArrayDeque
	{
	public:
		explicit ArrayDeque(const size_t& max_size);
		ArrayDeque(const ArrayDeque& copy) noexcept(false);
		ArrayDeque& operator=(const ArrayDeque& rhs) noexcept(false);
		ArrayDeque(ArrayDeque&& copy) noexcept;
		ArrayDeque& operator=(ArrayDeque&& rhs) noexcept;

		void PushFront(const T& item) noexcept(false);
		void PushBack(const T& item) noexcept(false);
		T RemoveFront() noexcept(false);
		T RemoveBack() noexcept(false);
		T Front() const noexcept(false);
		T Back() const noexcept(false);
		bool Full() const noexcept;
		bool Empty() const noexcept;
		void Clear() noexcept;
		size_t Size() const noexcept;

		~ArrayDeque() = default;

	private:
		Array<T> deque_;
		int front;
		int back;

	};


	template<class T>
	 ArrayDeque<T>::ArrayDeque(const size_t& max_size) : deque_(max_size)
	{
		 front = -1;
		 back = 0;
	}

	template<class T>
	 ArrayDeque<T>::ArrayDeque(const ArrayDeque& copy) noexcept(false)
	{
		 *this = copy;
	}
	 
	template<class T>
	ArrayDeque<T>& ArrayDeque<T>::operator=(const ArrayDeque& rhs) noexcept(false)
	{
		 if (this != &rhs)
		 {
			 deque_ = rhs.deque_;
			 front = rhs.front;
			 back = rhs.back;

			 for (auto i = 0u; i < deque_.Length(); ++i)
			 {
				 deque_[i] = rhs.deque_[i];
			 }

			 return *this;
		 }
	}

	template<class T>
	 ArrayDeque<T>::ArrayDeque(ArrayDeque&& copy) noexcept
	{
		 *this = std::move(copy);
	}

	template<class T>
	 ArrayDeque<T>& ArrayDeque<T>::operator=(ArrayDeque&& rhs) noexcept
	{
		 if (this != &rhs)
		 {
			 deque_ = rhs.deque_;
			 front = rhs.front;
			 back = rhs.back;

			 for (auto i = 0u; i < deque_.Length(); ++i)
			 {
				 deque_[i] = rhs.deque_[i];
			 }

			 return *this;
		 }
	}

	template<class T>
	 void ArrayDeque<T>::PushFront(const T& item) noexcept(false)
	{ 
		 if (Full())
		 {
			 return;
		 }

		 if (front == -1)
		 {
			 front = 0;
			 back = 0;
		 }

		 if (front == 0)
		 {
			 front = deque_.Length() - 1;
		 }
		 else
		 {
			 front = front - 1;
		 }

		 deque_[front] = item;
	}

	template<class T>
	 void ArrayDeque<T>::PushBack(const T& item) noexcept(false)
	{
		 if (Full())
		 {
			 return;
		 }
 
		 if (front == -1)
		 {
			 front = 0;
			 back = 0;
		 }
 
		 if (back == Size() - 1)
		 {
			 back = 0;
		 }
 
		 else
		 {
			 back = back + 1;
		 }

		 deque_[back] = item;
	}

	template<class T>
	 T ArrayDeque<T>::RemoveFront() noexcept(false)
	{
		 if (Empty())
		 {
			 return Empty();
		 }

		 if (front == back)
		 {
			 front = -1;
			 back = -1;
		 }
		 else
		 {
			 
			 if (front == Size() - 1)
			 {
				 front = 0;
			 }
			 else 
			 {
				 front = front + 1;
			 }
		 }
	 }

	template<class T>
	 T ArrayDeque<T>::RemoveBack() noexcept(false)
	{
		 if (Empty())
		 {
			 return true;
		 }

		 if (front == back)
		 {
			 front = -1;
			 back = -1;
		 }
		 if (back == 0)
		 {
			 back = Size() - 1;
		 }
		 else
		 {
			 back = back - 1;
		 }
	}

	template<class T>
	 T ArrayDeque<T>::Front() const noexcept(false)
	{
		 if (Empty())
		 {
			 return -1;
		 }
		 return deque_[front];
	}

	template<class T>
	 T ArrayDeque<T>::Back() const noexcept(false)
	{
		if (Empty())
		{
			return -1;
		}
		return deque_[back];
	}

	template<class T>
	 bool ArrayDeque<T>::Full() const noexcept
	{
		 return ((front == 0 && back == Size() - 1) ||
			 front == back + 1);
	}

	template<class T>
	 bool ArrayDeque<T>::Empty() const noexcept
	{
		 return front <= 0 && back <= 0;
	}

	template<class T>
	 void ArrayDeque<T>::Clear() noexcept
	{
		 for (auto i = 0u; i < Size(); ++i)
		 {
	
				 if (front > 0 && front != 0)
				 {
					 RemoveFront();
				 }
				
			 }
		 front = -1;
		 back = -1;
		 
	}

	 template <class T>
	 size_t ArrayDeque<T>::Size() const noexcept
	 {
		 return deque_.Length();
	 }

}

#endif
