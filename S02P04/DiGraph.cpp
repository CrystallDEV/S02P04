#include "stdafx.h"
#include <algorithm>
#include "DiGraph.h"
#include "SFMLGraphVisualizer.h"

/**
*
* @param key1
* @param key2
* @param weight
*/
void DiGraph::addEdge(string key1, string key2, float weight) {
	Edge *edge = new Edge(getNodeByKey(key1), getNodeByKey(key2), weight);
	getNodeByKey(key1)->setNewEdge(edge);
}

/**
*
* @param node
*/
void DiGraph::addNode(Node *node) {
	this->nodes.append(node);
}

/**
*
* @param key1
* @param x
* @param y
*/
void DiGraph::addNode(std::string key, int x, int y) {
	this->nodes.append(new Node(key, x, y));
}

/**
*
* @param key
* @return
*/
Liste<Edge *> DiGraph::getEdges(string key) {
	return getNodeByKey(key)->getEdges();
}

/**
*
* @param key
* @return
*/
Liste<Node *> DiGraph::getNeighbours(string key) {
	Liste<Node *> nodes = this->getNodes();
	Liste<Node *> neighbours = NULL;
	for (int pos = 0; pos < nodes._last; pos++) {
		if (nodes._values[pos]->node_key == key) {
			if (neighbours.contains(nodes._values[pos])) continue;
			neighbours.append(nodes._values[pos]);
		}
	}

	return neighbours;
}

/**
*
* @return
*/
Liste<Node *> DiGraph::getNodes() {
	return this->nodes;
}

/**
*
* @param key
* @return
*/
Node *DiGraph::getNodeByKey(string key) {
	Liste<Node *> nodes = this->getNodes();
	for (int pos = 0; pos < nodes._last; pos++) {
		if (nodes._values[pos]->node_key == key) {
			return nodes._values[pos];
		}
	}
	return NULL;
}

Liste<Edge*> dijkstraShortestPath(std::string start, std::string end) {

	return *result;
}

Liste<Edge*> DiGraph::getRoute(){
	return route;
}

void DiGraph::setVisualizer(GraphVisualizer *graphviz) {
	gv = graphviz;
}

GraphVisualizer* const DiGraph::getVisualizer() {
	return gv;
}