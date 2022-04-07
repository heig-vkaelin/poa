/**
 * Point d'entrée du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <cstdlib>
#include <iostream>
#include "Squadron.hpp"
#include "ships/cargo/Shuttle.hpp"
#include "ships/cargo/StarDreadnought.hpp"
#include "ships/TIEFighter.hpp"

using namespace std;

void testInvalidCargo() {
	// TODO:
	// - cargo négatif
	// - maxCargo négatif
	// - cargo > maxCargo
}

void testComputeSingleConsumption() {
	// TODO:
	// - speed trop rapide pour le ship
}

/**
 * Teste les différentes possibilités d'ajouts de vaisseaux aux escadrilles
 */
void testAddShips() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	TIEFighter ship3;
	TIEFighter ship4;

	cout << "TEST : Ajouts de ship de differentes facons" << endl;
	squad += ship1;
	squad = squad + ship2;
	squad.addShip(ship3);

	Squadron squadCopy = squad.addShipCopy(ship4);

	cout << "Les 3 ships doivent figurer dans le squadron" << endl << endl;
	cout << squad << endl;

	cout << "Le 2eme squadron doit contenir 4 ships" << endl << endl;
	cout << squadCopy << endl;

	cout << "TEST : Ajout de ships qui sont deja dans le squadron" << endl;
	squad += ship1;
	squad += ship2;
	squad += ship3;

	cout << "Il n'y a pas de doublons dans la liste des ships" << endl << endl;
	cout << squad << endl;
}

/**
 * Teste les différentes possibilités de suppressions de vaisseaux des escadrilles
 */
void testRemoveShips() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	TIEFighter ship3;
	TIEFighter ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	cout << "TEST : Suppression de ship avec differentes methodes" << endl;
	squad -= ship1;
	squad = squad - ship2;
	squad.removeShip(ship3);
	squad = squad.removeShipCopy(ship4);
	cout << "Le squadron doit etre vide" << endl << endl;
	cout << squad << endl;

	cout << "TEST : Suppression de ship d'un squadron vide" << endl;
	squad -= ship1;
	cout << "Il ne se passe rien. Le squadron reste vide" << endl << endl;
	cout << squad << endl;

	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	cout << "TEST : Suppression d'un ship au milieu" << endl;
	squad -= ship3;
	cout << squad << endl;

	cout << "TEST : Suppression du premier ship" << endl;
	squad -= ship1;
	cout << squad << endl;

	cout << "TEST : Suppression du dernier ship" << endl;
	squad -= ship4;
	cout << squad << endl;
}

void testAccessShip() {
	// TODO
	// - get un ship par son index via [] + via get
}

void testAccessConstShip() {
	// TODO
	// - get un ship constant par son index via [] + via get
}

void testReplaceByIndex() {
	// TODO: voir comment faire ça ???


}

void testCopySquadron() {
	// TODO
	// - opérateur de copie, potentiellement delete aussi ?
}

void testSetLeader() {
	// TODO
	// - si déjà dans la liste, pas de doublon
	// - si pas présent, bien rajouté
}

void testRemoveLeader() {
	// TODO
	// l'enlève pas de la liste des vaisseaux
}

int main() {
//	testAddShips();
	testRemoveShips();
	return EXIT_SUCCESS;

	TIEFighter blackLeader;
	blackLeader.setNickname("Black leader");
	TIEFighter blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises

	Squadron squad("Black Squadron");
	squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;

	squad.setLeader(blackLeader);

	cout << squad;

//	cout << s << endl << endl;

//	cout << "Consommation: " << squad.computeConsumption(200, 40) << endl;

	return EXIT_SUCCESS;
}
