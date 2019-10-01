#pragma once
#include <vector>
#include <iostream>
#include "List.h"
#include "Interface.h"
#include "Tree.h"
#include "PackofDice.h"
#include "Operator.h"
#include <string>
template <typename T>
class Graph: public Interface<T>
{
private:
	int find_number_by_value(T);
	void spanning_tree_recursive(std::vector<bool>&, int,Tree<T>&);
public:
	std::vector<T> values;
	std::vector<List> edges;
	Graph();
	void add_edge(int, int, double = 1) ;
	void delete_edge(int, int);
	void add_vertex(T) override;
	void delete_vertex_by_number(int);
	void delete_vertex(T) override;
	void print() override;
	void Prim_algorithm(Tree<T>&);
	std::vector<Tree<T>> spanning_tree();
};