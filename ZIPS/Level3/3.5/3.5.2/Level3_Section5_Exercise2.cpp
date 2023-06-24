#include"command.h"
#include <functional>
#include <queue>

int main() {

	// Part a

    //implementation of the compare operator in a lambda function
	auto compare = [](Command l, Command r) {return l.priority() > r.priority(); };

	// Part b

	// function (wrapped) for the commands
	std::function<double(double)> plus_one = [](double x) {return x + 1; };

	// creating several instances of command
	Command c1(plus_one, 1);
	Command c2(plus_one, 3);
	Command c3(plus_one, 2);

	// Part c

	// priority queue of commands
	std::priority_queue<Command, std::vector<Command>, decltype(compare)> queue(compare);

	// inserting commands in queue
	queue.push(c1);
	queue.push(c2);
	queue.push(c3);

	// Part d

    //iterating through the queue until empty
	for (; !queue.empty(); queue.pop()) {
		queue.top().Execute(3.14);
	}
}


