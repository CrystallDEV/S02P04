#pragma once


class Vehicle {
protected:
	float speed;

public:
	Vehicle(float speed) : speed (speed) {}
	virtual ~Vehicle() {}

	virtual float const neededTimeForDistance(float distance) = 0;
};

	class Car : public Vehicle {

	public:
		Car(float speed) : Vehicle(speed) {}
		virtual ~Car() {}

		float const neededTimeForDistance(float distance) {
			cout << "CAR ";

			return ((distance / speed) * 60);
		}
	};

	class Cycle : public Vehicle {

	public:
		Cycle(float speed) : Vehicle(speed) {}
		virtual ~Cycle() {}

		float const neededTimeForDistance(float distance) {
			cout << "Cycle ";
			return (int)((distance / speed) * 60 * 0.80);
		}
	};
}