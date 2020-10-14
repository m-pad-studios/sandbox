#ifndef array_queue_HPP
#define array_queue_HPP

#include "iqueue.hpp"
#include "array.hpp"

namespace data_structures
{
	template <class T>
	class ArrayQueue final : public IQueue<T>
	{
	public:
		ArrayQueue() = default;
		explicit ArrayQueue(size_t length);
		ArrayQueue(const ArrayQueue& copy);
		ArrayQueue& operator=(const ArrayQueue& rhs);
		ArrayQueue(ArrayQueue&& copy) noexcept;
		ArrayQueue& operator=(ArrayQueue&& rhs) noexcept;

		void Enqueue(T data) override;
		T Dequeue() override;
		T& Front() override;
		bool Full() const noexcept;
		void Clear() noexcept override;
		
		~ArrayQueue() = default;
		size_t Size() const noexcept override;
		bool Empty() const noexcept override;
	private:
		Array<T> queue_;
		int front;
		int back;
	};


	template <class T>
	ArrayQueue<T>::ArrayQueue(size_t length) : queue_(length)
	{
		front = -1;
		back = -1;
	}

	template <class T>
	ArrayQueue<T>::ArrayQueue(const ArrayQueue& copy)
	{
		*this = copy;
	}


	template <class T>
	ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue& rhs)
	{
		if (this != &rhs)
		{
			queue_ = rhs.queue_;
			front = rhs.front;
			back = rhs.back;

			for (auto i = 0u; i < queue_.Length(); ++i)
			{
				queue_[i] = rhs.queue_[i];
			}

			return *this;
		}
	}

	template <class T>
	ArrayQueue<T>::ArrayQueue(ArrayQueue&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue&& rhs) noexcept
	{
		if (this != &rhs)
		{

			queue_ = rhs.stack_;
		    front = rhs.front;
			back = rhs.back;

			for (auto i = 0u; i < queue_.Length(); ++i)
			{
				queue_[i] = rhs.stack_[i];
			}

			return *this;
		}
	}

	template <class T>
	void ArrayQueue<T>::Enqueue(T data)
	{
		
		if (Full())
		{

			throw AdtException("List done did gone got itself full here! [it is a tongue twister]");

		}
		else
		{
			if (front == -1)
				front = 0;
			back++;
			queue_[back] = data;
		}
		////couldn't figure out why it wasn't registering as full
		//if(Empty() || Size() >= 0)
		//{
		//	back = front = 0;
		//}

		//else
		//{
		//	back = (back + 1) % Size();
		//}
		//queue_[back] = data;
	}

	template <class T>
	T ArrayQueue<T>::Dequeue()
	{
		if (Size() == 0)
		{
			return Empty();
		}
		 if(front == back)
		{
		 	//flag system..
			back = front = -1;
		}
		 else
		 {
			 front = (front + 1) % Size();
		 }
	}

	template <class T>
	T& ArrayQueue<T>::Front()
	{
		if(front == -1)
		{
			return back;
		}
		return queue_[front];
	}

	template <class T>
	bool ArrayQueue<T>::Full() const noexcept
	{
		return back == Size() - 1 ? true : false;
	}

	template <class T>
	void ArrayQueue<T>::Clear() noexcept
	{
		for (auto i = 0u; i < Size(); ++i)
		{
			if (Size() > 0 && Size() != 0)
			{
				Dequeue();
			}
		}
		front = -1;
		back = -1;
	}

	template <class T>
	size_t ArrayQueue<T>::Size() const noexcept
	{
		return queue_.Length();
	}

	template <class T>
	bool ArrayQueue<T>::Empty() const noexcept
	{
		return (front == -1 && back == -1);
	}
}
#endif // array_queue_HPP
