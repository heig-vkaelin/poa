#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <string>

class Container;

/**
 * Classe abstraite représentant une personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Person {
public:
	/**
	 * Crée une personne avec un nom
	 * @param name : nom de la personne
	 */
	explicit Person(const std::string& name);

	/**
	 * @return true si la personne peut conduire le bâteau, false sinon
	 */
	virtual bool canDrive() const = 0;

	/**
	 * Vérifie si l'état du conteneur vérifie les contraintes de la personne
	 * @param container : le conteneur à vérifier
	 * @return true si les contraintes sont bien vérifiées, false sinon
	 */
	virtual bool isStateValid(const Container& container) const = 0;

	/**
	 * @return le nom de la personne
	 */
	std::string getName() const;

private:
	std::string name;
};

#endif // RIVIERE_PERSON_HPP
