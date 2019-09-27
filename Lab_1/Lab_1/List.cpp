#include "pch.h"
#include "List.h"
Node::Node() {

}
Node::Node(int _vertex_number, double _weight) : vertex_number(_vertex_number), weight(_weight), next(nullptr) {

}
List::List() : start(nullptr) {

}
List::~List() {
	while (start) {
		Node* temp = start;
		start = start->next;
		delete temp;
	}
}
void List::add_node(int key, double weight) {
	if (!start) {
		start = new Node(key, weight);
	}
	else {
		Node* temp = start;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Node(key, weight);
	}
}
void List::delete_node(int key, int key_to_swap_with) {
	if (start) {
		Node* temp = start;
		while (temp->next) {
			if (temp->next->vertex_number == key) {
				Node* to_delete = temp->next;
				temp->next = temp->next->next;
				delete to_delete;
			}
			else {
				temp = temp->next;
			}
			if (temp->next) {
				if (temp->next->vertex_number == key_to_swap_with) {
					temp->next->vertex_number = key;
				}
			}
		}
		if (start->vertex_number == key) {
			Node* temp = start;
			start = start->next;
			delete temp;
		}
		else {
			if (start->vertex_number == key_to_swap_with) {
				start->vertex_number = key;
			}
		}
	}
}

void List::print() {
	if (start) {
		Node* temp = start;
		while (temp) {
			std::cout << temp->vertex_number << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "List is empty" << std::endl;
	}
}