#pragma once
#include <vector>
template <typename T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* parent;
	std::vector<TreeNode<T>*> children;
	TreeNode();
	TreeNode(T,TreeNode<T>*);
};
