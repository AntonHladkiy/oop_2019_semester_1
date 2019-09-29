// Lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include "Graph.h"
#include <vector>
#include "List.h"
#include <random>
#include <ctime>
#include "Tree.h"




int main()
{
	Tree<int> t;
	t.add_vertex(3);
	t.print();
	t.add_vertex(4);
	t.add_vertex(5);
	t.add_vertex(6);
	t.print();
	t.delete_vertex(4);
	t.print();
	t.delete_vertex(3);
	t.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file