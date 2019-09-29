#include "pch.h"
#include "Graph.h"


template<typename T>
Graph<T>::Graph() {
}


template <typename T>
void Graph<T>::add_edge(int from, int to, double weight) {
	if (from < edges.size() && to < edges.size()) {
		edges[from].add_node(to, weight);
	}
}

template <typename T>
void Graph<T>::delete_edge(int from, int to) {
	if (from < edges.size() && to < edges.size()) {
		edges[from].delete_node(to);
	}
}

template <typename T>
void Graph<T>::add_vertex(T data) {
	edges.push_back(List());
	values.push_back(data);
}

template <typename T>
void Graph<T>::delete_vertex_by_number(int key) {
	if (key < edges.size()) {
		edges[key] = edges[edges.size() - 1];
		edges[edges.size() - 1] = List();
		edges.pop_back();
		for (int i = 0; i < edges.size(); i++) {
			edges[i].delete_node(key, edges.size());
			
		}
		values[key] = values[values.size() - 1];
		values.pop_back();
	}
}


template <typename T>
int Graph<T>::find_number_by_value(T value) {
	for (int i = 0; i < values.size(); i++) {
		if (values[i] == value) {
			return i;
		}
	}
	return -1;
}


template <typename T>
void Graph<T>::delete_vertex(T value) {
	int vertex_number = find_number_by_value(value);
	if (vertex_number >= 0) {
		delete_vertex_by_number(vertex_number);
	}
}

template <typename T>
void Graph<T>::print() {
	for (int i = 0; i < edges.size(); i++) {
		edges[i].print();
	}
}


template class Graph<int>;