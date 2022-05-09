//
// Created by Valentin Kaelin on 31.03.22.
//

#ifndef EXERCICES_SEASON_HPP
#define EXERCICES_SEASON_HPP

#include <cstdlib>

class Season {
public:
	Season(const Season& other) = delete;

	Season& operator=(const Season& other) = delete;

	static const Season Spring;
	static const Season Summer;
	static const Season Autumn;
	static const Season Winter;

	static std::size_t size();

	static const Season& get(std::size_t index);

	static const Season** values();

	const char* name() const;

	std::size_t index() const;

	const Season& next() const;

private:
	explicit Season(const char* n);

	static const Season* seasons[];

	~Season();

	static std::size_t counter;
	const char* _name;
	std::size_t ord;
};

#endif // EXERCICES_SEASON_HPP
