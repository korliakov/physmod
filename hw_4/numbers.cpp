#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>



float K_sum(float a, float b) {

	float sum = 0.0;
	float c = 0.0;

	float y = a - c;
	float t = sum + y;
	c = (t - sum) - y;
	sum = t;

	float y = b - c;
	float t = sum + y;
	c = (t - sum) - y;
	sum = t;

	return sum;
}



void data_t(float delta, int N, std::vector<float> &x, std::vector<float> &v) {


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

void predict_correct_data_t(float delta, int N, std::vector<float> &x, std::vector<float> &v) {


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
	int T = 100;
	int N = int(T/delta);
	std::vector<float> x;
	std::vector<float> v;
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