#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "iiterator.hpp"
#include "adt_exception.hpp"
#include "list_node.hpp"

namespace data_structures
{
	template <class T>
	class ListIterator : public IIterator<T>
	{
	public:
		ListIterator() = default;
		ListIterator(const ListIterator& copy) noexcept;
		explicit ListIterator(ListNode<T>* const copy) noexcept;
		ListIterator(ListIterator&& copy) noexcept;
		ListIterator& operator=(const ListIterator& rhs) noexcept;
		virtual ListIterator& operator=(ListNode<T>* const rhs) noexcept;
		ListIterator& operator=(ListIterator&& rhs) noexcept;

		T& operator*();
		T operator*() const;
		T& Current() override;
		T Current() const override;
		T* operator->();
		T* operator->() const;
		bool Done() const noexcept override;
		operator void* () const noexcept override;

		virtual ~ListIterator() = default;


	protected:
		ListNode<T>* node_ = nullptr;
		bool done_ = true;
	};

	
	template<class T>
	ListIterator<T>::ListIterator(const ListIterator& copy) noexcept
	{
		*this = copy;
	}

	template<class T>
	ListIterator<T>::ListIterator(ListNode<T>* const copy) noexcept
		:node_(copy)
	{ 
		*this = copy;
	}

	template<class T>
	inline ListIterator<T>::ListIterator(ListIterator&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template<class T>
	ListIterator<T>& ListIterator<T>::operator=(const ListIterator& rhs) noexcept
	{
		if (this != &rhs)
		{
			node_ = rhs.node_;
			done_ = rhs.done_;
		}
		return *this;
	}

	template<class T>
	ListIterator<T>& ListIterator<T>::operator=(ListNode<T>* const rhs) noexcept
	{
	
			node_ = rhs;
		
		return *this;
	}

	template<class T>
	ListIterator<T>& ListIterator<T>::operator=(ListIterator&& rhs) noexcept
	{
		if (this != &rhs)
		{
			node_ = rhs.node_;
			done_ = rhs.done_;

			rhs.node_ = nullptr;
		}
		return *this;
	}

	template<class T>
	T& ListIterator<T>::operator*()
	{
		return Current();
	}

	template<class T>
	T ListIterator<T>::operator*() const
	{
		return Current();
	}

	template<class T>
	T& ListIterator<T>::Current()
	{
		if (node_ == nullptr)
		{
			throw AdtException("Iterator is at the end");
		}

		return node_->Value();
	}

	template<class T>
	T ListIterator<T>::Current() const
	{
		if (node_ == nullptr)
		{
			throw AdtException("Iterator is at the end");
		}

		return node_->Value();
	}

	template<class T>
	T* ListIterator<T>::operator->()
	{
		if (done_)
		{
			throw AdtException("Iterator is at the end");
		}

		return &node_;
	}

	template<class T>
	T* ListIterator<T>::operator->() const
	{
		if (done_)
		{
			throw AdtException("Iterator is at the end");
		}

		return &node_;
	}

	template<class T>
	bool ListIterator<T>::Done() const noexcept
	{
		return done_;
	}

	template<class T>
	ListIterator<T>::operator void* () const noexcept
	{
		return static_cast<void*>(*this);
	}

}

#endif // LISTITERATOR_HPP