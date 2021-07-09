#include "Tree.h"
#include <iostream>
#include "Match.h"

template class Tree <int>;
template class Tree <Match>;

ostream& operator<<(ostream& out, const Match& el) {
	out << el.Name << " " << el.match << " " << el.Opponent << endl;
	return out;
}

template <typename T>
void Tree<T>::print(shared_ptr<TreeNode<T>> Node)
{
	if (Node) {
		print(Node->left); 
			cout << Node->data;
		print(Node->right); /*
		cout << "{"; 
		cout << Node->data; 
		if (Node->left || Node->right) {
			cout << " : "; 
		}
		if (Node->left) {
			cout << "left";
			print(Node->left);
		}
		
		if (Node->right) {
			cout << "right";
			print(Node->right);
		}
		cout << "}"; */
	}
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::search(shared_ptr<TreeNode<T>> Node, T key)
{
	while (Node && key != Node->data) {
		if (key < Node->data) { //���� ����� ��������� (���� <)
			Node = Node->left; 
		}
		else {
			Node = Node->right; 
		}
	}
	return Node;
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::Min(shared_ptr<TreeNode<T>> Node)
{
	while (Node && Node->left) {
		Node = Node->left; 
	}
	return Node;
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::Max(shared_ptr<TreeNode<T>> Node)
{
	while (Node && Node->right) {
		Node = Node->right;
	}
	return Node;
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::Next(shared_ptr<TreeNode<T>> Node)
{
	shared_ptr<TreeNode<T>> a;
	if (Node) {
		if (Node->right) {
			return Min(Node->right); 
        }
		a = Node->parent; //���� ��� �� ������ ������ � ��� �������� ������ ���������
		while (a && Node == a->right) {
			//�������� �����
			Node = a;
			a = a->parent; 
		}
	}
		return a; 
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::Previous(shared_ptr<TreeNode<T>> Node)
{
	shared_ptr<TreeNode<T>> a;
	if (Node) {
		if (Node->left) {
			return Max(Node->left);
		}
		a = Node->parent; //���� ��� �� ������ ������ � ��� �������� left ���������
		while (a && Node == a->left) {
			//�������� �����
			Node = a;
			a = a->parent;
		}
	}
	return a;
}
template <typename T>
void Tree<T>::Insert(shared_ptr<TreeNode<T>> z)
{
	z->left = nullptr;
	z->right = nullptr;
	shared_ptr<TreeNode<T>>y;
	auto Node = root; 
	//����� ����� �������
	while (Node) {//���� ���� �� �������
		y = Node; // ������������ ��� ��� ����� �������� 
		if (z->data < Node->data) {
			Node = Node->left; 
		}
		else {
			Node = Node->right; 
		}
	}
	//���������� ��������� ������ parent
	z->parent = y; 
	if (y == nullptr) {//���� ������ �������
		root = z; 
	}
	else {
		if (z->data < y->data) { //���� ������ ������ �������� � ��������
			y->left = z;
		}
		else {
			y->right = z; 
		}
	}
}
template <typename T>
void Tree<T>::Insert(T data)
{
	auto Node = make_shared<TreeNode<T>>(data); 
	Insert(Node); 
}
template <typename T>
void Tree<T>::Del(shared_ptr<TreeNode<T>> Node)
{
	if (Node) {
		shared_ptr<TreeNode<T>> Node2; 
		if (Node->left == nullptr || Node->right == nullptr) { //���� �� ��� ����� ����
			Node2 = Node->left ? Node->left: Node->right; 
			if (Node2) {// ���� ���� ���� �������� 
				Node2->parent = Node->parent; //���������� � ��������
			}
			if (Node->parent == nullptr) {// ���� ��������� ������
				root = Node2; 
			}
			else {
				if (Node == Node->parent->left) {//���� ��������� ������� ��� ����� ��� ��������
					Node->parent->left = Node2;
				}
				else {
					Node->parent->right = Node2;
				}
			}
		}
		else {
			Node2 = Next(Node); //����� ���� �������� �� ���������� ��������
			Node->data = Node2->data; // �������������� ������
			Del(Node2); 
		}
	}
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::getRoot()
{
	return root;
}
