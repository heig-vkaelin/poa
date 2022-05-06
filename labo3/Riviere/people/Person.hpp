#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <list>
#include <string>

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

	// TODO: abstract = 0
	/**
	 * Vérifie si l'état du conteneur vérifie les contraintes de la personne
	 * @param peopleInContainer : liste des personnes dans le conteneur
	 * @return true si les contraintes sont bien vérifiées, false sinon
	 */
	virtual bool isStateValid(std::list<Person*> peopleInContainer) const
	{return true;};

	/**
	 * @return le nom de la personne
	 */
	std::string getName() const;

private:
	std::string name;
};

#endif // RIVIERE_PERSON_HPP
