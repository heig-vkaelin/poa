//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef EXERCICES_ARRAY_HPP
#define EXERCICES_ARRAY_HPP

#include <cstdlib>


template<typename T>
class Array {
	class Iterator;
public:
	explicit Array(std::size_t size);

	Array(const Array& o);

	~Array();

	Array& operator=(const Array& o);

	T& operator[](std::size_t index);

	std::size_t size() const;

	Iterator begin();

	Iterator end();

private:
	class Iterator {
	public:
		explicit Iterator(T* ptr);

		Iterator& operator++();


		Iterator operator++(int);

		bool operator==(const Iterator& o) const;

		bool operator!=(const Iterator& o) const;

		T& operator*() const;

	private:
		T* ptr;
	};

	void init(std::size_t size);

	void destroy();

	std::size_t _size;
	T* data;
};

#include "Array_impl.hpp"

#endif // EXERCICES_ARRAY_HPP
