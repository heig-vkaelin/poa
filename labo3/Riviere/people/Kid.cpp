/**
 * Classe abstraite représentant un enfant
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <algorithm>
#include "Kid.hpp"
#include "../containers/Container.hpp"

using namespace std;

Kid::Kid(const string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: Person(name), dependsOn(&dependsOn), cannotStayWith(&cannotStayWith) {
}

bool Kid::isStateValid(const Container& container) const {
	// Si l'enfant est avec le parent avec qui il ne peut pas rester seul, il doit
	// également être avec le parent dont il dépend
	bool isWithCannotStayWith =
		find(container.begin(), container.end(), cannotStayWith) != container.end();
	bool isWithDependsOn =
		find(container.begin(), container.end(), dependsOn) != container.end();

	return !isWithCannotStayWith || isWithDependsOn;;
}

// Constructeur par défaut afin de ne pas être obligé de le redéfinir dans les
// classes qui héritent de Kid
Kid::~Kid() = default;
