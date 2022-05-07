#include <stdexcept>
#include "Array.hpp"

// Public methods

template<typename T>
Array<T>::Array(std::size_t size) {
	init(size);
}

template<typename T>
Array<T>::Array(const Array& o) {
	init(o._size);
	for (std::size_t i = 0; i < _size; i++) {
		data[i] = o.data[i];
	}
}

template<typename T>
Array<T>::Array(std::initializer_list<T> args) {
	init(args.size());
	int i = 0;
	auto end = args.end();
	for (const T* val = args.begin(); val != end; ++val, ++i) {
		data[i] = *val;
	}
}

template<typename T>
Array<T>::~Array() {
	destroy();
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& o) {
	if (this != &o) {
		destroy();
		init(o._size);
		for (std::size_t i = 0; i < _size; i++) {
			data[i] = o.data[i];
		}
	}
	return *this;
}

template<typename T>
std::size_t Array<T>::size() const {
	return _size;
}

template<typename T>
T& Array<T>::operator[](std::size_t i) {
	return at(i);
}

template<typename T>
const T& Array<T>::operator[](std::size_t i) const {
	return at(i);
}

template<typename T>
typename Array<T>::Iterator Array<T>::begin() {
	return Iterator(data);
}

template<typename T>
typename Array<T>::Iterator Array<T>::end() {
	return Iterator(data + _size);
}

// Private methods

template<typename T>
void Array<T>::init(std::size_t size) {
	_size = size;
	data = new T[size];
}

template<typename T>
void Array<T>::destroy() {
	delete[] data;
}

template<typename T>
T& Array<T>::at(std::size_t i) {
	if (i >= _size)
		throw std::out_of_range("Index out of range");

	return data[i];
}

// Iterator class

template<typename T>
Array<T>::Iterator::Iterator(T* ptr) : ptr(ptr) {
}

template<typename T>
T& Array<T>::Iterator::operator*() const {
	return *ptr;
}

template<typename T>
typename Array<T>::Iterator& Array<T>::Iterator::operator++() {
	++ptr;
	return *this;
}

template<typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator++(int) {
	Iterator tmp = *this;
	++ptr;
	return tmp;
}

template<typename T>
bool Array<T>::Iterator::operator==(const Iterator& o) const {
	return ptr == o.ptr;
}

template<typename T>
bool Array<T>::Iterator::operator!=(const Iterator& o) const {
	return ptr != o.ptr;
}
