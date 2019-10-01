#include "pch.h"
#include "TreeNode.h"
#include "PackofDice.h"
#include "Operator.h"

template <typename T>
TreeNode<T>::TreeNode(T _data, TreeNode<T>* _parent,int _node_number):data(_data),parent(_parent),node_number(_node_number){

}
template <typename T>
TreeNode<T>::TreeNode(){

}

template class TreeNode<int>;
template class TreeNode<double>;
template class TreeNode<double>;
template class TreeNode<std::string>;
template class TreeNode<std::vector<int>>;
template class TreeNode<Dice>;
template class TreeNode<PackofDice>;