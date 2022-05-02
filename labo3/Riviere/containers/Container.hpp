//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_CONTAINER_HPP
#define RIVIERE_CONTAINER_HPP

#include <string>
#include <list>
#include <iostream>
#include "../persons/Person.hpp"

class Container;

/**
 * Affiche un conteneur dans un flux
 * @param os flux dans lequel afficher le conteneur
 * @param container conteneur souhaité
 * @return le flux avec le conteneur affiché
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
	bool addPerson(const Person* person);

	/**
	 * Ajoute plusieurs personnes au conteneur
	 * @param list : liste des personnes à ajouter
	 */
	void addPersons(const std::list<const Person*>& list);

	/*
	 * Enlève toutes les personnes du conteneur
	 */
	void clear();

	/**
	 * @return le nom du conteneur
	 */
	const std::string& getName() const;

	/**
	* Ajoute le conteneur dans un flux
	* @param os flux souhaité
	* @return le flux avec le conteneur inséré
	*/
	virtual std::ostream& toStream(std::ostream& os) const = 0;

	virtual ~Container() = default;

protected:
	/**
	 * Vérifie si une personne est déjà dans le conteneur
	 * @param person : personne à vérifier
	 * @return true si la personne est là, false sinon
	 */
	bool contains(const Person* person) const;

	std::string personsToString() const;

private:
	std::string name;
	std::list<const Person*> persons;
};


#endif // RIVIERE_CONTAINER_HPP
