#include <vector>

#include "Item.h"

#ifndef KNAPSACK_H
#define KNAPSACK_H

class Knapsack {
	public:
		Knapsack();
		~Knapsack();
		std::vector<Item> contents;
		void show();
		int capasity;
		int real_weight;
		bool dyn, brute, greedy;
};
#endif
