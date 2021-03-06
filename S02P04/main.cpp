#include "DiGraph.h"
#include "Node.h"
 #include <string>
 #include <iostream>
 #include "SFMLGraphVisualizer.h"
 #include "Vehicle.h"
 #include "Navigator.h"

 using namespace std;

 void createDummyGraph(DiGraph &g) {
	 g.addNode(new Node("Aachen", 100, 600));
	 g.addNode(new Node("Berlin", 300, 650));
	 g.addNode(new Node("Koeln", 300, 300));
	 g.addNode(new Node("Essen", 900, 300));
	 g.addNode(new Node("Bonn", 300, 150));
	 g.addNode(new Node("Krefeld", 100, 160));
	
     g.addEdge("Aachen", "Berlin", 7);
	 g.addEdge("Koeln", "Aachen", 9);
	 g.addEdge("Aachen", "Krefeld", 7);
	 g.addEdge("Berlin", "Essen", 40);
	 g.addEdge("Berlin", "Koeln", 3);
	 g.addEdge("Koeln", "Essen", 31);
	 g.addEdge("Bonn", "Essen", 8);
	 g.addEdge("Krefeld", "Bonn", 1);
	
}

 int main(int argc, char ** argv) {
	
	 DiGraph myGraph;
	 SFMLGraphVisualizer graphviz;
	 myGraph.setVisualizer(&graphviz);
	
	 createDummyGraph(myGraph);
	 Navigator navi(&myGraph);
	 int speed = 120;
	 navi.setVehicle(new Car(speed));
	 std::string town1 = "Aachen";
	 std::string town2 = "Essen";

	 std::cout << "Fahrzeit: " << navi.planRoute(town1, town2) << std::endl;
	 graphviz.render(myGraph, town1, town2);

}