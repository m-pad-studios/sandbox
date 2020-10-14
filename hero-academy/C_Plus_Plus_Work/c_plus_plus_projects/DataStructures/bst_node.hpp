#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include "pair_node.hpp"

namespace data_structures
{
	template <class K, class V>
	class BstNode final : public PairNode<K, V>
	{
	public:
		BstNode(const K& key, const V& value, BstNode<K, V>* left = nullptr, BstNode<K, V>* right = nullptr);
		~BstNode() = default;
		BstNode(const BstNode& copy) noexcept;
		BstNode& operator=(const BstNode& rhs) noexcept;
		BstNode(BstNode&& copy) noexcept;
		BstNode& operator=(BstNode&& rhs) noexcept;
		BstNode*& Left() noexcept;
		BstNode*& Right() noexcept;
		BstNode* Left() const noexcept;
		BstNode* Right() const noexcept;
		void Left(BstNode* const left) noexcept;
		void Right(BstNode* const right) noexcept;

	private:
		BstNode* left_ = nullptr;
		BstNode* right_ = nullptr;
	};


	
}
#endif