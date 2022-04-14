//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_BANK_HPP
#define RIVIERE_BANK_HPP

#include <string>
#include "Container.hpp"
#include "Boat.hpp"

class Bank : public Container {
public:
	explicit Bank(const std::string& name);

private:
	Boat* boat;
};


#endif // RIVIERE_BANK_HPP
