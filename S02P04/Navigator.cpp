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

float Navigator::planRoute(std::string &start, std::string &end) {
	Liste<Edge*> shortestPAth = g->getShortestPathByDijkstra(start, end);
	double sum = 0.0;
	for (int i = 0; i < shortestPAth.size(); ++i) {
		sum += shortestPAth[i]->getWeight();
	}
	return sum;
}