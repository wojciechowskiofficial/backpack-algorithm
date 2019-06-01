#include <iostream>

#include "Knapsack.h"
#include "Item.h"

Knapsack::Knapsack() {
	this->capasity = -1;
	this->contents = NULL;
	this->dyn = false;
	this->brute = false;
	this->greedy = false;
}

Knapsack::~Knapsack() {
	if (this->contents != NULL) {
		delete [] this->contents;
		this->contents = NULL;
	}
	this->capasity = -1;
	this->dyn = false;
	this->brute = false;
	this->greedy = false;
}
