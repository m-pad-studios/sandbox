#ifndef array_stack_HPP
#define array_stack_HPP

#include "istack.hpp"
#include "array.hpp"
#include "adt_exception.hpp"
namespace data_structures
{

	template <class T>
	class ArrayStack final : public IStack<T>
	{
	public:
		ArrayStack() = default;
		explicit ArrayStack(const size_t& max_size);
		ArrayStack(const ArrayStack& copy);
		ArrayStack& operator=(const ArrayStack& rhs);
		ArrayStack(ArrayStack&& copy) noexcept;
		ArrayStack& operator=(ArrayStack&& rhs) noexcept;
		~ArrayStack() = default;

		T Pop() override;
		T Peek() override;
		void Push(T data) override;
		void DisplayStack();
		bool Full() const noexcept;
		void Clear() noexcept override;
		bool Empty() const noexcept override;
		size_t Size() const noexcept override;
	private:
		Array<T> stack_;
		int top;
	};


	template <class T>
	ArrayStack<T>::ArrayStack(const size_t& max_size) : stack_(max_size)
	{
		if (max_size <= 0)
		{
			throw  AdtException("Can't create a stack of size 0");
		}
		top = -1;
	}

	template <class T>
	ArrayStack<T>::ArrayStack(const ArrayStack& copy)
	{
		*this = copy;
	}

	template <class T>
	ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack& rhs)
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
			top = rhs.top;

			for (auto i = 0u; i < stack_.Length(); ++i)
			{
				stack_[i] = rhs.stack_[i];
			}

			return *this;
		}
	}

	template <class T>
	ArrayStack<T>::ArrayStack(ArrayStack&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack&& rhs) noexcept
	{
		if (this != &rhs)
		{
			stack_ = rhs.stack_;
			stack_.StartIndex() = rhs.StartIndex();

			for (auto i = 0u; i < stack_.Length(); ++i)
			{
				stack_[i] = rhs.storage_[i];
			}

			return *this;
		}
	}

	template <class T>
	T ArrayStack<T>::Pop()
	{
		if (Empty())
		{
			return Empty();
		}
		else
		{
			return stack_[top] = top--;
		}
	}

	template <class T>
	T ArrayStack<T>::Peek()
	{
		if (top < 0) {

			return Empty();
		}
		else {
			int first = stack_[top];
			return first;
		}
	}

	template <class T>
	void ArrayStack<T>::Push(T data)
	{
		//is an array stack like a push pop...ya know those old ice creams. they had like flintstones ones haha :D
		if (Full())
		{
			throw AdtException("List done did gone got itself full here! [it is a tongue twister]");
		}
		if (Empty() || stack_.Length() > 0)
		{
			stack_[++top] = data;
		}
	}

	template <class T>
	void ArrayStack<T>::DisplayStack()
	{
	
		for (auto i = 0u; i < stack_.Length(); ++i)
		{
			std::cout << stack_[i] << std::endl;
		}
	}

	template <class T>
	bool ArrayStack<T>::Full() const noexcept
	{
		return top == Size() - 1 ? true : false;
	}

	template <class T>
	void ArrayStack<T>::Clear() noexcept
	{
		//so this is working properly at least when I debugged it is but idk how to deal with the abort() error that crashes the program. I looked into it a lot and couldn't figure it out.
		if (top == -1)
		{
			Empty();
		}
		
		for (auto i = 0u; i < Size(); ++i)
		{
			if (Size() > 0 && Size() != 0)
			{
				Pop();
			}
		}
		top = -1;
	}

	template <class T>
	bool ArrayStack<T>::Empty() const noexcept
	{
		bool result = top == -1 || top == 0 ? true : false;
		return result;
	}

	template <class T>
	size_t ArrayStack<T>::Size() const noexcept
	{
		return stack_.Length();
	}
}
#endif // array_stack_HPP
