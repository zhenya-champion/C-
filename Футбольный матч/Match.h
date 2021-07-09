#pragma once
using namespace std; 
#include <string>
#include <iostream>
struct Match
{
	int OwnerPoints; // ���� �������
	int OppPoints; //���� ���������
	string match; // ����
	string Name; // ������� ������
	string Opponent; // ������� - ��������
	bool operator !=(const Match& other) {
		return Name != other.Name; 
	}
	bool operator <(const Match& other) {
		return Name < other.Name;
	}
};

