#include "Flist.h"

void FList::push_front(int el)
{
	//создаем новый элемент
	auto new_item = std::make_shared<FlistItem>(el);
	//помещаем в него указатель на старый корневой элемент
	new_item->next = root;
	//делаем его корневым
	root = new_item;
}

void FList::push_back(int el)
{
	//создаем новый элемент
	auto new_item = std::make_shared<FlistItem>(el);
	//ищем последний элемент
	auto current = root;
	while (current->next) {
		current = current->next;
	}//current содержит последний элемент
	current->next = new_item;
}
