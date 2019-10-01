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
void Graph<T>::spanning_tree_recursive(std::vector<bool>& checked, int vertex_number,Tree<T>& result) {
	checked[vertex_number] = true;
	Node* temp = edges[vertex_number].start;
	while (temp) {
		if (!checked[temp->vertex_number]) {
			result.add_after_node(values[temp->vertex_number], result.find_node_by_number(vertex_number),temp->weight,temp->vertex_number);
			spanning_tree_recursive(checked, temp->vertex_number, result);
		}
		temp = temp->next;
	}
}

template <typename T>
std::vector<Tree<T>> Graph<T>::spanning_tree() {
	std::vector<bool> checked;
	checked.resize(values.size());
	for (int i = 0; i < values.size(); i++) {
		checked[i] = false;
	}
	std::vector<Tree<T>> forest;
	for (int i = 0; i < checked.size(); i++) {
		if (!checked[i]) {
			Tree<T> result;
			if (!values.empty()) {
				result.add_after_node(values[i],nullptr,1,i);
			}
			spanning_tree_recursive(checked, i, result);
			
			forest.push_back(result);
		}
	}
	return forest;
}

template <typename T>
void Graph<T>::Prim_algorithm(Tree<T>& result) {
	result.add_after_node(values[0], nullptr, 0, 0);
	std::vector<int> cheapest_connection;
	std::vector<int> visit_status;
	std::vector<double> cheapest_cost;
	cheapest_connection.resize(values.size());
	visit_status.resize(values.size());
	cheapest_cost.resize(values.size());
	for (int i = 0; i < values.size(); i++) {
		cheapest_connection[i] = -1;
		cheapest_cost[i] = INT_MAX;
		visit_status[i] = i;
	}
	while (!visit_status.empty()) {
		int k = 0;
		int minimum = visit_status[k];
		for (int i = 0; i < visit_status.size(); i++) {
			if (cheapest_cost[visit_status[i]] < cheapest_cost[minimum]) {
				minimum = visit_status[i];
				k = i;
			}
		}

		if (cheapest_connection[minimum] != -1) {
			Node* temp = edges[cheapest_connection[minimum]].start;
			double value = 0;
			while (temp) {
				if (temp->vertex_number == minimum) {
					value = temp->weight;
					break;
				}
				temp = temp->next;
			}
			result.add_after_node(values[minimum], result.find_node_by_value(values[cheapest_connection[minimum]]), value, minimum);
		}

		Node* temp = edges[minimum].start;
		while (temp) {
			for (int i = 0; i < visit_status.size(); i++) {
				if (temp->vertex_number == visit_status[i]) {
					if (temp->weight < cheapest_cost[visit_status[i]]) {
						cheapest_cost[visit_status[i]] = temp->weight;
						cheapest_connection[visit_status[i]] = minimum;
					}
				}
			}
			temp = temp->next;
		}
		visit_status.erase(visit_status.begin() + k);
	}
}
template <typename T>
void Graph<T>::print() {
	for (int i = 0; i < edges.size(); i++) {
		edges[i].print();
	}
}


template class Graph<int>;
template class Graph<double>;
template class Graph<double>;
template class Graph<std::string>;
template class Graph<std::vector<int>>;
template class Graph<Dice>;
template class Graph<PackofDice>;