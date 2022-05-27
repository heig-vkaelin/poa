//
// Created by Valentin Kaelin on 28.05.22.
//

#ifndef BUFFY_FIELD_IMPL_HPP
#define BUFFY_FIELD_IMPL_HPP

#include <limits>

template<typename T>
T* Field::findClosestHumanoid(const Humanoid& closeTo) const {
	double minDist = std::numeric_limits<double>::max();
	T* closest = nullptr;
	T* converted;

	for (Humanoid* humanoid: humanoids) {
		double dist =
			Position::getDistance(humanoid->getPosition(), closeTo.getPosition());
		if (dist < minDist && (converted = dynamic_cast<T*>(humanoid)) != nullptr) {
			minDist = dist;
			closest = converted;
		}
	}
	return closest;
}

#endif // BUFFY_FIELD_IMPL_HPP
