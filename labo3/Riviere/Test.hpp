#ifndef RIVIERE_TEST_HPP
#define RIVIERE_TEST_HPP

#include <string>
#include <sstream>
#include <list>

/**
 * Classe testant les différentes fonctionnalités et cas limites du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Test {
public:
	/**
	 * Teste la bonne solution du jeu
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void correctSolution(bool debug = false);

	/**
	 * Teste la bonne remise à zéro lors de la demande de réinitialisation de
	 * l'utilisateur
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void resetProgram(bool debug = false);

	/**
	 * Teste la règle qui dit que le garçon ne peut pas rester avec sa mère si son père
	 * n'est pas là
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void boyWithMotherButWithoutFather(bool debug = false);

	/**
	 * Teste la règle qui dit que la fille ne peut pas rester avec son père si sa mère
	 * n'est pas là
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void girlWithFatherButWithoutMother(bool debug = false);

	/**
	 * Teste qu'un bateau vide ne peut pas bouger de rive
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void emptyBoatCantMove(bool debug = false);

	/**
	 * Teste qu'il puisse y avoir au maximum 2 personnes dans le bateau
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void onlyTwoPeopleOnTheBoat(bool debug = false);

	/**
	 * Teste que le voleur ne puisse pas être seul avec la famille sans le policier
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void thiefWithFamilyWithoutPoliceman(bool debug = false);

	/**
	 * Teste que les enfants et le voleur ne puissent pas conduire le bateau
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void thiefAndChildrenCannotDriveTheBoat(bool debug = false);

	/**
	 * Lance tous les tests créés ci-dessus
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 */
	static void testEverything(bool debug = false);

private:
	/**
	 *  Lance le test souhaité après avoir reçu une entrée utilisateur.
	 *  Vérifie que les string souhaitées soient bien affichées
	 * @param in : entrée utilisateur
	 * @param needToBeDisplayed : liste des strings qui doivent s'afficher pour que le
	 * test passe
	 * @param debug : si vaut true, le déroulement du jeu est affiché
	 * @return true si le test est passé, false sinon
	*/
	static bool runTest(const std::istringstream& in,
							  const std::list<std::string>& needToBeDisplayed,
							  bool debug);
};

#endif // RIVIERE_TEST_HPP
