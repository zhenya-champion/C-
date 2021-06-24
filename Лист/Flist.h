#pragma once
#include <memory>

struct FlistItem {
	//������ ������
	int data;
	//��������� �� ��������� �������
	std::shared_ptr<FlistItem> next;
	FlistItem(int el) : data(el) {

	}
};

class FList {
	std::shared_ptr <FlistItem> root;
public:
	//���������� �������� � ������
	void push_front(int el);
	//���������� �������� � �����
	void push_back(int el);
	//���������� �������� �� ������
	std::unique_ptr<int> pop_front(int el);
	//���������� �������� �� ������
	std::unique_ptr<int> pop_back(int el);
	//���-�� ���������
	size_t GetCount();
	//������� ������
	void show();
};
