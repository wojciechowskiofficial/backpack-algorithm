#ifndef GENERATOR_H
#define GENERATOR_H

class Generator {
	public:
		Generator();
		~Generator();
		bool gen(int quantity, int max_value, int max_weight);
		Item * gen_arr;
};
#endif
