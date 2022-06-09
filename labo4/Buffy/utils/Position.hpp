#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

/**
 * Classe Position représentant une position dans la simulation en 2 dimensions
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Position {
public:
	/**
	 * Crée une nouvelle position aux coordonnées (0, 0)
	 */
	Position();

	/**
	 * Crée une position aux coordonnées souhaitées
	 * @param x : coordonnée x
	 * @param y : coordonnée y
	 */
	Position(int x, int y);

	/**
	 * @return la coordonnée x
	 */
	int getX() const;

	/**
	 * @return la coordonnée y
	 */
	int getY() const;

	/**
	 * Ajoute une Position à celle-ci
	 * @param other : position à ajouter
	 * @return position initiale modifiée
	 */
	Position& add(const Position& other);

	/**
	 * Récupérer la direction permettant d'aller à la position souhaitée
	 * @param to : position d'arrivée souhaitée
	 * @return la direction
	 */
	Position getDirection(const Position& to) const;

	/**
	 * Calcule la distance jusqu'à la position souhaitée
	 * @param to : position d'arrivée souhaitée
	 * @return la distance
	 */
	int getDistance(const Position& to) const;

	/**
	 * Génère une position aléatoire
	 * @param maxX : borne max de la position x
	 * @param maxY : borne max de la position y
	 * @return la position aléatoire créée
	 */
	static Position getRandomPosition(int maxX, int maxY);

	/**
	 * Différentes directions possibles
	 */
	static const Position
		UP,
		UP_LEFT,
		LEFT,
		DOWN_LEFT,
		DOWN,
		DOWN_RIGHT,
		RIGHT,
		UP_RIGHT;

private:
	int x;
	int y;
};

#endif // BUFFY_POSITION_HPP
