#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#include "Handle.h"
#include "Item.h"
#include "Knapsack.h"

Handle::Handle() {
	this->knapsack = NULL;
	this->gen_arr = NULL;
}

Handle::~Handle() {
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

void Handle::copy_gen_arr(Item * _gen_arr, int quantity) {
	this->gen_arr = new Item [quantity];
	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i].id = _gen_arr[i].id;
		this->gen_arr[i].weight = _gen_arr[i].weight;
		this->gen_arr[i].value = _gen_arr[i].value;
	}
}

bool Handle::solve_greedy(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr) {
	if (this->knapsack != NULL || this->gen_arr != NULL) {
		return false;
	}
	this->copy_gen_arr(_gen_arr, quantity);
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
	this->knapsack->capacity = _capacity;
	this->knapsack->greedy = true;
	int curr_weight = 0, iterator = 0;

	while (curr_weight + utility_vec.at(iterator).weight <= this->knapsack->capacity) {
		this->knapsack->contents.push_back(utility_vec.at(iterator));
		curr_weight += utility_vec.at(iterator).weight;
		iterator++;
	}
	this->knapsack->real_weight = curr_weight;
	return true;
}

int ret_max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

bool Handle::solve_dynamic(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr, bool print_arr = false) {
	if (this->knapsack != NULL || this->gen_arr != NULL) {
		return false;
	}
	int ** dyn_arr = new int * [quantity + 1];
	for (int i = 0; i < quantity + 1; i++) {
		dyn_arr[i] = new int [_capacity + 1];
	}

	for (int i = 0; i < quantity + 1; i++) {
		dyn_arr[i][0] = 0;
	}
	for (int i = 0; i < _capacity + 1; i++) {
		dyn_arr[0][i] = 0;
	}

	this->knapsack = new Knapsack();
	this->knapsack->capacity = _capacity;
	this->knapsack->dyn = true;
	this->gen_arr = _gen_arr;

	/*
	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i].show();
	}
	*/

	for (int i = 1; i < quantity + 1; i++) {
		for (int j = 1; j < _capacity + 1; j++) {
			if (j < this->gen_arr[i - 1].weight) {
				dyn_arr[i][j] = dyn_arr[i - 1][j];
			}
			else {
				dyn_arr[i][j] = ret_max(this->gen_arr[i - 1].value + dyn_arr[i - 1][j - this->gen_arr[i - 1].weight]
						, dyn_arr[i - 1][j]);
			}
		}
	}

	int iteri = quantity, iterj = _capacity;
	while (iteri > 0) {
		if (dyn_arr[iteri][iterj] == dyn_arr[iteri - 1][iterj]) {
			iteri--;
			continue;
		}
		else {
			this->knapsack->contents.push_back(this->gen_arr[iteri - 1]);
			iterj -= this->gen_arr[iteri - 1].weight;
			iteri--;
		}
	}

	if (print_arr) {
		for (int i = 0; i < quantity + 1; i++) {
			for (int j = 0; j < _capacity + 1; j++) {
				std::cout << dyn_arr[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < quantity + 1; i++) {
		delete [] dyn_arr[i];
		dyn_arr[i] = NULL;
	}
	delete [] dyn_arr;
	dyn_arr = NULL;
	return true;
}

bool Handle::solve_brute(int max_value, int max_weight, int quantity, int _capacity, Item * _gen_arr) {
	if (this->knapsack != NULL || this->gen_arr != NULL) {
		return false;
	}
	this->copy_gen_arr(_gen_arr, quantity);
	this->knapsack = new Knapsack();
	this->knapsack->capacity = _capacity;
	int * arr = new int [quantity];
	for (int i = 0; i < quantity; i++) {
		arr[i] = i;
	}
	std::stack<int> comb_stack;
	int curr_weight = 0, curr_value = 0, best_value = 0;
	for (unsigned i = (1 << quantity); --i;) {
		for (unsigned k = 0; k < quantity; ++k) {
			if ((i >> k) & 1) {
				comb_stack.push(arr[k]);
				curr_value += this->gen_arr[k].value;
				curr_weight += this->gen_arr[k].weight;
			}
		}
		if (curr_value > best_value && curr_weight <= this->knapsack->capacity) {
			this->knapsack->contents.clear();
			best_value = curr_value;
			while (!comb_stack.empty()) {
				int current = comb_stack.top();
				this->knapsack->contents.push_back(this->gen_arr[current]);
				comb_stack.pop();
			}
		}
		curr_weight = 0;
		curr_value = 0;
		while (!comb_stack.empty()) {
			comb_stack.pop();
		}
	}
	//do usuniecia genarr generatora
	return true;
}
