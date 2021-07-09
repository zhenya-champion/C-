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
		if (key < Node->data) { //если левое поддерево (ключ <)
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
		a = Node->parent; //если нод не корень дерева и нод является правым элементом
		while (a && Node == a->right) {
			//движемся вверх
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
		a = Node->parent; //если нод не корень дерева и нод является left элементом
		while (a && Node == a->left) {
			//движемся вверх
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
	//поиск места вставки
	while (Node) {//пока узел не нулевой
		y = Node; // предполагаем что это будет родитель 
		if (z->data < Node->data) {
			Node = Node->left; 
		}
		else {
			Node = Node->right; 
		}
	}
	//заполнение служебных данных parent
	z->parent = y; 
	if (y == nullptr) {//если первый элемент
		root = z; 
	}
	else {
		if (z->data < y->data) { //если данные меньше родителя и наоборот
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
		if (Node->left == nullptr || Node->right == nullptr) { //если не обе ветви есть
			Node2 = Node->left ? Node->left: Node->right; 
			if (Node2) {// если есть одна подветвь 
				Node2->parent = Node->parent; //прицепляем к родителю
			}
			if (Node->parent == nullptr) {// если удаляется корень
				root = Node2; 
			}
			else {
				if (Node == Node->parent->left) {//если удаляемый элемент был левым для родителя
					Node->parent->left = Node2;
				}
				else {
					Node->parent->right = Node2;
				}
			}
		}
		else {
			Node2 = Next(Node); //выбор след элемента от удаляемого элемента
			Node->data = Node2->data; // перезаписываем данные
			Del(Node2); 
		}
	}
}
template <typename T>
shared_ptr<TreeNode<T>> Tree<T>::getRoot()
{
	return root;
}
