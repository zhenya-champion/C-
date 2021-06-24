#pragma once
#include <memory>
#include <list>

template <typename T>

class Stack {
	//границы
	const int EMPTY = -1;
	size_t FULL;
	// данные стека
	std::list<T> st;
	//индекс вершины стека
	int top;
public:
	//конструктор
	Stack(size_t size);
	//добавление элемента
	void Push(T c);
	//извлечение элемента
	std::unique_ptr<T> Pop();
	//очистка стека
	void Clear();
	//пустой?
	bool IsEmpty();
	//полный?
	bool IsFull(); 
	//кол-во элементов
	int Getcount(); 
};