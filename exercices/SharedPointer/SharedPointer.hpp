#ifndef EXERCICES_SHAREDPOINTER_HPP
#define EXERCICES_SHAREDPOINTER_HPP

template<typename T>
class SharedPointer {
public:
	SharedPointer();

	explicit SharedPointer(T* ptr);

	SharedPointer(const SharedPointer& other);

	SharedPointer& operator=(const SharedPointer& other);

	T& operator*() const;

	T* operator->() const;

	bool operator==(const SharedPointer& other) const;

	bool operator!=(const SharedPointer& other) const;

	T* get() const;

	std::size_t useCount() const;

	~SharedPointer();

private:
	class Manager {
	public:
		explicit Manager(T* ptr);

		~Manager();

		T* ptr;
		std::size_t refCount;
	};

	void addReference();

	void removeReference();

	Manager* manager;
};

#include "SharedPointer_Impl.hpp"

#endif // EXERCICES_SHAREDPOINTER_HPP
