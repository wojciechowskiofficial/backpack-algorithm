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
	this->generator = NULL;
	this->knapsack = NULL;
	this->gen_arr = NULL;
}

bool Handle::greedy_comp(Item a, Item b) {
	return a.vw_ratio < b.vw_ratio;
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
	std::vector<Item> wektor;

	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i].vw_ratio = (float) this->gen_arr[i].value / (float) this->gen_arr[i].weight;
		this->gen_arr[i].show();
		wektor.push_back(this->gen_arr[i]);
	}
	
	std::sort(wektor.begin(), wektor.end(), this->greedy_comp);

}
