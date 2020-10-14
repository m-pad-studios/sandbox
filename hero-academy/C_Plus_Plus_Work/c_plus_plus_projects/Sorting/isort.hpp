#ifndef ISORT_HPP
#define ISORT_HPP

//This is my equivalent to an interface that I will be using.
template <class C>
class ISort
{
public:
	virtual ~ISort() = default;
	virtual size_t Sort(C container, const size_t& size) = 0;
	virtual const char* GetSortName() = 0;
};
#endif
