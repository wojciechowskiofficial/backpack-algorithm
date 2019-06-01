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
	std::cout << "[ id:\t" << this->id << " value:\t" << this->value << " weight:\t" 
		<< this->weight << " value/weight ratio:\t" 
		<< this->vw_ratio << "]" << std::endl;
}
