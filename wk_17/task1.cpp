#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <vector>
#include <set>

class App {

private:
	int n;
	int k;
	int amnt_of_tests;
	std::vector<int> flags;
	std::set<int> sequence;
	float probability;

	std::ofstream out; 

public: 


	App() {

		std::cout << "Enter K and amount of tests: " << "\n";
		std::cin >> k; 
		std::cin >> amnt_of_tests;
		n = 1;
	}

	void get_sequence() {

		std::random_device r;

		std::minstd_rand e(r());
		std::uniform_int_distribution<int> uniform_int_dist(1, k);


	    for (int i =0; i < n; i++) {

	    	sequence.insert(uniform_int_dist(e));

	    }
	}

	void get_flags() {

		for (int i= 0; i < amnt_of_tests; i++) {

			get_sequence();

			if (sequence.size() == k) {

				flags.push_back(1);
			} else {
				flags.push_back(0);
			}

			sequence.clear();
		}
	}

	void print_flags() {

		for (auto p : flags) {

			std::cout << p;
		}
	}

	void get_prob() {

		get_flags();

		int sum = 0;
		float flags_size = flags.size();
		for (auto i : flags) { 
			sum += i;
		}

		probability = sum/flags_size;
	}

	void get_data_file() {

		out.open("data1.txt");

		for (int i = 0; i < 100; i++) {
			get_prob();
			out << n << ' ' << probability << "\n";
	
			n++;
		}


	}






};




int main() {


	App app;
	app.get_data_file();
	// std::cout <<  app.get_prob();







}


