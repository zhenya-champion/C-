#pragma once
#include <memory>
#include <list>

template <typename T>

class Stack {
	//�������
	const int EMPTY = -1;
	size_t FULL;
	// ������ �����
	std::list<T> st;
	//������ ������� �����
	int top;
public:
	//�����������
	Stack(size_t size);
	//���������� ��������
	void Push(T c);
	//���������� ��������
	std::unique_ptr<T> Pop();
	//������� �����
	void Clear();
	//������?
	bool IsEmpty();
	//������?
	bool IsFull(); 
	//���-�� ���������
	int Getcount(); 
};