#include <iostream>

#include "Knapsack.h"
#include "Item.h"

Knapsack::Knapsack() {
	this->capacity = -1;
	this->dyn = false;
	this->brute = false;
	this->greedy = false;
	this->real_weight = -1;
}

Knapsack::~Knapsack() {
	this->capacity = -1;
	this->dyn = false;
	this->brute = false;
	this->greedy = false;
	this->real_weight = -1;
}

void Knapsack::show() {
	for (int i = 0; i < this->contents.size(); i++) {
		this->contents.at(i).show();
	}
}
