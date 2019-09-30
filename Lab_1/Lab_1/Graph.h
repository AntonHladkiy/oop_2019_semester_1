#pragma once
#include <vector>
#include <iostream>
#include "List.h"
#include "Interface.h"
#include "Tree.h"
template <typename T>
class Graph: public Interface<T>
{
private:
	std::vector<List> edges;
	std::vector<T> values;
	int find_number_by_value(T);
	void spanning_tree_recursive(std::vector<bool>&, int,Tree<T>&);
public:
	Graph();
	void add_edge(int, int, double = 1) ;
	void delete_edge(int, int);
	void add_vertex(T) override;
	void delete_vertex_by_number(int);
	void delete_vertex(T) override;
	void print() override;
	Tree<T> spanning_tree();
};