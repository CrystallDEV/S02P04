#pragma once

#include "Liste.h"
#include "Node.h"

class GraphVisualizer;

using namespace std;

class DiGraph {
private:
	Liste<Node *> nodes;
	GraphVisualizer* gv;


public:
	Liste<Edge*> route;

	void addNode(Node *node);
	void addNode(std::string key, int x, int y);
	void addEdge(string key1, string key2, float weight);
	unsigned int getNodePos(Node *);
	Liste<Node *> getNeighbours(string key);
	Liste<Edge *> getEdges(string key);
	Liste<Node *> getNodes();
	Liste<Edge*> getShortestPathByDijkstra(string start, string end);
	Liste<Edge*> getShortestPathByDijkstra(Node start, Node end);
	Liste<Edge*> getRoute();

	void setVisualizer(GraphVisualizer* graphviz);
	GraphVisualizer* const getVisualizer();
	Node * getNodeByKey(string key);
};

