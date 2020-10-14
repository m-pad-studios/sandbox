#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include "adt_exception.hpp"
#include "list_node.hpp"
#include "forward_iterator.hpp"
#include "backward_iterator.hpp"


namespace data_structures
{
	template <class T>
	class LinkedList final
	{
	public:
		LinkedList() = default;
		LinkedList(const LinkedList& copy);
		LinkedList(LinkedList&& copy) noexcept;
		~LinkedList();

		LinkedList& operator=(const LinkedList& rhs);
		LinkedList& operator=(LinkedList&& rhs) noexcept;

		explicit operator bool() const;

		void Append(const T& data);
		void Prepend(const T& data);
		void RemoveLast();
		void RemoveFirst();
		void Extract(const T& data);
		void InsertAfter(const T& data, const T& after);
		void InsertBefore(const T& data, const T& before);
		void Clear() noexcept;
		T& Last();
		T Last() const;
		T& First();
		T First() const;
		ListNode<T>* Head() const noexcept;
		ListNode<T>* Tail() const noexcept;
		bool Empty() const noexcept;
		size_t Size() const noexcept;

		bool operator==(const LinkedList<T>& rhs) const noexcept;

		ForwardIterator<T> ForwardBegin();
		ForwardIterator<T> ForwardEnd();
		BackwardIterator<T> BackwardBegin();
		BackwardIterator<T> BackwardEnd();


	private:
		ListNode<T>* head_ = nullptr;
		ListNode<T>* tail_ = nullptr;
		size_t size_ = 0;
	};


	template <class T>
	LinkedList<T>::LinkedList(const LinkedList& copy)
	{
		*this = copy;
	}

