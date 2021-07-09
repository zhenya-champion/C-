#pragma once
#include<memory>
#include <iostream>
using namespace std;

//Узел дерева
template <typename T>
struct TreeNode
{
	T data; //данные дерева
	shared_ptr<TreeNode<T>> left; 
	shared_ptr<TreeNode<T>> right; 
	shared_ptr<TreeNode<T>> parent;
	TreeNode(T data_): data(data_){}
	TreeNode(){}
};
template <typename T>
class Tree
{
	shared_ptr<TreeNode<T>> root; // корневой узел
public:
	//вывод поддерева
	void print(shared_ptr<TreeNode<T>> Node);
	
	//поиск узла
	shared_ptr<TreeNode<T>> search(shared_ptr<TreeNode<T>> Node, T key); 
	
	//поиск минимального и максимального элемента от узла
	shared_ptr<TreeNode<T>> Min(shared_ptr<TreeNode<T>> Node);
	shared_ptr<TreeNode<T>> Max(shared_ptr<TreeNode<T>> Node);
	
	//след элемент
	shared_ptr<TreeNode<T>> Next(shared_ptr<TreeNode<T>> Node);
	
	//пред элемент
	shared_ptr<TreeNode<T>> Previous(shared_ptr<TreeNode<T>> Node);
	
	//вставка узла
	void Insert(shared_ptr<TreeNode<T>> z);
	
	//вставка данных
	void Insert(T data);
	
	//удаление элемента
	void Del(shared_ptr<TreeNode<T>> Node); 

	//вернуть корень
	shared_ptr<TreeNode<T>> getRoot(); 
	
};