#pragma once
#include <iostream>
class Node
{
private:
	int vertex_number;
	double weight;
	Node* next;
public:
	Node(int, double);
	Node();
	friend class List;
};


class List
{
private:
	Node* start;
public:
	
	List();
	~List();
	void add_node(int, double = 1);
	void delete_node(int, int = -1);
	void print();
};