//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_BOAT_HPP
#define RIVIERE_BOAT_HPP

#include <string>
#include "Container.hpp"
#include "Bank.hpp"

class Boat : public Container {
public:
	explicit Boat(const std::string& name);

	std::ostream& toStream(std::ostream& os) const override;

	const Bank* getBank() const;

	void setBank(const Bank* bank);

private:
	const Bank* bank;
};

#endif // RIVIERE_BOAT_HPP
