/**
 * Classe représentant un vaisseau de type Intercepteur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "TIEInterceptor.hpp"

ShipSpecs TIEInterceptor::specs = ShipSpecs("TIE/IN", 110, 5);

TIEInterceptor::TIEInterceptor() : Ship(&specs) {
}