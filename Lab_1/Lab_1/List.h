#pragma once
#include <iostream>
class Node
{
public:
	int vertex_number;
	double weight;
	Node* next;
	Node(int, double);
	Node();
	friend class List;
};


class List
{
public:
	Node* start;
	List();
	void add_node(int, double = 1);
	void delete_node(int, int = -1);
	void print();
};