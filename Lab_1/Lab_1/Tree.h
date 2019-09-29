#pragma once
#include "TreeNode.h"
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include "Interface.h"

template <typename T>
class Tree:public Interface<T>
{
private:
	void add_vertex_recursive(T, TreeNode<T>*);
	TreeNode<T>* find_node_by_value_recursive(T, TreeNode<T>*);
	void print_recursive(TreeNode<T>*,int);
public:
	TreeNode<T>* root;
	Tree();
	void add_vertex(T) override;
	void add_after_node(T, TreeNode<T>*);
	void add_node_after_node(TreeNode<T>*, TreeNode<T>*);
	void delete_vertex(T) override;
	TreeNode<T>* find_node_by_value(T);
	void print() override;
};

