#include "Item.h"

#ifndef KNAPSACK_H
#define KNAPSACK_H

class Knapsack {
	public:
		Knapsack();
		~Knapsack();
		Item * contents;
		int capasity;
		bool dyn, brute, greedy;
};
#endif
