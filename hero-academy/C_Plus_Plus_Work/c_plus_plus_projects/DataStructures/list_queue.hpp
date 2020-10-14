#ifndef list_queue_HPP
#define list_queue_HPP


#include "iqueue.hpp"
#include "linked_list.hpp"

namespace data_structures
{
	template <class T>
	class ListQueue final : public IQueue<T>
	{
	public:
		ListQueue() = default;
		ListQueue(const ListQueue& copy);
		ListQueue& operator=(const ListQueue& rhs);
		ListQueue(ListQueue&& copy) noexcept;
		ListQueue& operator=(ListQueue&& rhs) noexcept;
		~ListQueue() = default;

		void Enqueue(T data) override;
		T Dequeue() override;
		T& Front() override;
		void Clear() noexcept override;
		size_t Size() const noexcept override;
		bool Empty() const noexcept override;
	private:
		LinkedList<T> queue_;

	};

	
	template<class T>
	inline ListQueue<T>::ListQueue(const ListQueue& copy)
	{
		*this = copy;
	}

	template<class T>
	inline ListQueue<T>& ListQueue<T>::operator=(const ListQueue& rhs)
	{
		if (this != &rhs)
		{
			queue_ = rhs.queue_;
		}
		return *this;
	}

	template<class T>
	inline ListQueue<T>::ListQueue(ListQueue&& copy) noexcept
	{
		this = std::move(copy);
	}

	template<class T>
	inline ListQueue<T>& ListQueue<T>::operator=(ListQueue&& rhs) noexcept
	{
		if (this != &rhs)
		{
			queue_ = rhs.queue_;
		}
		return *this;
	}

	template<class T>
	inline void ListQueue<T>::Enqueue(T data)
	{
		queue_.Append(data);
	}

	template<class T>
	inline T ListQueue<T>::Dequeue()
	{
		if (Empty())
		{
			throw AdtException("The queue is already empty");
		}
		else
		{
			queue_.RemoveFirst();
			return queue_.First();
		}
	}

	template<class T>
	inline T& ListQueue<T>::Front()
	{
		if (Empty())
		{
			throw AdtException("The queue is already empty");
		}
		return queue_.First();
	}

	template<class T>
	inline void ListQueue<T>::Clear() noexcept
	{
		queue_.Clear();
	}

	template<class T>
	inline size_t ListQueue<T>::Size() const noexcept
	{
		return queue_.Size();
	}

	template<class T>
	inline bool ListQueue<T>::Empty() const noexcept
	{
		return queue_.Empty();
	}

}
#endif // list_queue_HPP
