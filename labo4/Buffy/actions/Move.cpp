/**
 * Classe Move représentant le déplacement d'un humanoïde
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Move.hpp"
#include "../utils/Random.hpp"
#include "../actors/Humanoid.hpp"
#include "../Field.hpp"

using namespace std;

Move::Move(unsigned range, Humanoid& humanoid, const Humanoid* target)
	: Action(humanoid), range(range), target(target) {
}

void Move::execute(Field& field) {
	Position direction;
	Position newPosition = getHumanoid()->getPosition();

	for (unsigned i = 0; i < range; ++i) {
		if (target) {
			direction = newPosition.getDirection(target->getPosition());
		} else {
			vector<const Position*> directions =
				getPossibleDirections(newPosition, field);

			if (directions.empty())
				break;

			direction = *directions.at(
				(unsigned long)(Random::generate((int)directions.size()))
			);
		}
		newPosition.add(direction);
	}

	getHumanoid()->setPosition(newPosition);
}

vector<const Position*> Move::getPossibleDirections(const Position& position,
																	 const Field& field) const {
	vector<const Position*> possibleDirections;

	int x = position.getX();
	int y = position.getY();
	int maxX = (int)field.getWidth();
	int maxY = (int)field.getHeight();
	int reach = (int)range;

	if (x >= reach)
		possibleDirections.push_back(&Position::LEFT);
	if (x >= reach && y >= reach)
		possibleDirections.push_back(&Position::UP_LEFT);
	if (x >= reach && y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN_LEFT);
	if (x < maxX - reach)
		possibleDirections.push_back(&Position::RIGHT);
	if (x < maxX - reach && y >= reach)
		possibleDirections.push_back(&Position::UP_RIGHT);
	if (x < maxX - reach && y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN_RIGHT);
	if (y >= reach)
		possibleDirections.push_back(&Position::UP);
	if (y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN);

	return possibleDirections;
}
