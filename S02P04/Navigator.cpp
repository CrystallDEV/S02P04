#include "Navigator.h"
#include "Vehicle.h"
#include "DiGraph.h"

Navigator::Navigator(DiGraph *graph, Vehicle *vh) : g(graph), v(vh) {}
Navigator::~Navigator() {}

void Navigator::setGraph(DiGraph *graph) {
	g = graph;
}

void Navigator::setVehicle(Vehicle *vehicle) {
	v = vehicle;
}

float Navigator::planRoute(std::string &from, std::string &to) {
	if (!g) throw "Graph not found!";
	g->route = g->dijkstraShortestPath(from, to);

	float sum = 0;
	Edge **iter =g->route->toArray();

	int lenght = &g->route->getLength();

	for (int i = 0; i < lenght; i++) {
		sum += iter[i]->getWeight();
	}

	if (v) {
		sum = v->neededTimeForDistance(sum);
		return sum;
	}

	std::cout << "No vehicle" << endl;

	return sum;
}