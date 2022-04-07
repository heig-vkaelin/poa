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
const double TIEInterceptor::MAX_SPEED = 110;
const double TIEInterceptor::WEIGHT = 5;

TIEInterceptor::TIEInterceptor() : Ship(++counter) {
}

double TIEInterceptor::getMaxSpeed() const {
	return MAX_SPEED;
}

string TIEInterceptor::getModelName() const {
	return MODEL_NAME;
}

double TIEInterceptor::getWeight() const {
	return WEIGHT;
}
