/**
 * Classe représentant un vaisseau de type Intercepteur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "TIEInterceptor.hpp"

using namespace std;

unsigned TIEInterceptor::counter = 0;
const string TIEInterceptor::MODEL_NAME = "TIE/IN";
const unsigned TIEInterceptor::MAX_SPEED = 110;
const double TIEInterceptor::WEIGHT = 5;

TIEInterceptor::TIEInterceptor() : Ship(++counter) {
}

unsigned TIEInterceptor::getMaxSpeed() const {
	return MAX_SPEED;
}

string TIEInterceptor::getModelName() const {
	return MODEL_NAME;
}

double TIEInterceptor::getWeight() const {
	return WEIGHT;
}
