#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>


int main() {



	std::ofstream out;
	out.open("./numbers1.txt");




	int n;
	std::cout << "Enter amount of numbers: ";
	std::cin >> n;
	std::cout << "\nEnter 2 boundaries: ";

	float a;
	float b;

	std::cin >> a;
	std::cin >> b;

	std::random_device r;

	std::minstd_rand e(r());
	std::uniform_real_distribution<> uniform_dist(a, b);


    for (int i =0; i < n; i++) {

    	out << uniform_dist(e) << ' ';

    }


}


