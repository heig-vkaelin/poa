//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef EXERCICES_ARRAY_HPP
#define EXERCICES_ARRAY_HPP

#include <cstdlib>

template<typename T>
class Array {
public:
	class Iterator {
		friend class Array;

	public:
		T& operator*() const;

		Iterator& operator++();

		Iterator operator++(int);

		bool operator!=(const Iterator& other);

		bool operator==(const Iterator& other);

		T* operator->() const;

	private:
		T* ptr;

		explicit Iterator(T* data);
	};

	Array();

	explicit Array(std::size_t size);

	Array(std::initializer_list<T> args);

	Array(const Array& other);

	~Array();

	Array& operator=(const Array& other);

	T& operator[](std::size_t i);

	const T& operator[](std::size_t i) const;

	std::size_t size() const;

	Iterator begin();

	Iterator end();

private:
	T* data;
	std::size_t length;

	void init(std::size_t size, T* src = nullptr);

	void destroy();

	T& at(std::size_t i) const;
};

#include "Array_Impl.hpp"

#endif // EXERCICES_ARRAY_HPP
