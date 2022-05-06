//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Girl.hpp"

Girl::Girl(const std::string& name, const IndependantPerson& dependsOn,
			  const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}
