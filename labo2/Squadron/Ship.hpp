#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;

std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
	virtual ~Ship();

	void setNickname(const std::string& nick);

	virtual unsigned getMaxSpeed() const = 0;

	virtual std::string getModelName() const = 0;

	virtual double getWeight() const = 0;

	virtual std::ostream& toStream(std::ostream& os) const;

private:
	std::string nickname;
//	double consumption; // in tons
};

#endif /* SHIP_HPP */
