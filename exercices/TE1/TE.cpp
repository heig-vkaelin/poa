// Nom : Valentin Kaelin

#include <iostream>
#include <string>

using namespace std;

class Town {
public:
	Town(const Town& other) = delete;

	Town& operator=(const Town& other) = delete;

	static const Town
		lausanne,
		geneve,
		yverdon,
		berne;

	size_t index() const {
		return _index;
	}

	string name() const {
		return _name;
	}

	static size_t size() {
		return counter;
	}

private:
	explicit Town(const char* name)
		: _name(name), _index(counter++) {
	}

	const string _name;
	const size_t _index;
	static size_t counter;
};

size_t Town::counter = 0;

const Town Town::lausanne("Lausanne");
const Town Town::geneve("Geneve");
const Town Town::yverdon("Yverdon");
const Town Town::berne("Berne");

class Bird {
public:
	Bird(const char* name) : _name(name) {}

	virtual ~Bird() = default;

	string name() const {
		return _name;
	}

	virtual void fly() {
		displayMessage(message());
	}

	static void displayMessage(const string& message) {
		cout << message << endl;
	}

protected:
	string message() const {
		return "Flap! " + _name + " flies";
	}

private:
	const string _name;
};

class Pigeon : public Bird {
public:
	Pigeon(const char* name, const Town& home)
		: Bird(name), _home(&home), _destination(nullptr),
		  _visits(new const Town* [Town::size()]) {
		visitTown(&home);
	}

	~Pigeon() override {
		delete[] _visits;
	}

	void setDestination(const Town& destination, const char* message) {
		_destination = &destination;
		_message = message;
	}

	void fly() override {
		if (_town == _home)
			visitTown(_destination, messageLeavingHome());
		else
			visitTown(_home, messageComingHome());
	}

	void printVisits() const {
		cout << name() << " visits: ";
		for (size_t i = 0; i < Town::size(); i++) {
			if (_visits[i] != nullptr)
				cout << _visits[i]->name() << " ";
		}
		cout << endl;
	}

private:
	void visitTown(const Town* town, const string& message = "") {
		if (town == nullptr)
			throw runtime_error("Ville invalide pour le pigeon");

		if (!message.empty())
			displayMessage(message);

		for (size_t i = 0; i < Town::size(); i++) {
			if (_visits[i] == nullptr) {
				_visits[i] = town;
				break;
			} else if (_visits[i] == town) {
				break;
			}
		}
		_town = town;
	}

	string messageLeavingHome() const {
		return message() + " to " + _destination->name()
				 + " and says '" + _message + "'";
	}

	string messageComingHome() const {
		return message() + " back " + _home->name();
	}

	string _message;
	const Town* _town;
	const Town* _home;
	const Town* _destination;
	const Town** _visits;
};

int main() {
	Bird o1("Titi");
	Pigeon p1("Plip", Town::lausanne);
	Pigeon p2("Glop", Town::yverdon);

	p1.setDestination(Town::geneve, "Bonjour Geneve");
	p2.setDestination(Town::berne, "Hallo Bern");

	Bird* birds[] = {&o1, &p1, &p2};

	for (int i = 0; i < 2; i++) {
		cout << "-- " << endl;
		for (Bird* b: birds)
			b->fly();
	}

	cout << "---" << endl;
	p1.setDestination(Town::yverdon, "Salut Yverdon");
	p1.fly();

	cout << "---" << endl;
	p1.printVisits();
}

