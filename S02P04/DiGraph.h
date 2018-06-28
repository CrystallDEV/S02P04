#pragma once

#include "Liste.h"
#include "Node.h"
#include "SFMLGraphVisualizer.h"

using namespace std;

class DiGraph {
private:
	Liste<Node *> nodes;
	GraphVisualizer* gv;
	Node * getNodeByKey(string key);

public:
	Liste<Edge*> route;

	void addNode(Node *node);
	void addNode(std::string key, int x, int y);
	void addEdge(string key1, string key2, float weight);
	Liste<Node *> getNeighbours(string key);
	Liste<Edge *> getEdges(string key);
	Liste<Node *> getNodes();
	Liste<Edge*> dijkstraShortestPath(std::string start, std::string end);
	Liste<Edge*> dijkstraShortestPath(Node start,  Node end);
	Liste<Edge*> getRoute();

	void setVisualizer(GraphVisualizer* graphviz);
	GraphVisualizer* const getVisualizer();

};

