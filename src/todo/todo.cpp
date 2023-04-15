#include <cmath>
/* #include <memory>
#include <vector>
#include "todo.hpp"

using std::shared_ptr;
using std::vector;

vector<shared_ptr<Todo>> todos = {};

__attribute__((export_name("add")))
vector<shared_ptr<Todo>> add(shared_ptr<Todo> todo) {
	todos.push_back(todo);

	return todos;
} */

__attribute__((export_name("deg_to_rad")))
double deg_to_rad(int d) {
	return d * M_PI / 180;
}