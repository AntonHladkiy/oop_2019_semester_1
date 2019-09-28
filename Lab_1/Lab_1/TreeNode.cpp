#include "pch.h"
#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(T _data, TreeNode<T>* _parent):data(_data),parent(_parent) {

}
template <typename T>
TreeNode<T>::TreeNode(){

}

template class TreeNode<int>;