
#include "SharedPointer.hpp"

// Public
template<typename T>
SharedPointer<T>::SharedPointer() : manager(nullptr) {
}

template<typename T>
SharedPointer<T>::SharedPointer(T* ptr): manager(new Manager(ptr)) {
}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer& other)
	: manager(other.manager) {
	if (manager) {
		manager->addReference();
	}
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other) {
	if (this != &other) {
		if (manager) {
			manager->removeReference();
		}
		if (manager) {
			manager = other.manager;
			manager->addReference();
		}
	}
	return *this;
}

template<typename T>
T& SharedPointer<T>::operator*() const {
	return *get();
}

template<typename T>
T* SharedPointer<T>::operator->() const {
	return get();
}

template<typename T>
bool SharedPointer<T>::operator==(const SharedPointer& other) const {
	return get() == other.get();
}

template<typename T>
bool SharedPointer<T>::operator!=(const SharedPointer& other) const {
	return get() != other.get();
}

template<typename T>
T* SharedPointer<T>::get() const {
	if (!manager)
		throw std::runtime_error("Dereferencing null pointer");

	return manager->ptr;
}

template<typename T>
std::size_t SharedPointer<T>::useCount() const {
	return manager ? manager->refCount : 0;
}

template<typename T>
SharedPointer<T>::~SharedPointer() {
	manager->removeReference();
}

// Private

// Manager
template<typename T>
SharedPointer<T>::Manager::Manager(T* ptr): ptr(ptr), refCount(1) {
}

template<typename T>
void SharedPointer<T>::Manager::addReference() {
	++refCount;
}

template<typename T>
void SharedPointer<T>::Manager::removeReference() {
	--refCount;
	if (refCount == 0) {
		delete ptr;
		delete this;
	}
}
