//
// Created by Valentin Kaelin on 28.05.22.
//

#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

/**
 * Classe Position
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Position {
public:
	/**
	 * Constructeur de la classe Position
	 */
	Position();

	/**
	 * Constructeur de la classe Position
	 * @param x Position x
	 * @param y Position y
	 */
	Position(int x, int y);

	/**
	 * Méthode permettant de récupérer la position x
	 * @return Position x
	 */
	int getX() const;

	/**
	 * Méthode permettant de récupérer la position y
	 * @return Position y
	 */
	int getY() const;

	/**
	 * Méthode permettant de déplacer la position en y ajoutant une autre
	 * @param other Position à ajouter
	 * @return Position déplacée
	 */
	Position& add(const Position& other);

	/**
	 * Méthode permettant de déplacer la position en y ajoutant une autre (sans modifier la
	 * position actuelle)
	 * @param other Position à ajouter
	 * @return Position déplacée
	 */
	Position addVal(const Position& other) const;

	/**
	 * Méthode permettant de déplacer la position en la multipliant par un facteur
	 * @param factor Facteur de multiplication
	 * @return Position déplacée
	 */
	Position& multiply(int factor);

	/**
	 * Méthode permettant de déplacer la position en la multipliant par un facteur (sans modifier
	 * la position actuelle)
	 * @param factor Facteur de multiplication
	 * @return Position déplacée
	 */
	Position multiplyVal(int factor) const;

	/**
	 * Méthode permettant de récupérer la direction d'une position en fonction d'une autre
	 * @param to Position à comparer
	 * @return Direction de la position
	 */
	Position getDirection(const Position& to) const;

	/**
	 * Méthode permettant de récupérer la distance d'une position en fonction d'une autre
	 * @param to Position à comparer
	 * @return Distance de la position
	 */
	int getDistance(const Position& to) const;

	/**
	 * Méthode permettant de récupérer une position aléatoire
	 * @param maxX Borne max de la position x
	 * @param maxY Borne max de la position y
	 * @return Position aléatoire
	 */
	static Position getRandomPosition(int maxX, int maxY);

	/**
	 * Différente direction possible
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
