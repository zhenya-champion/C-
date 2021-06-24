#pragma once
#include <memory>

struct FlistItem {
	//данные списка
	int data;
	//указатель на следующий элемент
	std::shared_ptr<FlistItem> next;
	FlistItem(int el) : data(el) {

	}
};

class FList {
	std::shared_ptr <FlistItem> root;
public:
	//добавление элемента в начало
	void push_front(int el);
	//добавление элемента в конец
	void push_back(int el);
	//извлечение элемента из начала
	std::unique_ptr<int> pop_front(int el);
	//извлечение элемента из конеца
	std::unique_ptr<int> pop_back(int el);
	//кол-во элементов
	size_t GetCount();
	//вывести список
	void show();
};
