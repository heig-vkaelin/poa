#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;

std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
	virtual ~Ship();

	/* à compléter */

	void setNickname(const std::string& nick);

	virtual std::ostream& toStream(std::ostream& os) const;

protected:
	Ship(unsigned maxSpeed, double weight);
//	static std::string modelName;

private:
	/* à compléter */

	std::string nickname;
	unsigned maxSpeed; // in MGLT
	double weight; // in tons
	double consumption; // in tons
};

#endif /* SHIP_HPP */
