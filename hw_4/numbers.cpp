#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>





void data_t(float delta, int N, std::vector<double> &x, std::vector<double> &v) {


	float v_cur = 0;
	float x_cur = 10;

	x.push_back(x_cur);
	v.push_back(v_cur);

	for (int i = 0; i < N; i++) {

		x_cur = x[x.size() - 1] + v[v.size() - 1] * delta;
		v_cur = v[v.size() - 1] - x[x.size() - 1] * delta;

		x.push_back(x_cur);
		v.push_back(v_cur);

	}

}

void predict_correct_data_t(float delta, int N, std::vector<double> &x, std::vector<double> &v) {


	float v_cur = 0;
	float x_cur = 10;

	x.push_back(x_cur);
	v.push_back(v_cur);

	for (int i = 0; i < N; i++) {

		float x_pred = x[x.size() - 1] + v[v.size() - 1] * delta;
		float v_pred = v[v.size() - 1] - x[x.size() - 1] * delta;

		x_cur = x[x.size() - 1] + delta * (v[v.size() - 1] + v_pred) / 2;
		v_cur = v[v.size() - 1] - delta * (x[v.size() - 1] + x_pred) / 2;

		x.push_back(x_cur);
		v.push_back(v_cur);

	}

}


int main(int argc, char *argv[]) {


	long double delta = atof(argv[2]); 
	int N = 10000;
	std::vector<double> x;
	std::vector<double> v;
	float t = 0;

	// 	data_t(delta, N, x, v);
	predict_correct_data_t(delta, N, x, v);

	std::string path = argv[1];

	std::ofstream out(path);


	if (out.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out << x[i] << ' ' << v[i] << ' ' << t << "\n";

        	t+=delta;


        }
    }
}