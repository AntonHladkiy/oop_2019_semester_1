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
#include "Dice.h"
#include "PackofDice.h"


int main()
{
	Graph<int> gr;
	for (int i = 0; i <= 9; i++) {
		gr.add_vertex(i);
	}
	gr.add_edge(0, 1);
	gr.add_edge(1, 2);
	gr.add_edge(1, 3);
	gr.add_edge(1, 4);
	gr.add_edge(4, 5);
	gr.add_edge(3, 5);
	gr.add_edge(2, 3);
	gr.add_edge(2, 6);
	gr.add_edge(6, 7);
	gr.add_edge(7, 8);
	gr.add_edge(8, 9);
	gr.add_edge(9, 7);
	Tree<int> tree;
	tree = gr.spanning_tree();
	tree.print();
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