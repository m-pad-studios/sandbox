#ifndef PAIR_NODE_HPP
#define PAIR_NODE_HPP

#include "node.hpp"
#include <algorithm>

namespace data_structures
{
	template <class K, class V>
	class PairNode : public Node<V>
	{
	public:
		PairNode() = delete;
		K Key() const noexcept;
		K& Key() noexcept;
		void Key(const K key) noexcept(false);
		virtual ~PairNode() = 0;

	protected:
		PairNode(const K& key, const V& value) noexcept;
		PairNode(const PairNode& copy) noexcept;
		PairNode(PairNode&& copy) noexcept;
		PairNode& operator=(const PairNode& rhs) noexcept;
		PairNode& operator=(PairNode&& rhs) noexcept;

		K key_;
	};


	

}
#endif