#ifndef RIVIERE_CONTAINER_HPP
#define RIVIERE_CONTAINER_HPP

#include <string>
#include <list>
#include <iostream>
#include "../people/Person.hpp"

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
	bool addPerson(const Person& person);

	/**
	 * Ajoute plusieurs personnes au conteneur
	 * @param list : liste des personnes à ajouter
	 */
	void addPeople(const std::list<const Person*>& list);

	/**
	 * @return true si le conteneur est vide, false sinon
	 */
	bool empty() const;

	/*
	 * Enlève toutes les personnes du conteneur
	 */
	void clear();

	/**
	 * @return le nom du conteneur
	 */
	const std::string& getName() const;

	/**
	 * Cherche une personne par so nom
	 * @param name : nom de la personne recherchée
	 * @return un pointeur sur la personne si elle est dans le conteneur, nullptr
	 * sinon
	 */
	const Person* findByName(const std::string& name) const;

	/**
	 * Affiche le conteneur sur le stream souhaité
	 * @param os : stream sur lequel afficher le conteneur
	 * @return le stream avec les infos du conteneur
	 */
	virtual std::ostream& toStream(std::ostream& os) const = 0;

	virtual ~Container() = default;

	/**
	 * @return les personnes dans le conteneur
	 */
	// TODO: en public pour le moment psk facilite mais faudra modif
	const std::list<const Person*>& getPeople() const;

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

private:
	std::string name;
	std::list<const Person*> people;
};

#endif // RIVIERE_CONTAINER_HPP
