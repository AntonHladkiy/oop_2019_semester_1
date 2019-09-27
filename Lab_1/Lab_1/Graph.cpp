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
void Graph<T>::delete_vertex(int key) {
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
void Graph<T>::print() {
	for (int i = 0; i < edges.size(); i++) {
		edges[i].print();
	}
}


template class Graph<int>;