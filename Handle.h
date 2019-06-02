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
		void copy_gen_arr(Item * _gen_arr, int quantity);
		bool solve_greedy(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr);
		bool solve_dynamic(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr, bool print_arr);
		bool solve_brute(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr);
};

#endif
