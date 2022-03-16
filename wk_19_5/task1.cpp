#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <vector>
#include <set>
#include <cstdint>
#include <filesystem>

class App {

private:
	int n = 1000;
	float r = 2;
	std::vector<double> x;
	float x_0 = 0.5;

	int number_of_seq = 30000;

	float delta_r = 0.0001;
	std::string file_path = "data.csv";





public: 


	App() {
		x.resize(n);
	}


	void get_sequence() {
		std::ofstream out;
		

		out.open(file_path, std::ios::app);

		// out.precision(6);
		out << r;
		out << ", ";


		// x[0] = x_0;

		// for (int i = 1; i < n; i++) {
		// 	x[i] = r * x[i-1] * (1 - x[i-1]);

		// }


		double x_cur = x_0;

		out << x_cur;
		out << ", ";

		for (int i = 1; i < n; i++) {
			x_cur = r * x_cur * (1 - x_cur);
			out << x_cur;

			if (i != n-1) {out << ", ";}
			

		}

		out << "\n";
	}


	void print_seq() {

		std::filesystem::path name ("");
		auto to_del = name / file_path;
		std::filesystem::remove(to_del);

		for (int i = 0; i < number_of_seq+1; i++) {

			get_sequence();
			r += delta_r;

		}

	}


};




int main() {


	App app;
	app.print_seq();
	







}


