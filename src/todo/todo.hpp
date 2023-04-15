#ifndef TODO_HPP
#define TODO_HPP

#include <iostream>

using std::string;

class Todo {
	private:
		string name;

	public:
		Todo(string name) : name(name) {};

		string getName() {
			return name;
		}
};

#endif