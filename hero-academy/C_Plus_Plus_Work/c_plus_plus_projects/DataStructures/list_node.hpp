#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

#include "node.hpp"

namespace data_structures
{
	template <class T>
	class ListNode : public Node<T>
	{
	public:
		ListNode() = delete;
		explicit ListNode(const T& data, ListNode<T>* next = nullptr, ListNode<T>* previous = nullptr);
		ListNode(const ListNode<T>& copy);
		ListNode<T>& operator=(const ListNode<T>& rhs);

		ListNode(ListNode<T>&& copy) noexcept;
		ListNode<T>& operator=(ListNode<T>&& rhs) noexcept;

		ListNode<T>* Next() noexcept;
		ListNode<T>* Next() const noexcept;
		ListNode<T>* Previous() noexcept;
		ListNode<T>* Previous() const noexcept;

		void Next(ListNode<T>* const next) noexcept;
		void Previous(ListNode<T>* const previous) noexcept;

		~ListNode() = default;
	private:
		ListNode<T>* next_{ nullptr };
		ListNode<T>* previous_{ nullptr };
	};

	template <class T>
	ListNode<T>::ListNode(const T& data, ListNode<T>* next, ListNode<T>* previous)
		:Node<T>(data), next_(next), previous_(previous)
	{
	}

	template <class T>
	ListNode<T>::ListNode(const ListNode<T>& copy)
	{
		*this = copy;
	}

	template <class T>
	ListNode<T>& ListNode<T>::operator=(const ListNode<T>& rhs)
	{
		if (this != &rhs)
		{
			Node<T>::Value(rhs.value_);
			next_ = rhs.next_;
			previous_ = rhs.previous_;
		}
		return *this;
	}

	template <class T>
	ListNode<T>::ListNode(ListNode<T>&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	ListNode<T>& ListNode<T>::operator=(ListNode<T>&& rhs) noexcept
	{
		if (this != &rhs)
		{
			Node<T>::Value(rhs.value_);
			next_ = rhs.next_;
			previous_ = rhs.previous_;
		}
		return *this;
	}

	template <class T>
	ListNode<T>* ListNode<T>::Next() noexcept
	{
		return next_;
	}

	template <class T>
	ListNode<T>* ListNode<T>::Next() const noexcept
	{
		return next_;
	}

	template <class T>
	ListNode<T>* ListNode<T>::Previous() noexcept
	{
		return previous_;
	}

	template <class T>
	ListNode<T>* ListNode<T>::Previous() const noexcept
	{
		return previous_;
	}

	template <class T>
	void ListNode<T>::Next(ListNode<T>* const next) noexcept
	{
		next_ = next;
	}

	template <class T>
	void ListNode<T>::Previous(ListNode<T>* const previous) noexcept
	{
		previous_ = previous;
	}
}
#endif
