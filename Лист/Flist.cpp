#include "Flist.h"

void FList::push_front(int el)
{
	//������� ����� �������
	auto new_item = std::make_shared<FlistItem>(el);
	//�������� � ���� ��������� �� ������ �������� �������
	new_item->next = root;
	//������ ��� ��������
	root = new_item;
}

void FList::push_back(int el)
{
	//������� ����� �������
	auto new_item = std::make_shared<FlistItem>(el);
	//���� ��������� �������
	auto current = root;
	while (current->next) {
		current = current->next;
	}//current �������� ��������� �������
	current->next = new_item;
}
