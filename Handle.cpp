#include <iostream>
#include <vector>
#include <algorithm>

#include "Handle.h"
#include "Item.h"
#include "Knapsack.h"
#include "Generator.h"

Handle::Handle() {
	this->generator = NULL;
	this->knapsack = NULL;
	this->gen_arr = NULL;
}

Handle::~Handle() {
	if (this->generator != NULL) {
		delete this->generator;
		this->generator = NULL;
	}
	if (this->knapsack != NULL) {
		delete this->knapsack;
		this->knapsack = NULL;
	}
	if (this->gen_arr != NULL) {
		delete [] this->gen_arr;
		this->gen_arr = NULL;
	}
}

//utility bool function for std::sort by object atributej
bool greedy_comp(Item a, Item b) {
	return a.vw_ratio > b.vw_ratio;
}

bool Handle::solve_greedy(int max_value, int max_weight, int quantity) {
	if (this->generator != NULL || this->knapsack != NULL || this->gen_arr != NULL) {
		return false;
	}
	this->generator = new Generator();
	this->generator->gen(max_value, max_weight, quantity);
	this->gen_arr = this->generator->gen_arr;
	delete this->generator;
	this->generator = NULL;
	std::vector<Item> utility_vec;
	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i].vw_ratio = (float) this->gen_arr[i].value / (float) this->gen_arr[i].weight;
		utility_vec.push_back(this->gen_arr[i]);
	}
	std::sort(utility_vec.begin(), utility_vec.end(), greedy_comp);
	delete [] this->gen_arr;
	this->gen_arr = NULL;
	this->gen_arr = new Item [quantity];
	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i] = utility_vec.at(i);
	}
	this->knapsack = new Knapsack();
	this->knapsack->capasity = quantity;
	this->knapsack->greedy = true;
	int curr_weight = 0, iterator = 0;

	while (curr_weight + utility_vec.at(iterator).weight <= this->knapsack->capasity) {
		this->knapsack->contents.push_back(utility_vec.at(iterator));
		curr_weight += utility_vec.at(iterator).weight;
		iterator++;
	}
	this->knapsack->real_weight = curr_weight;

}
