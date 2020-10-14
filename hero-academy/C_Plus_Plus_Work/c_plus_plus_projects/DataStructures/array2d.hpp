#ifndef array_2d_HPP
#define array_2d_HPP


#include "array.hpp"
#include "iarray2d.hpp"
#include <algorithm>

namespace data_structures
{
	template <class T>
	class Array2D  : public IArray2D<T>
	{
	public:
		Array2D() = default;
		~Array2D() = default;
		explicit Array2D(const size_t& rows, const size_t& columns) noexcept(false);
		Array2D(const Array2D& copy) noexcept(false);
		Array2D& operator=(const Array2D& copy) noexcept(false);
		Array2D(Array2D&& copy) noexcept;
		Array2D& operator=(Array2D&& copy) noexcept;
		T Select(const int& row, const int& column) const override;
		T& Select(const int& row, const int& column) override;
		Row<T> operator[](const int& row_index) const noexcept(false) override;
		Row<T> operator[](const int& row_index) noexcept(false) override;
		explicit operator bool() const noexcept override;
		size_t Rows() const noexcept override;
		size_t Columns() const noexcept override;
		void Rows(const size_t& rows) noexcept(false) override;
		void Columns(const size_t& columns) noexcept(false) override;

		bool operator==(const Array2D<T>& rhs) const noexcept;
	private:
		Array<T> storage_{};
		size_t rows_ = 0;
		size_t columns_ = 0;
	};


	template <class T>
	Array2D<T>::Array2D(const size_t& rows, const size_t& columns) noexcept(false) :storage_(rows * columns), rows_(rows)
	, columns_(columns){		}

	template <class T>
	Array2D<T>::Array2D(const Array2D& copy) noexcept(false)
	{
		*this = copy;
	}

	template <class T>
	Array2D<T>& Array2D<T>::operator=(const Array2D& copy) noexcept(false)
	{
		if(this != &copy)
		{
			rows_ = copy.rows_;
			columns_ = copy.columns_;
			storage_ = copy.storage_;
		}
		return *this;
	}

	template <class T>
	Array2D<T>::Array2D(Array2D&& copy) noexcept
	{
		*this = std::move(copy);
	}

	template <class T>
	Array2D<T>& Array2D<T>::operator=(Array2D&& copy) noexcept
	{
		if(this != &copy)
		{
			rows_ = copy.rows_;
			columns_ = copy.columns_;
			storage_ = std::move(copy.storage_);
			
		}
		return *this;
	}

	template <class T>
	T Array2D<T>::Select(const int& row, const int& column) const
	{
		auto actual_index = (row * columns_) + column;

		if (row < 0 || row > rows_ || column < 0 || column > columns_)
			throw AdtException("Out of Bounds");
		
		return storage_[actual_index];
	}

	template <class T>
	T& Array2D<T>::Select(const int& row, const int& column)
	{
		auto actual_index = (row * columns_) + column;

		if (row < 0 || row > rows_ || column < 0 || column > columns_)
			throw AdtException("Out of Bounds");

		return storage_[actual_index];
	}

	template <class T>
	Row<T> Array2D<T>::operator[](const int& row_index) const noexcept(false)
	{
		return Row<T>(*this, row_index);
		
	}

	template <class T>
	Row<T> Array2D<T>::operator[](const int& row_index) noexcept(false)
	{
		return Row<T>(*this, row_index);
	}

	template <class T>
	Array2D<T>::operator bool() const noexcept
	{
		return static_cast<bool>(storage_);
	}

	template <class T>
	size_t Array2D<T>::Rows() const noexcept
	{
		return rows_;
	}

	template <class T>
	size_t Array2D<T>::Columns() const noexcept
	{
		return columns_;
	}

	template <class T>
	void Array2D<T>::Rows(const size_t& rows) noexcept(false)
	{
		Array<T> temp(rows * columns_);

		int smaller_rows = rows_ < rows ? rows_ : rows;
		
		for(size_t i = 0; i < smaller_rows * columns_; ++i)
		{
			temp[i] = storage_[i];
		}
		
		storage_ = std::move(temp);
		rows_ = rows;
		
	}

	template <class T>
	void Array2D<T>::Columns(const size_t& columns) noexcept(false)
	{
			const auto smaller_columns = columns_ < columns ? columns_ : columns;
			Array<T> temp(rows_ * columns);
		
			for (auto i = 0u; i < rows_; ++i)
			{
				const auto row_count_old = i * columns_;
				const auto row_count_new = i * columns;

				for (auto j = 0u; j < smaller_columns; ++j)
				{
					temp[row_count_new + j] = storage_[row_count_old + j];
				}
			}
			storage_ = std::move(temp);
			columns_ = columns;
		
		}
	

	template <class T>
	bool Array2D<T>::operator==(const Array2D<T>& rhs) const noexcept
	{
		if (storage_.Length() != rhs.Length() || storage_.StartIndex() != rhs.StartIndex())
		{
			return false;
		}

		for (auto i = 0u; i < storage_.Length(); ++i)
		{
			for (auto j = 0u; j < storage_.StartIndex(); ++j)
			{
				if (storage_[i][j] != rhs[i][j])
				{
					return false;
				}
			}
		}
		return true;
		
	}
}
#endif // array_2d_H