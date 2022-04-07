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

/*
 * A demander:
 *
 * opérateur +/- méthode ou fonction vu qu'un paramètre est privilégié sur l'autre
 * retour d'operator[] lors d'une affectation, HOW ??
 * levée d'exceptions ou retourner le squadron (ex: dans un addShip déjà présent)
 *
 * Commentaires: opérateurs surchargés ? / méthodes privées / protected ?
 *
 */

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

void testAddShips() {
   Squadron squad = Squadron("Squadron de test");
   TIEFighter ship1;
   TIEFighter ship2;
   TIEFighter ship3;
   TIEFighter ship4;

   cout << "TEST : Ajouts de ship avec différentes méthodes" << endl;

   squad += ship1;
//   squad = squad + ship2;
   squad.addShip(ship3);
//   squad.addShipCopy(ship4);

   cout << "Les quatre ships doivent figurer dans le squadron" << endl << endl;
   cout << squad << endl;

   cout << "TEST : Ajout d'un ship qui est déjà dans le squadron" << endl;
   squad += ship1;

   cout << "Il n'y a pas de doublons dans la liste des ships" << endl << endl;
   cout << squad << endl;
}

void testRemoveShips() {
	// TODO
	// - supprimer un ship via les 4 méthodes différentes
	// - supprimer dans liste vide
	// - supprimer head
	// - supprimer tail
	// - supprimer au milieu
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

//	StarDreadnought xx(200);
//	squad[0] = xx;
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
