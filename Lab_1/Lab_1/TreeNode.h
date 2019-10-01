#pragma once
#include <vector>
template <typename T>
class TreeNode
{
public:
	T data;
	double weight;
	int node_number;
	TreeNode<T>* parent;
	std::vector<std::pair<TreeNode<T>*,double>> children;
	TreeNode();
	TreeNode(T,TreeNode<T>*,int);
};

