#include <iostream>

#include "Item.h"
#include "Knapsack.h"
#include "Generator.h"

#ifndef HANDLE_H
#define HANDLE_H

class Handle {
	public:
		Handle();
		~Handle();
		Generator * generator;
		Knapsack * knapsack;
		Item * gen_arr;
		bool solve_greedy(int max_value, int max_weight, int quantity);
	private:
		bool greedy_comp(Item a, Item b);
};

#endif
