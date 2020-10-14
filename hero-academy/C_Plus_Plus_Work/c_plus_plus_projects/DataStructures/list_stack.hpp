#ifndef LIST_STACK_HPP
#define LIST_STACK_HPP

#include "istack.hpp"
#include "linked_list.hpp"
#include "adt_exception.hpp"

namespace data_structures
{
	template <class T>
	class ListStack final : public IStack<T>
	{
	public:
		ListStack() = default;
		ListStack(const ListStack& copy);
		ListStack& operator=(const ListStack& rhs);
		ListStack(ListStack&& copy) noexcept;
		ListStack& operator=(ListStack&& rhs) noexcept;
		~ListStack() = default;

		T Pop() override;
		T Peek() override;
		void Push(T data) override;
		void Clear() noexcept override;
		bool Empty() const noexcept override;
		size_t Size() const noexcept override;
	private:
		LinkedList<T> stack_;

	};


	template<class T>
	 ListStack<T>::ListStack(const ListStack& copy) 
	{
		 *this = copy;
	}

	template<class T>
	ListStack<T>& ListStack<T>::operator=(const ListStack& rhs)
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
		}
		return *this;
	}

	template<class T>
	ListStack<T>::ListStack(ListStack&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template<class T>
	ListStack<T>& ListStack<T>::operator=(ListStack&& rhs) noexcept
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
		}
		return *this;
	}

	template<class T>
	T ListStack<T>::Pop()
	{
	stack_.RemoveFirst();
	return stack_.First();
	}

	template<class T>
	T ListStack<T>::Peek()
	{
		return stack_.First();
	}

	template<class T>
	void ListStack<T>::Push(T data)
	{
		stack_.Prepend(data);
	}

	template<class T>
	void ListStack<T>::Clear() noexcept
	{
		stack_.Clear();
	}

	template<class T>
	bool ListStack<T>::Empty() const noexcept
	{
		return stack_.Empty();
	}

	template<class T>
	size_t ListStack<T>::Size() const noexcept
	{
		return stack_.Size();
	}

}
#endif // list_stack_HPP
