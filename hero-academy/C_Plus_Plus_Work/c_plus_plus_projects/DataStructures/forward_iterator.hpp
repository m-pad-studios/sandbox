#ifndef FORWARDITERATOR_HPP
#define FORWARDITERATOR_HPP
#include "list_iterator.hpp"

namespace data_structures
{
	template <class T>
	class ForwardIterator final : public ListIterator<T>
	{
	public:
		ForwardIterator() = default;
		~ForwardIterator() = default;
		ForwardIterator(const ForwardIterator& copy) noexcept;
		explicit ForwardIterator(ListNode<T>* const copy) noexcept;
		ForwardIterator(ForwardIterator&& copy) noexcept;
		ForwardIterator& operator=(const ForwardIterator& rhs) noexcept;
		ForwardIterator& operator=(ListNode<T>* const rhs) noexcept override;
		ForwardIterator& operator=(ForwardIterator&& rhs) noexcept;

		bool operator==(const ForwardIterator& rhs) const noexcept;

		void MoveNext() override;
		void Reset() noexcept override;
		ForwardIterator& operator++();
		ForwardIterator operator++(int);

	};

	template<class T>
	ForwardIterator<T>::ForwardIterator(const ForwardIterator& copy) noexcept
	{
		*this = copy;
	}

	template<class T>
	ForwardIterator<T>::ForwardIterator(ListNode<T>* const copy) noexcept
	{
		ListIterator<T>::node_ = copy; 
		ListIterator<T>::done_ = copy->Next() == nullptr;
	}

	template<class T>
	ForwardIterator<T>::ForwardIterator(ForwardIterator&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template<class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(const ForwardIterator& rhs) noexcept
	{
		if (this != &rhs)
		{
			ListIterator<T>::done_ = rhs.done_;
			ListIterator<T>::node_ = rhs.node_;
		}
		return *this;
	}

	template<class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
		//if (this != &rhs)
		
			ListIterator<T>::node_ = rhs;
			ListIterator<T>::done_ = rhs;
			ListIterator<T>::done_ = rhs->Next() == nullptr;
		
		return *this;
	}

	template<class T>
	ForwardIterator<T>& ForwardIterator<T>::operator=(ForwardIterator&& rhs) noexcept
	{
		if (this != &rhs)
		{
			operator=(rhs.node_);
		}
		return *this;
	}

	template<class T>
	inline bool ForwardIterator<T>::operator==(const ForwardIterator& rhs) const noexcept
	{
		return ListIterator<T>::node_ == rhs.node_ && ListIterator<T>::done_ == rhs.done_;
	}

	template<class T>
	void ForwardIterator<T>::MoveNext()
	{
		// if not done advance pointer to next
		// else throw exception
		if (ListIterator<T>::done_)
		{
			throw AdtException("Already done...");
		}
		else
		{
			ListIterator<T>::node_ = ListIterator<T>::node_->Next();

			ListIterator<T>::done_ = ListIterator<T>::node_->Next() == nullptr;
		}
	}

	template<class T>
	 void ForwardIterator<T>::Reset() noexcept
	{
		 while (ListIterator<T>::node_->Previous() != nullptr)
		 {
			 ListIterator<T>::node_ = ListIterator<T>::node_->Previous();
		 }

		 ListIterator<T>::done_ = false;
	}

	template<class T>
	ForwardIterator<T>& ForwardIterator<T>::operator++()
	{
		MoveNext();

		return *this;
	}

	template<class T>
	ForwardIterator<T> ForwardIterator<T>::operator++(int)
	{
		auto temp = *this;

		MoveNext();

		return temp;
	}

}
#endif