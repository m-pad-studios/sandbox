#ifndef ISTACK_HPP
#define ISTACK_HPP

namespace  data_structures
{
	template <class T>
	class IStack
	{
	public:
		virtual ~IStack() = default;
		virtual T Pop() = 0;
		virtual T Peek() = 0;
		virtual void Push(T data) = 0;
		virtual bool Empty() const noexcept = 0;
		virtual size_t Size() const noexcept = 0;
		virtual void Clear() noexcept = 0;
	};
}
#endif 