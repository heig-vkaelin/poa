#ifndef SQUADRON_SQUADRON_HPP
#define SQUADRON_SQUADRON_HPP

#include "ships/Ship.hpp"

/**
 * Classe représentant une escadrille de divers vaisseaux pouvant être mise à jour
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Squadron;

/**
 * Ajoute un vaisseau dans une copie de l'escadrille
 * @param ship : vaisseau à ajouter
 * @return la nouvelle escadrille
 */
Squadron operator+(const Squadron& squadron, Ship& ship);

/**
 * Supprime un vaisseau dans une copie de l'escadrille
 * @param ship : vaisseau à supprimer
 * @return la nouvelle escadrille
 */
Squadron operator-(const Squadron& squadron, Ship& ship);

/**
 * Affiche l'escadrille sur le stream souhaité
 * @param os : stream sur lequel afficher l'escadrille
 * @param squad : escadrille à afficher
 * @return le stream avec l'escadrille affichée
 */
std::ostream& operator<<(std::ostream& os, const Squadron& squad);

class Squadron {

public:
	/**
	 * Créée une escadrille avec un nom
	 * @param name : nom de l'escadrille
	 */
	explicit Squadron(const std::string& name);

	/**
	 * Détruit l'escadrille
	 */
	~Squadron();

	/**
	 * Créée une escadrille en copiant l'autre.
	 * La nouvelle escadrille contiendra les mêmes vaisseaux.
	 *
	 * @param squad : l'escadrille à copier
	 */
	Squadron(const Squadron& squad);

	/**
	 * Opérateur d'affectation prenant la référence d'une autre escadrille
	 * @param squad : l'escadrille à copier
	 * @return la référence de l'escadrille dupliquée
	 */
	Squadron& operator=(const Squadron& squad);

	/**
	 * Ajoute un vaisseau à l'escadrille
	 * @param ship : vaisseau à ajouter
	 * @return l'escadrille modifiée
	 */
	Squadron& addShip(Ship& ship);

	/**
	 * Ajoute un vaisseau dans une copie de l'escadrille
	 * @param ship : vaisseau à ajouter
	 * @return la nouvelle escadrille
	 */
	Squadron addShipCopy(Ship& ship) const;

	/**
	 * Supprime un vaisseau de l'escadrille
	 * @param ship : vaisseau à supprimer
	 * @return l'escadrille modifiée
	 */
	Squadron& removeShip(Ship& ship);

	/**
	 * Supprime un vaisseau dans une copie de l'escadrille
	 * @param ship : vaisseau à supprimer
	 * @return la nouvelle escadrille
	 */
	Squadron removeShipCopy(Ship& ship) const;

	/**
	 * Ajoute un vaisseau à l'escadrille
	 * @param ship : vaisseau à ajouter
	 * @return l'escadrille modifiée
	 */
	Squadron& operator+=(Ship& ship);

	/**
	 * Supprime un vaisseau à l'escadrille
	 * @param ship : vaisseau à supprimer
	 * @return l'escadrille modifiée
	 */
	Squadron& operator-=(Ship& ship);

	/**
	 * Accès indexé à un vaisseau
	 * @param index du vaisseau à retourner
	 * @return le vaisseau cherché
	 * @throws out_of_range si l'index est trop grand
	 */
	const Ship& get(std::size_t index) const;

	/**
	 * Accès indexé à un vaisseau
	 * @param index du vaisseau à retourner
	 * @return le vaisseau cherché
	 * @throws out_of_range si l'index est trop grand
	 */
	const Ship& operator[](std::size_t index) const;

	/**
	 * @return le nom de l'escadrille
	 */
	const std::string& getName() const;

	/**
	 * Modifie le nom de l'escadrille
	 * @param name : nouveau nom
	 */
	void setName(const std::string& name);

	/**
	 * Modifie le leader de l'escadrille.
	 * Le vaisseau est également ajouté à l'escadrille s'il n'en faisait pas partie.
	 * @param ship : vaisseau du nouveau leader
	 */
	void setLeader(Ship& ship);

	/**
	 * Supprime le leader actuel de l'escadrille.
	 * Le leader reste membre de l'escadrille.
	 */
	void removeLeader();

	/**
	 * Calcule la consommation totale de l'escadrille pour l'opération souhaitée
	 * @param distance : distance de l'opération en [millions de km]
	 * @param speed : vitesse des vaisseaux lors de l'opération en [MGLT]
	 * @return le nombre de [tonnes] consommées
	 * @throws invalid_argument si la distance ou la vitesse est invalide ou si le
	 * squadron ne contient aucun vaisseau
	 */
	double computeConsumption(double distance, double speed) const;

	/**
	 * Affiche l'escadrille sur le stream souhaité
	 * @param os : le stream sur lequel afficher le squadron
	 * @return le stream modifié
	 */
	std::ostream& toStream(std::ostream& os) const;

private:
	void init(const std::string& name, Ship* leader);

	void copyShips(const Squadron& squad);

	void freeSquadron();

	struct Member;

	std::string name;
	std::size_t size;
	Ship* leader;
	Member* head;
};

#endif // SQUADRON_SQUADRON_HPP
