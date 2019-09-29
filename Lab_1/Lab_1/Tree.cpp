#include "pch.h"
#include "Tree.h"


double generate_random() {
	static std::random_device rd;
	std::seed_seq seed{ rd(), static_cast<unsigned int>(time(nullptr)) };
	static std::mt19937_64 gen(seed);
	static std::uniform_real_distribution<> real_dis;
	return real_dis(gen);
}


template <typename T>
Tree<T>::Tree() :root(nullptr){

}
template <typename T>
void Tree<T>::add_vertex_recursive(T data, TreeNode<T>* current) {
	if (current) {
		double random = generate_random();
		if (random <= 0.5 || current->children.empty()) {
			current->children.push_back(new TreeNode<T>(data,current));
		}
		else {
			double random = generate_random();
			add_vertex_recursive(data, current->children[floor(random*current->children.size())]);
		}
	}
	else {
		root = new TreeNode<T>(data,nullptr);
	}
} 

template <typename T>
void Tree<T>::add_vertex(T data) {
	add_vertex_recursive(data, root);
}


template <typename T>
void Tree<T>::add_after_node(T data, TreeNode<T>* parent) {
	parent->children.push_back(new TreeNode<T>(data, parent));
}


template <typename T>
void Tree<T>::add_node_after_node(TreeNode<T>* current, TreeNode<T>* parent) {
	current->parent = parent;
	parent->children.push_back(current);
}

template <typename T>
TreeNode<T>* Tree<T>::find_node_by_value_recursive(T data,TreeNode<T>* current) {
	if (current) {
		if (current->data == data) {
			return current;
		}
		else {
			if (current->children.empty()) {
				return nullptr;
			}
			else {
				for (int i = 0; i < current->children.size(); i++) {
					TreeNode<T>* temp = find_node_by_value_recursive(data, current->children[i]);
					if (temp) {
						return temp;
					}
				}
			}
		}
	}
	else {
		return current;
	}
}

template <typename T>
TreeNode<T>* Tree<T>::find_node_by_value(T data) {
	return find_node_by_value_recursive(data, root);
}

template <typename T>
void Tree<T>::delete_vertex(T data) {
	TreeNode<T>* temp = find_node_by_value(data);
	if (temp) {
		if (temp == root) {
			
			if (temp->children.empty()) {
				root = nullptr;
				delete temp;
			}
			else {
				double random = generate_random();
				root = temp->children[floor(temp->children.size()*random)];
				root->parent = nullptr;
				temp->children.erase(temp->children.begin()+floor(temp->children.size()*random));
				for (int i = 0; i < temp->children.size(); i++) {
					add_node_after_node(temp->children[i], root);
				}
				delete temp;
			}
		}
		else {
			if (!temp->children.empty()) {
				for (int i = 0; i < temp->children.size(); i++) {
					add_node_after_node(temp->children[i], temp->parent);
				}
			}
			for (int i = 0; i < temp->parent->children.size(); i++) {
				if (temp->parent->children[i]->data == data) {
					temp->parent->children.erase(temp->parent->children.begin() + i);
				}
			}
			delete temp;
		}
	}
}


template <typename T>
void Tree<T>::print_recursive(TreeNode<T>* current,int counter) {
	if (current) {
		for (int i = 0; i < counter; i++) {
			std::cout << " ";
		}
		std::cout << current->data << std::endl;
		if (current->children.empty()) {
			return;
		}
		else {
			for (int i = 0; i < current->children.size(); i++) {
				print_recursive(current->children[i],counter+1);
			}
		}
	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}


template <typename T>
void Tree<T>::print() {
	print_recursive(root, 0);
}


template class Tree<int>;