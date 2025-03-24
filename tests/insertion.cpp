// Copyright (c) 2016 Andrew Sutton
// All rights reserved

#include <queue.hpp>

#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

int main()
{
	// Randomize a list of weights.
	std::vector<int> distance(10);
	std::iota(distance.begin(), distance.end(), 0);
	std::random_shuffle(distance.begin(), distance.end());

	std::cout << "distances: ";
	for (int d : distance)
		std::cout << d << ' ';
	std::cout << '\n';

	// Make a label for the vector.
	auto dist = origin::vertex_label(distance);

	// FIXME: Can we do this without decltype?
	using C = origin::compare_vertex_label<decltype(dist), std::less<int>>;
	using Q = origin::insertion_queue<origin::vertex_t, C>;

	C comp(dist);
	Q queue(comp);

	for (int i = 0; i < 10; ++i)
	{
		queue.push(i);
		std::cout << "insert " << i << " (" << dist(i) << ")\n";
		for (int n : queue.data())
			std::cout << n << " (" << dist(n) << ") ";
		std::cout << '\n';
	}

}
