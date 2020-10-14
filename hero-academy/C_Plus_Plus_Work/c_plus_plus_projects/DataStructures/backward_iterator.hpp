#ifndef BACKWARDITERATOR_HPP
#define BACKWARDITERATOR_HPP

#include "list_iterator.hpp"

namespace data_structures
{
	template <class T>
	class BackwardIterator : public ListIterator<T>
	{
	public:
		BackwardIterator() = default;
		~BackwardIterator() = default;
		BackwardIterator(const BackwardIterator& copy) noexcept;
		explicit BackwardIterator(ListNode<T>* const copy) noexcept;
		BackwardIterator(BackwardIterator&& copy) noexcept;
		BackwardIterator& operator=(const BackwardIterator& rhs) noexcept;
		BackwardIterator& operator=(ListNode<T>* const rhs) noexcept override;
		BackwardIterator& operator=(BackwardIterator&& rhs) noexcept;

		bool operator==(const BackwardIterator<T>& rhs) const noexcept;

		void MoveNext() override;
		void Reset() noexcept override;
		BackwardIterator& operator++();
		BackwardIterator operator++(int);
	};

	template <class T>
	BackwardIterator<T>::BackwardIterator(const BackwardIterator& copy) noexcept
		: ListIterator<T>(copy) { }

	template <class T>
	BackwardIterator<T>::BackwardIterator(ListNode<T>* const copy) noexcept
		: ListIterator<T>(copy) { }

	template <class T>
	BackwardIterator<T>::BackwardIterator(BackwardIterator&& copy) noexcept
		: ListIterator<T>(std::move(copy)) { }

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(const BackwardIterator& rhs) noexcept
	{
		if (this != &rhs)
		{
			ListIterator<T>::operator=(rhs);
		}
		return *this;
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
		ListIterator<T>::operator=(rhs);
		ListIterator<T>:: done_ = rhs;
		return *this;
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator=(BackwardIterator&& rhs) noexcept
	{
		if (this != &rhs)
		{
			ListIterator<T>::operator=(std::move(rhs));
		}
		return *this;
	}

	template <class T>
	bool BackwardIterator<T>::operator==(const BackwardIterator<T>& rhs) const noexcept
	{
		return ListIterator<T>::node_ == rhs.node_;
	}

	template <class T>
	void BackwardIterator<T>::MoveNext() noexcept(false)
	{
		if (ListIterator<T>::done_) throw AdtException("Backward Iterator: Can't move any further.");

		(ListIterator<T>::node_->Previous()) ? ListIterator<T>::node_ = ListIterator<T>::node_->Previous() : ListIterator<T>::done_ = true;
	}

	template <class T>
	void BackwardIterator<T>::Reset() noexcept
	{
		if (ListIterator<T>::node_)
		{
			while (ListIterator<T>::node_->Next())
			{
				ListIterator<T>::node_ = ListIterator<T>::node_->Next();
			}

			ListIterator<T>::done_ = false;
		}
	}

	template <class T>
	BackwardIterator<T>& BackwardIterator<T>::operator++() noexcept(false)
	{
		MoveNext();
		return *this;
	}

	template <class T>
	BackwardIterator<T> BackwardIterator<T>::operator++(int) noexcept(false)
	{
		const auto temp = *this;
		MoveNext();
		return temp;
	}

}
#endif // BACKWARDITERATOR_HPP
