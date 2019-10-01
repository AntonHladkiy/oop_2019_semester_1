#include "pch.h"
#include "catch.hpp"
#include "List.h"
#include "Graph.h"
#include <vector>
#include "Operator.h"
#include <string>

TEST_CASE("List test", "[list]") {
	List list;
	list.add_node(3);
	list.add_node(5);
	list.delete_node(3);
	REQUIRE(list.start->vertex_number == 5);
}


TEST_CASE("Graph test", "[graph]") {
	Graph<std::vector<int>> graph;
	for (int i = 0; i < 15; i++) {
		graph.add_vertex({ i,i,i });
	}
	for (int i = 0; i < 10; i++) {
		graph.add_edge(0, i);
		if (i >= 5) {
			graph.add_edge(1, i);
		}
	}
	REQUIRE(graph.edges[0].count_nodes_number() == 10);
	REQUIRE(graph.edges[1].count_nodes_number() == 5);
	graph.add_edge(2, 0);
	for (int i = 3; i < 15; i++) {
		REQUIRE(graph.edges[i].start==nullptr);
	}
	REQUIRE(graph.edges[2].start->vertex_number == 0);
	graph.delete_edge(2, 0);
	REQUIRE(graph.edges[2].start == nullptr);
	graph.delete_vertex({ 1,1,1 });
	REQUIRE(graph.edges[0].count_nodes_number() == 9);
}

TEST_CASE("Tree test", "[tree]") {
	Tree<std::string> tree;
	tree.add_after_node("a", nullptr, 0, 0);
	for (int i = 0; i < 5; i++) {
		tree.add_after_node("b", tree.find_node_by_value("a"), i, i + 1);
	}
	REQUIRE(tree.vertex_count == 6);
	tree.delete_vertex("a");
	REQUIRE(tree.root->data == "b");

}

TEST_CASE("Spanning tree test", "[spanning tree]") {
	Graph<double> graph;
	Tree<double> spanning_tree;
	Tree<double> minimal_spanning_tree;
	for (int i = 0; i < 4; i++) {
		graph.add_vertex(i);
	}
	graph.add_edge(0, 1, 2);
	graph.add_edge(1, 0, 2);
	graph.add_edge(1, 2, 2);
	graph.add_edge(2, 1, 2);
	graph.add_edge(0, 2, 1);
	graph.add_edge(2, 0, 1);
	graph.add_edge(2, 3, 3);
	graph.add_edge(3, 2, 3);
	spanning_tree = graph.spanning_tree()[0];
	graph.Prim_algorithm(minimal_spanning_tree);
	REQUIRE(spanning_tree.vertex_count == 4);
	REQUIRE(spanning_tree.root->data == 0);
	REQUIRE(spanning_tree.count_weight() == 7);
	REQUIRE(minimal_spanning_tree.count_weight() <= spanning_tree.count_weight());
}


TEST_CASE("Pack of dice test", "[pack of dice]") {
	std::vector<Dice> vector;
	vector.push_back(Dice(4));
	vector.push_back(Dice(8));
	vector.push_back(Dice(10));
	vector.push_back(Dice(12));
	vector.push_back(Dice(2));
	vector.push_back(Dice(14));
	vector.push_back(Dice(16));
	vector.push_back(Dice(18));
	vector.push_back(Dice(20));
	std::vector<Dice> vector_1;
	vector_1.push_back(Dice(2));
	vector_1.push_back(Dice(6));
	PackofDice pack(vector);
	PackofDice pack_1(vector_1);
	pack.count_chances();
	double chance = 0;
	for (int i = 0; i < pack.chances.size(); i++) {
		chance += pack.chances[i];
	}
	REQUIRE(abs(chance-1)<0.00001);
	for (int i = 0; i < 3; i++) {
		REQUIRE(pack.chances[i] == 0);
	}
	REQUIRE(pack.count_expected_value() < 68);
	pack_1.count_chances();
	REQUIRE(pack.count_expected_value() > pack_1.count_expected_value());
}