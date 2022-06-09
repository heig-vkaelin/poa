/**
 * Implémentation des méthodes génériques de Field
 *
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#ifndef BUFFY_FIELD_IMPL_HPP
#define BUFFY_FIELD_IMPL_HPP

#include <limits>

template<typename T>
T* Field::findClosestHumanoid(const Humanoid& closeTo) const {
	double minDist = std::numeric_limits<double>::max();
	T* closest = nullptr;
	T* converted;

	for (Humanoid* humanoid: humanoids) {
		if ((converted = dynamic_cast<T*>(humanoid)) == nullptr)
			continue;

		double dist = humanoid->getPosition().getDistance(closeTo.getPosition());
		if (dist < minDist) {
			minDist = dist;
			closest = converted;
		}
	}
	return closest;
}

#endif // BUFFY_FIELD_IMPL_HPP
