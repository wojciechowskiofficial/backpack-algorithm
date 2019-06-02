#include <iostream>

#include "Item.h"

Item::Item() {
	this->value = -1;
	this->weight = -1;
	this->id = -1;
	this->vw_ratio = -1;
}

Item::~Item() {
	this->value = -1;
	this->weight = -1;
	this->id = -1;
	this->vw_ratio = -1;
}

void Item::show() {
	std::cout << "[ id:" << this->id << "\tvalue:\t" << this->value << "\tweight:\t" 
		<< this->weight << "\tvalue/weight ratio:" 
		<< this->vw_ratio << " ]" << std::endl;
}
