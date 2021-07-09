#pragma once
#include<memory>
#include <iostream>
using namespace std;

//���� ������
template <typename T>
struct TreeNode
{
	T data; //������ ������
	shared_ptr<TreeNode<T>> left; 
	shared_ptr<TreeNode<T>> right; 
	shared_ptr<TreeNode<T>> parent;
	TreeNode(T data_): data(data_){}
	TreeNode(){}
};
template <typename T>
class Tree
{
	shared_ptr<TreeNode<T>> root; // �������� ����
public:
	//����� ���������
	void print(shared_ptr<TreeNode<T>> Node);
	
	//����� ����
	shared_ptr<TreeNode<T>> search(shared_ptr<TreeNode<T>> Node, T key); 
	
	//����� ������������ � ������������� �������� �� ����
	shared_ptr<TreeNode<T>> Min(shared_ptr<TreeNode<T>> Node);
	shared_ptr<TreeNode<T>> Max(shared_ptr<TreeNode<T>> Node);
	
	//���� �������
	shared_ptr<TreeNode<T>> Next(shared_ptr<TreeNode<T>> Node);
	
	//���� �������
	shared_ptr<TreeNode<T>> Previous(shared_ptr<TreeNode<T>> Node);
	
	//������� ����
	void Insert(shared_ptr<TreeNode<T>> z);
	
	//������� ������
	void Insert(T data);
	
	//�������� ��������
	void Del(shared_ptr<TreeNode<T>> Node); 

	//������� ������
	shared_ptr<TreeNode<T>> getRoot(); 
	
};