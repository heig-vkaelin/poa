//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_SQUADRON_HPP
#define SQUADRON_SQUADRON_HPP

#include "ships/Ship.hpp"

class Squadron {
	friend std::ostream& operator<<(std::ostream& lhs, const Squadron& rhs);

	friend Squadron operator+(const Squadron& squadron, Ship& ship);

	friend Squadron operator-(const Squadron& squadron, Ship& ship);

public:
	explicit Squadron(const std::string& name);

	~Squadron();

	Squadron(const Squadron& squad);

	Squadron& addShip(Ship& ship);

	Squadron addShipCopy(Ship& ship) const;

	Squadron& removeShip(Ship& ship);

	Squadron removeShipCopy(Ship& ship) const;

	const Ship& get(size_t index) const;

	Ship& get(size_t index);

	Squadron& operator+=(Ship& ship);

	Squadron& operator-=(Ship& ship);

	const Ship& operator[](size_t index) const;

	void setName(const std::string& name);

	void setLeader(Ship& ship);

	void removeLeader();

	double computeConsumption(double distance, double speed);

private:
	bool contains(Ship& ship);

	struct Member;

	std::string name;
	size_t size;
	Ship* leader;
	Member* head;

//	void getSpecs(double& totalWeight, double& maxSpeed);
};

#endif //SQUADRON_SQUADRON_HPP
