#include <iostream>

#include "Item.h"
#include "Knapsack.h"

#ifndef HANDLE_H
#define HANDLE_H

class Handle {
	public:
		Handle();
		~Handle();
		Knapsack * knapsack;
		Item * gen_arr;
		bool solve_greedy(int max_value, int max_weight, int quantity, int _capasity, Item * _gen_arr);
		bool solve_dynamic(int max_value, int max_weight, int quantity, int _capasity, Item * _gen_arr, bool print_arr);
};

#endif
