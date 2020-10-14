#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <vector>
#include <list>
#include <functional>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <thread>

using std::list;
using std::vector;
using std::function;
using std::move;
using std::pair;
using std::cout;
#include "adt_exception.hpp"

namespace data_structures
{


	template <class K, class V>
	class HashMap final
	{
	public:
		HashMap() = delete;
		HashMap(const size_t& table_size, const function<int(K key)>& hash_function);

		HashMap(const HashMap& copy);
		auto operator=(const HashMap& rhs) -> HashMap&;

		HashMap(HashMap&& copy) noexcept;
		auto operator=(HashMap&& rhs) noexcept -> HashMap&;

		~HashMap() = default;

		auto Insert(const K& key, const V& value) -> void;
		auto HashFunction(const function<int(const K& key)>& hash) -> void;
		auto operator [](const K& key) -> V&;
		auto operator [](const K& key) const -> V;
		auto Remove(const K& key) -> void;
		auto Traverse(const function<void(const K& key, const V& value)>& visit) const -> void;
		auto Contains(const K& key) -> bool;
		auto Count() const -> size_t;

		auto GetOrAdd(const K& key, const function<V()>& create_function) -> V&;


	private:
		vector<list<pair<K, V>>> buckets_;
		function<int(K key)> hash_function_ {nullptr};
		size_t size_{};

	};

	
	template<class K, class V>
	HashMap<K, V>::HashMap(const size_t& table_size, const function<int(K key)>& hash_function) : buckets_(table_size), hash_function_(hash_function)
	{
	}

	template<class K, class V>
	HashMap<K, V>::HashMap(const HashMap& copy)
	{
		*this = copy;
	}

	template<class K, class V>
	auto HashMap<K, V>::operator=(const HashMap& rhs) -> HashMap&
	{
		if (this != &rhs)
		{
			hash_function_ = rhs.hash_function_;
			buckets_ = rhs.buckets_;

			//rhs.hash_function_ = nullptr;
		}
		return *this;
	}

	template<class K, class V>
	HashMap<K, V>::HashMap(HashMap&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template<class K, class V>
	auto HashMap<K, V>::operator=(HashMap&& rhs) noexcept -> HashMap&
	{
		if (this != &rhs)
		{
			hash_function_ = std::move(rhs.hash_function_);
			buckets_ = std::move(rhs.buckets_);

			rhs.hash_function_ = nullptr;
		}
		return *this;
	}

	template<class K, class V>
	auto HashMap<K, V>::Insert(const K& key, const V& value) -> void
	{
		const int bucket_number = hash_function_(key);
		buckets_[bucket_number].emplace_back(key, value);
		++size_;
	}

	template<class K, class V>
	auto HashMap<K, V>::HashFunction(const function<int(const K & key)>& hash) -> void
	{
		hash_function_ = hash;

		HashMap<K, V> new_hash_map(buckets_.size(), hash);

		for (auto& bucket : buckets_)
		{
			for (auto& chain : bucket)
			{
				new_hash_map.Insert(chain.first, chain.second);
			}
		}

		*this = std::move(new_hash_map);
	}

	template<class K, class V>
	auto HashMap<K, V>::operator[](const K& key) -> V&
	{
		const int bucket_number = hash_function_(key);

		if (!Contains(key)) throw AdtException("Key doesn't exist");

		for (auto& chain : buckets_[bucket_number])
		{
			if (chain.first == key)
			{
				return chain.second;
			}
		}
	}

	template<class K, class V>
	auto HashMap<K, V>::operator[](const K& key) const -> V
	{
		const int bucket_number = hash_function_(key);

		if (!Contains(key)) throw AdtException("Key doesn't exist");

		for (auto& chain : buckets_[bucket_number])
		{
			if (chain.first == key)
			{
				return chain.second;
			}
		}
	}

	template<class K, class V>
	auto HashMap<K, V>::Remove(const K& key) -> void
	{
		if (!Contains(key)) throw AdtException("Key not found");

		const auto bucket_number = hash_function_(key);

		for (auto it = buckets_[bucket_number].begin();
			it != buckets_[bucket_number].end();
			++it)
		{
			if (it->first == key)
			{
				buckets_[bucket_number].erase(it);
				break;
			}
		}
	}

	template<class K, class V>
	auto HashMap<K, V>::Traverse(const function<void(const K & key, const V & value)>& visit) const -> void
	{

		for (auto& bucket : buckets_)
		{
			for (auto& chain : bucket)
			{
			visit(chain.first, chain.second);
			}
		}
	}

	template<class K, class V>
	auto HashMap<K, V>::Contains(const K& key) -> bool
	{
		//if (!Contains(key)) throw AdtException("Key not found");

		const int bucket_number = hash_function_(key);
		for (auto& chain : buckets_[bucket_number])
		{
				if (key == chain.first)
				{
					return true; //found it
				}
			
		}
		return false;
	}

	template<class K, class V>
	auto HashMap<K, V>::Count() const -> size_t
	{
		return size_;
	}

	template<class K, class V>
	auto HashMap<K, V>::GetOrAdd(const K& key, const function<V()>& create_function) -> V&
	{
		//if (!Contains(key)) throw AdtException("Key not found");

		if (Contains(key))
		{
			return (*this)[key];
		}
		Insert(key, create_function());
		return (*this)[key];
	}

}
#endif