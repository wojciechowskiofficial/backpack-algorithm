#include <fstream>
#include <ctime>

#include "Handle.h"
#include "Generator.h"
#include "Measure.h"

void Measure::measure() {
	clock_t begin, end;
	std::fstream out;
	out.open("knapsack.txt", std::ios::out);
	Generator * generator;
	Handle * handle;
	int size = 10000;
	bool safety_bit;

	for (int i = 0; i < 20; i++) {
		handle = new Handle();
		generator = new Generator();
		generator->gen(size, size, size);
		begin = clock();
		safety_bit = handle->solve_greedy(size, size, size, size, generator->gen_arr);
		end = clock();
		while (!safety_bit) {
			delete handle;
			handle = NULL;
			handle = new Handle();
			begin = clock();
			safety_bit = handle->solve_greedy(size, size, size, size, generator->gen_arr);
			end = clock();
		}
		std::cout << size << " " << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		out << size << " " << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		/*
		delete handle;
		handle = NULL;

		handle = new Handle();
		begin = clock();
		safety_bit = handle->solve_dynamic(size, size, size, size, generator->gen_arr, false);
		end = clock();
		std::cout << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		out << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		delete handle;
		handle = NULL;

		*/
		size += 20000;
		delete generator;
		generator = NULL;
	}

	out.close();
}
