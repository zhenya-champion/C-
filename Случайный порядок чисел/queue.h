#pragma once
#include <vector>
#include <memory>
#include <iostream>

struct QueueElement {
	int data;
	int pri;
};

class Queue {
	//������ �������
	std::vector<QueueElement> wait;
	//������������ �����
	size_t maxLength;
	public:
		//����������� 
		Queue(size_t size);
		//���������� ��������
		void Add(int c, int pri);
		//���������� �������
		std::unique_ptr<int> Extract(int pri);
		//������� � ������ � ������� ����������
		std::unique_ptr<int> ExtractAndRoll(int pri);
		//�������
		void Clear();
		//������?
		bool isEmpty();
		//������?
		bool isFull();
		//���������� ���������
		size_t getCount();
		//����� ������
		void Show();
 };
