#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

using Number = long long;

namespace mine {
	int fib(int n) {
		if (n <= 1) {
			return n;
		}
		return fib(n - 1) + fib(n - 2);
	}

}

//Memoization

namespace memoization {
	Number fibHelper(Number n, std::vector<Number>& mem)
	{
		if (n <= 1) {
			return n;
		}
		if (mem[n] != -1) {
			return mem[n];
		}
		mem[n] = fibHelper(n - 1, mem) + fibHelper(n - 2, mem);
		return mem[n];
	}
	Number fib(Number n) {
		std::vector<Number> mem(n + 1, -1);
		return fibHelper(n, mem);
	}
}

//Tabulation

namespace tabulation {
	Number fib(Number n){
		if (n <= 1) {
			return n;
		}
		std::vector<Number> mem(n + 1, -1);
		mem[0] = 0;
		mem[1] = 1;
		for (Number i = 2; i <= n; ++i) {
			mem[i] = mem[i - 1] + mem[i - 2];
		}
		return mem[n];

	}
}

int main() {
	//1
	auto start1 = high_resolution_clock::now();
	std::cout << mine::fib(7) << std::endl;
	for (int i = 0; i < 1000000; i++);

	auto end1 = high_resolution_clock::now();

	auto duration1 = duration_cast<milliseconds>(end1 - start1);

	cout << "Time: " << duration1.count() << " ms" << endl;

	//2
	auto start2 = high_resolution_clock::now();
	std::cout << memoization::fib(7) << std::endl;
	for (int i = 0; i < 1000000; i++);

	auto end2 = high_resolution_clock::now();

	auto duration2 = duration_cast<milliseconds>(end2 - start2);

	cout << "Time: " << duration2.count() << " ms" << endl;

	//3
	auto start3 = high_resolution_clock::now();
	std::cout << tabulation::fib(7) << std::endl;
	for (int i = 0; i < 1000000; i++);

	auto end3 = high_resolution_clock::now();

	auto duration3 = duration_cast<milliseconds>(end3 - start3);
	cout << "Time: " << duration3.count() << " ms" << endl;
}
