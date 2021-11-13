#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>



// float K_sum(float a, float b) {

// 	float sum = 0.0;
// 	float c = 0.0;

// 	float y = a - c;
// 	float t = sum + y;
// 	c = (t - sum) - y;
// 	sum = t;

// 	float y = b - c;
// 	float t = sum + y;
// 	c = (t - sum) - y;
// 	sum = t;

// 	return sum;
// }



void data_t(float delta, int N, std::vector<float> &x, std::vector<float> &v, double gamma, double w) {


	float v_cur = 0;
	float x_cur = 1;


	x[0] = x_cur;
	v[0] = v_cur;

	for (int i = 1; i < N; i++) {

		
		x_cur = x[i-1] + v[i-1] * delta;
		v_cur = v[i-1] - (2*gamma*v[i-1] + w*w*x[i-1]) * delta;


		x[i] = x_cur;
		v[i] = v_cur;

	}

}

void predict_correct_data_t(float delta, int N, std::vector<float> &x, std::vector<float> &v, double gamma, double w) {


	float v_cur = 0;
	float x_cur = 1;

	x[0] = x_cur;
	v[0] = v_cur;

	for (int i = 1; i < N; i++) {

		float x_pred = x[i-1] + v[i-1] * delta;
		float v_pred = v[i-1] - (2*gamma*v[i-1] + w*w*x[i-1]) * delta;

		x_cur = x[i-1] + delta * (v[i-1] + v_pred) / 2;
		v_cur = v[i-1] - delta * (2*gamma*v[i-1] + w*w*x[i-1] + 2*gamma*v_pred + w*w*x_pred )/2;

		x[i] = x_cur;
		v[i] = v_cur;

	}

}



//дописать!!

void rk4(float delta, int N, std::vector<float> &x, std::vector<float> &v, double gamma, double w) {


	float v_cur = 0;
	float x_cur = 1;

	x[0] = x_cur;
	v[0] = v_cur;

	for (int i = 1; i < N; i++) {

		
		float v1 = v[i-1] - (2*gamma*v[i-1] + w*w*x[i-1]) * delta;
		float x1 = x[i-1] + v[i-1] * delta;

		
		float v2 = 
		float x2 = 




		x_cur = x[i-1] + delta * (v[i-1] + v_pred) / 2;
		v_cur = v[i-1] - delta * (2*gamma*v[i-1] + w*w*x[i-1] + 2*gamma*v_pred + w*w*x_pred )/2;

		x[i] = x_cur;
		v[i] = v_cur;

	}


}


int main(int argc, char *argv[]) {

	std::string path1 = argv[1];
	std::string path2 = argv[2];
	long double delta = atof(argv[3]); 
	double gamma = atof(argv[4]);
	double w = atof(argv[5]);


	int T = 100;
	int N = int(T/delta);
	std::vector<float> x = std::vector<float>(N);
	std::vector<float> v = std::vector<float>(N);

	float t = 0;

	

	
	data_t(delta, N, x, v, gamma, w);	


	std::ofstream out1(path1);


	if (out1.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out1 << x[i] << ' ' << v[i] << ' ' << t << "\n";

        	t+=delta;


        }
    }

    t = 0;

    x.resize(0);
    v.resize(0);

    predict_correct_data_t(delta, N, x, v, gamma, w);




	std::ofstream out2(path2);


	if (out2.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out2 << x[i] << ' ' << v[i] << ' ' << t << "\n";

        	t+=delta;


        }
    }
}