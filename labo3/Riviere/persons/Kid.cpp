//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Kid.hpp"

Kid::Kid(const std::string& name, const IndependantPerson* mother,
			const IndependantPerson* father)
	: DependantPerson(name), mother(mother), father(father) {
}
