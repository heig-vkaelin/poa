//
// Created by Valentin Kaelin on 31.03.22.
//

#ifndef EXERCICES_SEASON_HPP
#define EXERCICES_SEASON_HPP

class Season {
public:
	static const Season& Spring;
	static const Season& Summer;
	static const Season& Autumn;
	static const Season& Winter;

	static int size();

	static const Season& get(int index);

	static const Season** values();

	const char* name() const;

	int index() const;

	const Season& next() const;

	~Season();

private:
	explicit Season(const char* n);

	static const Season* seasons[];

	static int counter;
	const char* _name;
	int ord;
};

#endif // EXERCICES_SEASON_HPP
