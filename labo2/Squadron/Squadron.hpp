//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_SQUADRON_HPP
#define SQUADRON_SQUADRON_HPP

#include "Ship.hpp"

class Squadron {
	friend std::ostream& operator<<(std::ostream& lhs, const Squadron& rhs);

	friend Squadron operator+(const Squadron& squadron, const Ship& ship);

	friend Squadron operator-(const Squadron& squadron, const Ship& ship);

public:
	explicit Squadron(const std::string& name);

	~Squadron();

	Squadron(const Squadron& squad);

	Squadron& addShip(const Ship& ship);

	Squadron addShipCopy(const Ship& ship) const;

	Squadron& removeShip(const Ship& ship);

	Squadron removeShipCopy(const Ship& ship) const;

	const Ship& get(size_t index) const;

	Squadron& operator+=(const Ship& ship);

	Squadron& operator-=(const Ship& ship);

	const Ship& operator[](size_t index) const;

	void setName(const std::string& name);

	void setLeader(const Ship& ship);

	void removeLeader();

	double computeConsumption(double distance, double speed);

private:
	struct Member;

	std::string name;
	size_t size;
	const Ship* leader;
	Member* head;

//	void getSpecs(double& totalWeight, double& maxSpeed);
};

#endif //SQUADRON_SQUADRON_HPP
