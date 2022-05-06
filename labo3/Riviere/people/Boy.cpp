//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Boy.hpp"

Boy::Boy(const std::string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}
