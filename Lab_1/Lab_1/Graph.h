#pragma once
#include <vector>
#include <iostream>
#include "List.h"
template <typename T>
class Graph
{
private:
	std::vector<List> edges;
	std::vector<T> values;
public:
	Graph();
	void add_edge(int, int, double = 1);
	void delete_edge(int, int);
	void add_vertex(T);
	void delete_vertex(int);
	void print();
};