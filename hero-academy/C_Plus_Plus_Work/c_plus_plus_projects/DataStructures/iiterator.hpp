#ifndef IITERATOR_HPP
#define IITERATOR_HPP

namespace data_structures
{
	template <class T>
	class IIterator
	{
	public:
		virtual ~IIterator() = default;
		virtual void MoveNext() = 0;
		virtual void Reset() noexcept = 0;
		virtual bool Done() const noexcept = 0;
		virtual T& Current() = 0;
		virtual T Current() const = 0;
		explicit virtual operator void* () const noexcept = 0;
	};

}
#endif