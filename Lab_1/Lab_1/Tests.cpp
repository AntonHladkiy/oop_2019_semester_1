#include "pch.h"
#include "catch.hpp"
#include "List.h"
#include "Graph.h"
#include <vector>
#include "Operator.h"

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