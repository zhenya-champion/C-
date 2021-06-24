#include "STACK.h"

template Stack<char>;
template Stack<int>;

template <typename T>
Stack<T>::Stack(size_t size): FULL(size)
{
}

template <typename T>
void Stack<T>::Push(T c)
{
	if (!IsFull()) {
		st.push_back(c);
	}
}

template <typename T>
std::unique_ptr<T> Stack<T>::Pop()
{
		if (!IsEmpty()) {
			T ret = st.back();
			st.pop_back();
			return std::make_unique<T>(ret);
		}
		return nullptr;
}

template <typename T>
void Stack<T>::Clear()
{
	st.clear();
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return st.empty();
}

template <typename T>
bool Stack<T>::IsFull()
{
	return st.size() == FULL;
}

template <typename T>
int Stack<T>::Getcount()
{
	return st.size();
}
