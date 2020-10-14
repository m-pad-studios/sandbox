#ifndef TREE_HPP
#define TREE_HPP
#include <functional>
#include "pair_node.hpp"

namespace data_structures
{
	template <class K, class V>
	class ITree
	{
	public:
		virtual ~ITree() = default;
		virtual auto Clear() noexcept -> void = 0;
		virtual auto VisitFunction(const std::function<void(const PairNode<K, V>* node)>& visit) noexcept -> void = 0;
		virtual auto Empty() const noexcept -> bool = 0;
		virtual auto InOrder() const noexcept -> void = 0;
		virtual auto PreOrder() const noexcept -> void = 0;
		virtual auto PostOrder() const noexcept -> void = 0;
		virtual auto BreadthFirst() const noexcept -> void = 0;
		virtual auto Insert(const K& key, const V& value) noexcept(false) -> void = 0;
		virtual auto Remove(const K& key) noexcept(false) -> void = 0;
		virtual auto Search(const K& key) const noexcept(false) -> V = 0;
		virtual auto Search(const K& key) noexcept(false) -> V& = 0;
	};
}

#endif