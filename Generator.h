#ifndef GENERATOR_H
#define GENERATOR_H

class Generator {
	public:
		Generator();
		bool gen(int max_value, int max_weight, int quantity);
		Item * gen_arr;
};
#endif