	template <class T>
	LinkedList<T>::LinkedList(LinkedList&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	LinkedList<T>::~LinkedList()
	{
		Clear();
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs)
	{
		if (this != &rhs)
		{
			Clear();
			for (auto current = rhs.head_; current != nullptr; current = current->Next())
			{
				Append(current->Value());
			}
		}
		return *this;
	}

	template <class T>
	LinkedList<T>& LinkedList<T>::operator=(LinkedList&& rhs) noexcept
	{
		if (this != &rhs)
		{
			Clear();
			head_ = rhs.head_;
			tail_ = rhs.tail_;
			size_ = rhs.size_;

			rhs.head_ = nullptr;
			rhs.tail_ = nullptr;
		}
		return *this;
	}

	template <class T>
	LinkedList<T>::operator bool() const
	{
		return Empty();
	}

	template <class T>
	void LinkedList<T>::Append(const T& data)
	{

		ListNode<T>* new_node = new ListNode<T>(data);
	
		if (Empty())
		{
			head_ = tail_ = new_node;

		}
		else if (head_ == tail_) // 1 element
		{
			head_->Next(new_node);
			tail_ = new_node;
			tail_->Previous(head_);

		}
		else
		{
			tail_->Next(new_node);
			tail_->Next()->Previous(tail_);
			tail_ = new_node;
		}
	
		++size_;

	}

	template <class T>
	void LinkedList<T>::Prepend(const T& data)
	{
		ListNode<T>* new_node = new ListNode<T>(data);

		if (Empty())
		{
			head_ = tail_ = new_node;
		}
		else
		{
			new_node->Next(head_);
			head_->Previous(new_node);
			head_ = new_node;
		}
		++size_;
	}

	template <class T>
	void LinkedList<T>::RemoveLast()
	{
		if (Empty())
		{
			throw AdtException("The list is empty");
		}

		if (tail_->Next() != nullptr)
		{
			delete tail_;
			head_ = tail_ = nullptr;
		}
		else
		{
			auto the_tail = tail_;
			tail_ = tail_->Previous();
			tail_->Next(nullptr);

			delete the_tail;
			
		}
		--size_;
	}

	template <class T>
	void LinkedList<T>::RemoveFirst()
	{
		if (Empty())
		{
			throw AdtException("The list is empty");
		}

		if (head_->Next() == nullptr)
		{
			delete head_;
			head_ = tail_ = nullptr;
		}
		else
		{
		
		auto the_head = head_;
			head_ = head_->Next();
			head_->Previous(nullptr);
			delete the_head;
		}
		--size_;
	}

	template <class T>
	void LinkedList<T>::Extract(const T& data)
	{
		
		ListNode<T>* node = head_;

		for (; node != nullptr && node->Value() != data; node = node->Next())
		{ }
			if (node == nullptr)
			{
				throw AdtException("Not found");
			}
			if (node == head_)
			{
				RemoveFirst();
			}
			else if (node == tail_)
			{
				RemoveLast();
			}

			else
			{
				auto node_copy = node;
				
				node->Previous()->Next(node->Next());
				node->Next()->Previous(node->Previous());

				delete node_copy;
				--size_;
			}
		
	}

	template <class T>
	void LinkedList<T>::InsertAfter(const T& data, const T& after)
	{
		if (Empty())
			throw AdtException("The list is empty");

		for (ListNode<T>* current = head_; current->Next() != nullptr; current = current->Next())
		{

			if (current->Value() == after)
			{
			
				if (current == head_)
				{
					Append(data);		
				}

				else
				{
					auto new_node = new ListNode<T>(data);
					auto previous_node = current->Previous();

					current->Previous(new_node);

					new_node->Next(current);
					new_node->Previous(previous_node);

					previous_node->Next(new_node);	
					++size_;
				}
			}
		}
	}

	template <class T>
	void LinkedList<T>::InsertBefore(const T& data, const T& before)
	{
		if (Empty())
			throw AdtException("The list is empty");

		for (auto current = head_; current != nullptr; current = current->Next())
		{
			if (current->Value() == before)
			{
				if (current == head_)
				{
					Prepend(data);
				}
				else
				{
					auto new_node = new ListNode<T>(data);

					auto previous_node = current->Previous();

					current->Previous(new_node);

					new_node->Next(current);
				
					previous_node->Next(new_node);
					++size_;
				}
			}
		}
	}

	template <class T>
	void LinkedList<T>::Clear() noexcept
	{
		ListNode<T>* current = head_;

		while(current != nullptr)
		{
			ListNode<T>* next = current->Next();
			delete current;
			current = next;
		}

		head_ = tail_ = nullptr;
		size_ = 0;
		
	}

	template <class T>
	T& LinkedList<T>::Last()
	{
		if (tail_ == nullptr) throw AdtException("Head is nullptr");
		return tail_->Value();
	}

	template <class T>
	T LinkedList<T>::Last() const
	{
	
		return tail_->Value();
	}

	template <class T>
	T& LinkedList<T>::First()
	{
	
		return head_->Value();
	}

	template <class T>
	T LinkedList<T>::First() const
	{
		
		return head_->Value();
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Head() const noexcept
	{
		return head_;
	}

	template <class T>
	ListNode<T>* LinkedList<T>::Tail() const noexcept
	{
		return tail_;
	}

	template <class T>
	bool LinkedList<T>::Empty() const noexcept
	{
		return head_ == nullptr;
	}

	template <class T>
	size_t LinkedList<T>::Size() const noexcept
	{
		return size_;
	}

	template <class T>
	bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const noexcept
	{
		if (size_ == rhs.Size())
		{
			for (ListNode<T>* lhs_current = head_, rhs_current = rhs.head_; lhs_current != nullptr && rhs_current != nullptr; lhs_current = lhs_current->Next(), rhs_current = rhs_current->Next())
			{
				if (lhs_current->Value() != rhs_current->Value())
				{
					return false;
			
				}
				return true;
			}
			return false;
		}
		
	}

	template<class T>
	ForwardIterator<T> LinkedList<T>::ForwardBegin()
	{
		return ForwardIterator<T> (head_);
	}
	template<class T>
	ForwardIterator<T> LinkedList<T>::ForwardEnd()
	{
		return ForwardIterator<T> (tail_);
	}
	template<class T>
	BackwardIterator<T> LinkedList<T>::BackwardBegin()
	{
		return BackwardIterator<T> (tail_);
	}
	template<class T>
	BackwardIterator<T> LinkedList<T>::BackwardEnd()
	{
		return BackwardIterator<T> (head_);
	}
}
#endif