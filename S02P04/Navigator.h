#pragma once

#include "DiGraph.h"
#include "Vehicle.h"

using namespace std;

class Navigator {

protected:
	DiGraph * g;
	Vehicle *v;


public:
	Navigator(DiGraph *graph = 0, Vehicle *vh = 0);
	virtual ~Navigator();

	void setGraph(DiGraph *graph);
	void setVehicle(Vehicle *vehicle);
	float planRoute(string &from, string &to);
};