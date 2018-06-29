
#include <iostream>
#include "PriorityQueue.h"

using namespace std;

PriorityQueue::PriorityQueue(PriorityQueueEntry *first, PriorityQueueEntry *last, int entries) {
	this->first = first;
	this->last = last;
	this->entries = entries;
}

PriorityQueue::PriorityQueue() {
	this->first = NULL;
	this->last = NULL;
	this->entries = 0;
};

void PriorityQueue::pqueue_insert(Node* node, float p) {
	PriorityQueueEntry *newEntry = new PriorityQueueEntry(node, p);

	if (this->entries == 0) {
		this->first = newEntry;
		this->last = newEntry;
		this->entries = 1;
		return;
	}

	if (newEntry->weight >= this->last->weight) {
		PriorityQueueEntry *lastEntry = this->last;
		lastEntry->next_entry = newEntry;
		this->last = newEntry;
	}
	else if (newEntry->weight <= this->first->weight) {
		PriorityQueueEntry *firstStoredEvent = this->first;
		newEntry->next_entry = firstStoredEvent;
		this->first = newEntry;
	}
	else {
		PriorityQueueEntry *currentEvent = this->first;
		while (currentEvent->next_entry != NULL) {
			if (newEntry->weight <= currentEvent->next_entry->weight) {
				if (newEntry->weight >= currentEvent->weight) {
					PriorityQueueEntry *next = currentEvent->next_entry;
					currentEvent->next_entry = newEntry;
					newEntry->next_entry = next;
					break;
				}
			}
			currentEvent = currentEvent->next_entry;
		}
	}
	this->entries++;
}

PriorityQueueEntry *PriorityQueue::pqueue_extractMin() {
	if (this->entries == 0) {
		cout << "ERROR: No entries found." << endl;
		return NULL;
	}
	PriorityQueueEntry *currentEntry = this->first;
	this->first = currentEntry->next_entry;
	float val = currentEntry->weight;

	if (this->entries == 1) {
		this->first = NULL;
		this->last = NULL;
		this->entries = 0;
		return currentEntry;
	}
	//Debugging values
	//    float priority = currentEntry->priority;
	//    printf("Value: %d Priority: %f\n", val, priority);
	pqueue_remove(currentEntry->weight);
	return currentEntry;
}

void PriorityQueue::pqueue_decreaseKey(Node* node, float weight) {
	//TODO improve? -> dont delete, change value and pointer in queue
	pqueue_remove(weight);
	pqueue_insert(node, weight);
}

void PriorityQueue::pqueue_remove(float weight) {
	PriorityQueueEntry *currentEntry = this->first;
	PriorityQueueEntry *previousEntry = NULL;
	if (currentEntry == NULL) {
		return;
	}

	while (currentEntry->next_entry != NULL) {
		if (currentEntry->weight == weight) {
			if (previousEntry == NULL) {
				this->first = currentEntry->next_entry;
				free(currentEntry);
				break;
			}
			previousEntry->next_entry = currentEntry->next_entry;
			free(currentEntry);
			break;
		}
		previousEntry = currentEntry;
		currentEntry = currentEntry->next_entry;
	}
	this->entries--;
}

bool PriorityQueue::isEmpty() {
	return this->entries > 0;
}