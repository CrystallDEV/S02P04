#include <cstdlib>
#include <string>
#include "Node.h"

using namespace std;

class PriorityQueueEntry {
public:
	PriorityQueueEntry *next_entry;
	Node* node;
	float weight;

	PriorityQueueEntry(PriorityQueueEntry *next,Node* node, float weight) {
		this->node = node;
		this->next_entry = next;
		this->weight = weight;
	}

	PriorityQueueEntry(Node* node, float weight) {
		this->node = node;
		this->next_entry = NULL;
		this->weight = weight;
	}

};