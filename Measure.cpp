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
		safety_bit = handle->solve_greedy(size, size, size, size / 50, generator->gen_arr);
		end = clock();
		while (!safety_bit) {
			delete handle;
			handle = NULL;
			handle = new Handle();
			begin = clock();
			safety_bit = handle->solve_greedy(size, size, size, size / 50, generator->gen_arr);
			end = clock();
		}
		std::cout << size << " " << double (end - begin) / CLOCKS_PER_SEC << " ";
		out << size << " " << double (end - begin) / CLOCKS_PER_SEC << " ";
		delete handle;
		handle = NULL;

		handle = new Handle();
		begin = clock();
		safety_bit = handle->solve_dynamic(size, size, size, size / 50, generator->gen_arr, false);
		end = clock();
		std::cout << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		out << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		delete handle;
		handle = NULL;

		size += 5000;
		delete generator;
		generator = NULL;
	}

	out.close();
}

void Measure::measure_brute() {
	clock_t begin, end;
	std::fstream out;
	out.open("knapsack_brute.txt", std::ios::out);
	Generator * generator;
	Handle * handle;
	int size = 20;
	bool safety_bit;

	std::cout << "brute" << std::endl;
	for (int i = 0; i < 20; i++) {
		generator = new Generator();
		generator->gen(size, size, size);
		handle = new Handle();
		begin = clock();
		handle->solve_brute(size, size, size, size, generator->gen_arr);
		end = clock();
		std::cout << size << " " << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		out << size << " " << double (end - begin) / CLOCKS_PER_SEC << std::endl;
		delete [] generator->gen_arr;
		generator->gen_arr = NULL;
		delete handle;
		handle = NULL;
		size++;
	}
	out.close();
}
