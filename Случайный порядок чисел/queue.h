#pragma once
#include <vector>
#include <memory>
#include <iostream>

struct QueueElement {
	int data;
	int pri;
};

class Queue {
	//данные очереди
	std::vector<QueueElement> wait;
	//максимальная длина
	size_t maxLength;
	public:
		//конструктор 
		Queue(size_t size);
		//Добавление элемента
		void Add(int c, int pri);
		//извлечение объекта
		std::unique_ptr<int> Extract(int pri);
		//перенос в начало и возврат последнего
		std::unique_ptr<int> ExtractAndRoll(int pri);
		//очистка
		void Clear();
		//пустая?
		bool isEmpty();
		//полная?
		bool isFull();
		//количество элементов
		size_t getCount();
		//вывод списка
		void Show();
 };
