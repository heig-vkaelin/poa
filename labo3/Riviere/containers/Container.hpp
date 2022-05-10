#ifndef RIVIERE_CONTAINER_HPP
#define RIVIERE_CONTAINER_HPP

#include <string>
#include <list>
#include <iostream>
#include "../people/Person.hpp"
#include "../people/ErrorStatus.hpp"

/**
 * Classe abstraite représentant une conteneur de tout type
 * Ce conteneur peut contenir un nombre inderterminé de personnes
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Container;

/**
 * Affiche un conteneur dans un stream
 * @param os stream dans lequel afficher le conteneur
 * @param container conteneur souhaité
 * @return le stream avec le conteneur affiché
 */
std::ostream& operator<<(std::ostream& os, const Container& container);

class Container {
public:
	/**
	 * Crée un nouveau conteneur
	 * @param name : nom du conteneur
	 */
	explicit Container(const std::string& name);

	/**
	 * Ajoute une personne au conteneur
	 * @param person : pointeur sur la personne à ajouter
	 * @return true si l'opération a été effectuée, false sinon
	 */
	virtual bool addPerson(const Person& person);

	/**
	 * Ajoute plusieurs personnes au conteneur
	 * @param list : liste des personnes à ajouter
	 */
	void addPeople(const std::list<const Person*>& list);

	/**
	 * Supprime la personne du conteneur (si elle se trouve à l'intérieur)
	 * @param person  : la personne à supprimer
	 */
	void removePerson(const Person& person);

	/**
	 * @return true si le conteneur est vide, false sinon
	 */
	bool empty() const;

	/**
	 * @return le nombre de personnes dans le conteneur
	 */
	std::size_t size() const;

	/*
	 * Enlève toutes les personnes du conteneur
	 */
	void clear();

	/**
	 * @return le nom du conteneur
	 */
	const std::string& getName() const;

	/**
	 * Cherche une personne par son nom
	 * @param name : nom de la personne recherchée
	 * @return un pointeur sur la personne si elle est dans le conteneur, nullptr
	 * sinon
	 */
	const Person* findByName(const std::string& name) const;

	/**
	 * Vérifie l'état des personnes dans le conteneur
	 * @return le status du conteneur contenant OK s'il est valide et l'erreur sinon
	 */
	ErrorStatus isValid() const;

	/**
	 * Affiche le conteneur sur le stream souhaité
	 * @param os : stream sur lequel afficher le conteneur
	 * @return le stream avec les infos du conteneur
	 */
	virtual std::ostream& toStream(std::ostream& os) const = 0;

	/**
	 * @return un itérateur constant sur la première personne du conteneur
	 */
	std::list<const Person*>::const_iterator begin() const;

	/**
	 * @return un itérateur constant après la dernière personne du conteneur
	 */
	std::list<const Person*>::const_iterator end() const;

	/**
	 * Destructeur virtuel afin de pouvoir être override
	 */
	virtual ~Container() = default;

protected:
	/**
	 * Vérifie si une personne est déjà dans le conteneur
	 * @param person : personne à vérifier
	 * @return true si la personne est là, false sinon
	 */
	bool contains(const Person& person) const;

	/**
	 * @return les personnes contenues sous représentation textuelle
	 */
	std::string peopleToString() const;

	/**
	 * @return les personnes dans le conteneur
	 */
	const std::list<const Person*>& getPeople() const;

private:
	std::string name;
	std::list<const Person*> people;
};

#endif // RIVIERE_CONTAINER_HPP
