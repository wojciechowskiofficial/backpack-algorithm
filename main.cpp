#include <iostream>

#include "Item.h"
#include "Generator.h"
#include "Knapsack.h"
#include "Handle.h"

int main() {
	Handle * test = new Handle();
	test->solve_greedy(10, 10, 10);
	delete test;
	test = NULL;
	return 0;
}
