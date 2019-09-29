#pragma once
#include "TreeNode.h"
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
template <typename T>
class Tree
{
private:
	void add_node_recursive(T, TreeNode<T>*);
	TreeNode<T>* find_node_by_value_recursive(T, TreeNode<T>*);
	void print_recursive(TreeNode<T>*,int);
public:
	TreeNode<T>* root;
	Tree();
	void add_node(T);
	void add_after_node(T, TreeNode<T>*);
	void add_node_after_node(TreeNode<T>*, TreeNode<T>*);
	void delete_node(T);
	TreeNode<T>* find_node_by_value(T);
	void print();
};

