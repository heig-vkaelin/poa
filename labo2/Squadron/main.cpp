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
#include "ships/TIEInterceptor.hpp"

using namespace std;

/**
 * Teste les potentielles valeurs invalides de la cargaison d'un vaisseau
 */
void testInvalidCargo() {
	cout << "TEST : creation d'un Ship avec une cargaison invalide" << endl;
	try {
		Shuttle shuttle = Shuttle(-12);
	} catch (const exception& e) {
		cout << "Erreur levee la cargaison est invalide: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}

	cout << "TEST : creation d'un Ship avec une cargaison trop elevee" << endl;
	try {
		Shuttle shuttle = Shuttle(100);
	} catch (const exception& e) {
		cout << "Erreur levee lorsque la cargaison est trop grande: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}

	cout << "TEST : modification d'un Ship avec un cargaison trop elevee" << endl;
	Shuttle shuttle = Shuttle(40);
	try {
		shuttle.setCargo(100);
	} catch (const exception& e) {
		cout << "Erreur levee lorsque la cargaison est trop grande: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}

	cout << "TEST : modification d'un Ship avec un cargaison invalide" << endl;
	Shuttle shuttle2 = Shuttle(40);
	try {
		shuttle2.setCargo(-12);
	} catch (const exception& e) {
		cout << "Erreur levee lorsque la cargaison est invalide: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}
}

/**
 * Teste le calcul de la consommation d'un vaisseau lors d'une opération
 */
void testComputeSingleConsumption() {
	cout << "TEST : vitesse lors de l'operation trop rapide pour le Ship" << endl;
	TIEInterceptor interceptor = TIEInterceptor();
	try {
		interceptor.computeConsumption(100, 300);
	} catch (const exception& e) {
		cout << "Erreur levee lors du calcul de la consommation: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}

	cout << "TEST : calcul de la consommation se deroule sans probleme" << endl;
	try {
		double conso = interceptor.computeConsumption(100, 50);
		if (conso == 0)
			throw exception();
	} catch (const exception& e) {
		cout << "Erreur non attendue lors du calcul de la consommation: " << endl;
		cout << e.what() << endl;
		cout << "TEST FAIL" << endl << endl;
		return;
	}
	cout << "TEST PASSE" << endl << endl;
}

/**
 * Teste la création de vaisseaux constants
 */
void testConstantShips() {
	const Shuttle ship1(12.2);

	cout << "TEST : Creation et affichage d'un ship constant" << endl;
	cout << ship1 << endl;

	cout << "TEST : Acces en lecture aux proprietes d'un ship constant" << endl;
	cout << "Max speed: " << ship1.getMaxSpeed() << endl;
	cout << "Cargaison: " << ship1.getCargo() << endl;
	cout << "Poids: " << ship1.getWeight() << endl << endl;

	Shuttle ship2(18);

	cout << "TEST : Copie d'un ship dans un ship constant" << endl;
	const Shuttle ship3 = ship2;
	ship2.setCargo(15);
	cout << "Cargaison ship original: " << ship2.getCargo() << endl;
	cout << "Cargaison ship copie: " << ship3.getCargo() << endl;
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

/**
 * Teste l'accès indexé à un vaisseau de l'escadrille
 */
void testAccessShip() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	TIEFighter ship3;
	TIEFighter ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;

	cout << "TEST : Acces indexe au 1er Ship" << endl;
	cout << squad[0] << endl;

	cout << "TEST : Acces indexe a un index au milieu de l'escadrille" << endl;
	cout << squad.get(2) << endl;

	cout << "TEST : Acces indexe au dernier ship" << endl;
	cout << squad[3] << endl;

	cout << "TEST : Acces indexe invalide" << endl;
	try {
		squad.get(5);
	} catch (const exception& e) {
		cout << "Erreur levee lors de l'acces indexe: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}

	const Squadron squad2(squad);
	cout << "TEST : Acces indexe dans un squadron constant" << endl;
	cout << squad2[3] << endl;
}

/**
 * Teste la copie d'une escadrille
 */
void testCopySquadron() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	TIEFighter ship3;
	TIEFighter ship4;
	squad += ship1;
	squad += ship2;
	squad += ship3;
	squad += ship4;
	squad.setLeader(ship1);

	cout << "TEST : La copie d'une escadrille copie bien les vaisseaux" << endl;
	Squadron squad2(squad);

	cout << "Escadrille originale: " << endl;
	cout << squad << endl;
	cout << "Escadrille copiee: " << endl;
	cout << squad2 << endl;

	cout << "TEST : Modification du nom de la copie" << endl;
	squad2.setName("Copie du squadron");
	cout << "Escadrille originale: " << squad.getName() << endl;
	cout << "Escadrille copiee: " << squad2.getName() << endl << endl;

	cout << "TEST : Modification du leader de la copie" << endl;
	squad2.setLeader(ship2);
	cout << "Escadrille originale: " << endl;
	cout << squad << endl;
	cout << "Escadrille copiee: " << endl;
	cout << squad2 << endl;

	cout << "TEST : Suppression de vaisseau dans l'escadrille originale" << endl;
	squad -= ship1;
	cout << "Escadrille originale: " << endl;
	cout << squad << endl;
	cout << "Escadrille copiee: " << endl;
	cout << squad2 << endl;

	cout << "TEST : Suppression de vaisseau  dans l'escadrille copiee" << endl;
	squad2 -= ship3;
	cout << "Escadrille originale: " << endl;
	cout << squad << endl;
	cout << "Escadrille copiee: " << endl;
	cout << squad2 << endl;

	cout << "TEST : Copie dans une escadrille constante" << endl;
	const Squadron squad3 = Squadron(squad2);
	cout << "Escadrille originale: " << endl;
	cout << squad << endl;
	cout << "Escadrille copiee (constante): " << endl;
	cout << squad2 << endl;
}

/**
 * Teste les modifications de leader de l'escadrille
 */
void testSetLeader() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	TIEFighter ship3;
	squad += ship1;
	squad += ship2;

	cout << "TEST : Ajout du leader deja present dans l'escadrille: pas de doublon"
		  << endl;
	squad.setLeader(ship1);
	cout << squad << endl;

	cout << "TEST : Ajout du leader pas present dans l'escadrille: egalement ajoute"
		  << endl;
	squad.setLeader(ship3);
	cout << squad << endl;
}

/**
 * Teste les suppressions de leader de l'escadrille
 */
void testRemoveLeader() {
	Squadron squad = Squadron("Squadron de test");
	TIEFighter ship1;
	TIEFighter ship2;
	squad += ship1;
	squad += ship2;
	squad.setLeader(ship1);

	cout << "TEST : Suppression du leader ne l'enleve pas de l'escadrille" << endl;
	squad.removeLeader();
	cout << squad << endl;

	cout << "TEST : Remplacement du leader ne l'enleve pas de l'escadrille" << endl;
	squad.setLeader(ship1);
	squad.setLeader(ship2);
	cout << squad << endl;
}

/**
 * Teste le calcul de la consommation d'une escadrille lors d'une opération
 */
void testSquadronConsumption() {
	Squadron squad = Squadron("Squadron de test");
	Shuttle ship1(42);
	TIEFighter ship2;
	squad += ship1;
	squad += ship2;
	double km = 200.5;
	double speed = 15;

	cout << "TEST : Verification du calcul de la consommation d'une escadrille"
		  << endl;
	double totalConsumption = squad.computeConsumption(km, speed);
	double oneByOneConsumption = 0;
	oneByOneConsumption += ship1.computeConsumption(km, speed);
	oneByOneConsumption += ship2.computeConsumption(km, speed);
	cout << "Consommation totale escadrille: " << totalConsumption << endl;
	cout << "Consommation ship par ship: " << oneByOneConsumption << endl << endl;

	cout << "TEST : Verification si la vitesse max de l'operation est trop grande "
			  "pour l'un des vaisseaux de l'escadrille" << endl;

	double tooBigSpeed = 60;
	try {
		squad.computeConsumption(km, tooBigSpeed);
	} catch (const exception& e) {
		cout << "Erreur lors du calcul de la consommation: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSE" << endl << endl;
	}
}

/**
 * Lance tous les tests créés ci-dessus
 */
void testEverything() {
	testInvalidCargo();
	testComputeSingleConsumption();
	testConstantShips();
	testAddShips();
	testRemoveShips();
	testAccessShip();
	testCopySquadron();
	testSetLeader();
	testRemoveLeader();
	testSquadronConsumption();
}

int main() {
//	testEverything();
//	return EXIT_SUCCESS;

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

	return EXIT_SUCCESS;
}
