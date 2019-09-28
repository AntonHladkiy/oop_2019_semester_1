#pragma once
#include "TreeNode.h"
#include <random>
#include <ctime>
#include <cmath>
#include <vector>

template <typename T>
class Tree
{
public:
	TreeNode<T>* root;
	Tree();
	void add_node_recursive(T, TreeNode<T>*);
	void add_node(T);
	void add_after_node(T, TreeNode<T>*);
	void delete_node(T);
	TreeNode<T>* find_node_by_value_recursive(T,TreeNode<T>*);
	TreeNode<T>* find_node_by_value(T);
};

