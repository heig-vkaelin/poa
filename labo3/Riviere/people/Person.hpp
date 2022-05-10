#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <string>
#include "ErrorStatus.hpp"

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
	virtual bool canDrive() const;

	/**
	 * Vérifie si l'état du conteneur vérifie les contraintes de la personne
	 * @param container : le conteneur à vérifier
	 * @return true si les contraintes sont bien vérifiées, false sinon
	 */
	virtual bool isStateValid(const Container& container) const = 0;

	/**
	 * @return le status d'erreur de la personne si celle-ci ne se trouve pas dans
	 * un conteneur valide
	 */
	virtual ErrorStatus getErrorStatus() const = 0;

	/**
	 * @return le nom de la personne
	 */
	std::string getName() const;

	/**
	 * Destructeur par défaut comme les personnes n'allouent pas de mémoire
	 * dynamiquement
	 */
	virtual ~Person() = default;

private:
	std::string name;
};

#endif // RIVIERE_PERSON_HPP
