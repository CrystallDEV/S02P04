#pragma once
#include "PriorityQueueEntry.h"

using namespace std;

class PriorityQueue {

public:
	PriorityQueueEntry *first;
	PriorityQueueEntry *last;
	int entries;

	PriorityQueue(PriorityQueueEntry *first, PriorityQueueEntry *last, int entries);

	PriorityQueue();

	/**
	* inserts a new element into the queue
	* @param pq
	* @param node
	* @param p
	*/
	void pqueue_insert(Node* node, float p);

	/**
	* returns the element value with the highest priority
	* @param pq
	* @return
	*/
	PriorityQueueEntry *pqueue_extractMin();

	/**
	* changes the priority of an element within the queue
	* @param pq
	* @param node
	* @param p
	*/
	void pqueue_decreaseKey(Node* node, float p);

	/**
	* removes an element of the queue by the given value
	* @param pq
	* @param node
	*/
	void pqueue_remove(float weight);

	/**
	* Returns if a queue is empty
	* @return
	*/
	bool isEmpty();
};
