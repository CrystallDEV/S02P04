#include "stdafx.h"
#include <algorithm>
#include "DiGraph.h"
#include "SFMLGraphVisualizer.h"
#include <iostream>
#include "PriorityQueue.h"

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
	Node* node = this->getNodeByKey(key);
	Liste<Node *> neighbours = Liste<Node*>();
	Liste<Edge *> edges = node->getEdges();
	for (int pos = 0; pos < edges.size(); pos++) {
		neighbours.append(edges[pos]->getEndNode());
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
	return nullptr;
}

unsigned int DiGraph::getNodePos(Node *node) {
	for (unsigned int i = 0; i < nodes.size(); i++) {
		if (node->getKey() == nodes.getValueAt(i)->getKey())
			return i;
	}
}

Liste <Edge *> DiGraph::getShortestPathByDijkstra(string startNodeKey, string endNodeKey) {
	Liste<Edge *> shortestPath;
	if (startNodeKey == endNodeKey)
		return shortestPath;

	Node *startNode = getNodeByKey(startNodeKey);
	Node *endNode = getNodeByKey(endNodeKey);

	Node *helpPointer = nullptr;
	Node *endNoteOfEdgeList = nullptr;


	int nodeCount = nodes.size();

	Node *prev[100] = { nullptr };
	float dist[100] = { 0 };
	float value = 0;

	PriorityQueue *pq = new PriorityQueue();
	for (int i = 0; i < nodeCount; i++) {
		if (nodes.getValueAt(i) == startNode)
			dist[i] = 0;
		else
			dist[i] = 9999999;

		prev[i] = nullptr;

		pq->pqueue_insert(nodes.getValueAt(i), dist[i]);
	}

	while (pq->entries > 0) {
		helpPointer = pq->pqueue_extractMin()->node;

		for (int i = 0; i < helpPointer->getEdges().size(); i++) {
			endNoteOfEdgeList = helpPointer->getEdges().getValueAt(i)->getEndNode();

			value = dist[getNodePos(helpPointer)] + helpPointer->getEdges().getValueAt(i)->getWeight();

			if (value <  dist[getNodePos(endNoteOfEdgeList)]) {
				dist[getNodePos(endNoteOfEdgeList)] = value;
				prev[getNodePos(endNoteOfEdgeList)] = helpPointer;
				pq->pqueue_decreaseKey(endNoteOfEdgeList, value);
			}
		}
	}

	helpPointer = endNode;

	while (prev[getNodePos(helpPointer)] != nullptr) {
		for (int i = 0; i < prev[getNodePos(helpPointer)]->getEdges().size(); i++) {
			if (prev[getNodePos(helpPointer)]->getEdges().getValueAt(i)->getEndNode() == helpPointer)
				shortestPath.append(prev[getNodePos(helpPointer)]->getEdges()[i]);
		}
		helpPointer = prev[getNodePos(helpPointer)];
	}
	return shortestPath;
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