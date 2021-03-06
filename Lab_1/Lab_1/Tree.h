#pragma once
#include "TreeNode.h"
#include <random>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include "Interface.h"
#include "PackofDice.h"
#include <string>
#include "Operator.h"

template <typename T>
class Tree:public Interface<T>
{
private:
	void add_vertex_recursive(T, TreeNode<T>*,int,double=1);
	TreeNode<T>* find_node_by_value_recursive(T, TreeNode<T>*);
	TreeNode<T>* find_node_by_number_recursive(int, TreeNode<T>*);
	void print_recursive(TreeNode<T>*,int);
	double count_weight_recursive(TreeNode<T>*);
public:
	int vertex_count;
	TreeNode<T>* root;
	Tree();
	void add_vertex(T) override;
	void add_after_node(T, TreeNode<T>*,double, int);
	void add_node_after_node(TreeNode<T>*, TreeNode<T>*,double);
	void delete_vertex(T) override;
	TreeNode<T>* find_node_by_value(T);
	TreeNode<T>* find_node_by_number(int);
	double count_weight();
	void print() override;
};

