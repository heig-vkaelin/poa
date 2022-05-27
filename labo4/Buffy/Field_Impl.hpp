//
// Created by Valentin Kaelin on 28.05.22.
//

#ifndef BUFFY_FIELD_IMPL_HPP
#define BUFFY_FIELD_IMPL_HPP

template<typename T>
T* Field::findClosestHumanoid(const Humanoid& closeTo) const {
	unsigned minDist = UINT_MAX;
	T* closest = nullptr;
	T* converted;

	for (Humanoid* humanoid: humanoids) {
		unsigned dist = Utils::getDistance(
			humanoid->getXPos(), humanoid->getYPos(),
			closeTo.getXPos(), closeTo.getYPos()
		);
		if (dist < minDist && (converted = dynamic_cast<T*>(humanoid)) != nullptr) {
			minDist = dist;
			closest = converted;
		}
	}
	return closest;
}

#endif // BUFFY_FIELD_IMPL_HPP
