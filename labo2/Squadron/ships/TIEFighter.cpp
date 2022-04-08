/**
 * Classe représentant un vaisseau de type Chasseur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "TIEFighter.hpp"

ShipSpecs TIEFighter::specs = ShipSpecs("TIE/LN", 100, 6);

TIEFighter::TIEFighter() : Ship(&specs) {
}
