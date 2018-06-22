#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <sstream>
#define NODERADIUS 30

using namespace std;

#include "DiGraph.h"


class SFMLGraphVisualizer {
private:

	sf::RenderWindow window;
	sf::Font font;

public:

	SFMLGraphVisualizer() {
		// load my font
		this->font.loadFromFile("FreeMono.ttf");
	}

	void visualize(DiGraph &g) {

		window.create(sf::VideoMode(1000, 600), "Praktikum 4");

		Liste<Node *> nodes = g.getNodes();

		while (window.isOpen()) {
			// Process events
			sf::Event event;

			while (window.pollEvent(event)) {
				// Close window : exit
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// Clear screen
			window.clear(sf::Color::White);
			for (unsigned int i = 0; i < nodes.size(); i++) {
				Node *node = nodes.getValueAt(i);

				sf::Color color(255, 0, 0);
				drawNode(*node, color);

				// Ausgehende Kanten einzeichnen
				Liste<Edge *> edges;
				edges = g.getEdges(node->getKey());

				for (unsigned int j = 0; j < edges.size(); j++) {
					drawEdge(*(edges.getValueAt(j)), sf::Color::Black,
						edges.getValueAt(j)->getWeight(), 1);
				}
			}
			// Update the window
			window.display();
		}
	}

	void drawNode(Node &node, sf::Color nodeColor) {

		sf::CircleShape Circle(NODERADIUS);
		Circle.setPosition(node.getPositionX() - NODERADIUS,
			node.getPositionY() - NODERADIUS);
		Circle.setFillColor(sf::Color::White);
		Circle.setOutlineColor(nodeColor);
		Circle.setOutlineThickness(5);

		window.draw(Circle);

		sf::Text Label(node.getKey(), font, 32);
		Label.setPosition(node.getPositionX() - NODERADIUS / 2 + 5,
			node.getPositionY() - NODERADIUS / 2 - 5);
		Label.setFillColor(sf::Color::Blue);

		window.draw(Label);
	}

	void drawEdge(Edge &edge, sf::Color color, double weight,
		int thickness = 1, int arrowMagnitude = 20) {

		sf::Vector2f p(edge.getStartNode()->getPositionX(),
			edge.getStartNode()->getPositionY());
		sf::Vector2f q(edge.getEndNode()->getPositionX(),
			edge.getEndNode()->getPositionY());


		// Berechne den Winkel
		const double PI = 3.141592653;
		double angle = atan2((double)p.y - q.y, (double)p.x - q.x);

		// Berechne verkuerzten Pfeil
		q.x = (int)(q.x + NODERADIUS * cos(angle));
		q.y = (int)(q.y + NODERADIUS * sin(angle));
		p.x = (int)(p.x - NODERADIUS * cos(angle));
		p.y = (int)(p.y - NODERADIUS * sin(angle));

		sf::Vertex line[2] =
		{
			sf::Vertex(sf::Vector2f(p.x, p.y), color),
			sf::Vertex(sf::Vector2f(q.x, q.y), color)
		};

		// thickness
		window.draw(line, 2, sf::Lines);
		std::stringstream weightstring;
		weightstring << weight;
		sf::Text Labelweight(weightstring.str(), font, 32);
		int size = sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
		Labelweight.setPosition(p.x - (size / 2) * cos(angle) + 10 * sin(angle),
			p.y - (size / 2) * sin(angle) + 10 * cos(angle));
		Labelweight.setFillColor(sf::Color::Blue);
		window.draw(Labelweight);

		// Erstes Segment
		p.x = (int)(q.x + arrowMagnitude * cos(angle + PI / 8));
		p.y = (int)(q.y + arrowMagnitude * sin(angle + PI / 8));
		sf::Vertex first[2] =
		{
			sf::Vertex(sf::Vector2f(p.x, p.y), color),
			sf::Vertex(sf::Vector2f(q.x, q.y), color)
		};
		window.draw(first, 2, sf::Lines);


		// Zweites Segment
		p.x = (int)(q.x + arrowMagnitude * cos(angle - PI / 8));
		p.y = (int)(q.y + arrowMagnitude * sin(angle - PI / 8));
		sf::Vertex second[2] =
		{
			sf::Vertex(sf::Vector2f(p.x, p.y), color),
			sf::Vertex(sf::Vector2f(q.x, q.y), color)
		};
		window.draw(second, 2, sf::Lines);
	}
};