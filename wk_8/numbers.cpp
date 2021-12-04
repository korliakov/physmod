#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <math.h>


#define PI 3.1415926


template <typename T>
void data_t(float delta, int N, std::vector<T> &t, std::vector<T> &x, std::vector<T> &v, double gamma, double w0, double w, double F) {


	T v_cur = 0;
	T x_cur = 0;
	T t_cur = 0;


	x[0] = x_cur;
	v[0] = v_cur;
	t[0] = t_cur;

	for (int i = 1; i < N; i++) {

		float k = std::fmod(w*t[i-1], 2*PI)/(2*PI);

		x_cur = x[i-1] + v[i-1] * delta;

		if (k >= 0 && k <= 0.5) {

			v_cur = v[i-1] +(F  - (2*gamma*v[i-1] + w0*w0*x[i-1])) * delta;

		} else if (k > 0.5 && k <= 1) {

			v_cur = v[i-1] +(0 - (2*gamma*v[i-1] + w0*w0*x[i-1])) * delta;
		
		}
		
		
		t_cur = t[i-1] + delta;

		x[i] = x_cur;
		v[i] = v_cur;
		t[i] = t_cur;

	}

}


template <typename T>
void predict_correct_data_t(float delta, int N, std::vector<T> &t, std::vector<T> &x, std::vector<T> &v, double gamma, double w0, double w, double F) {


	T v_cur = 0;
	T x_cur = 0;
	T t_cur = 0;

	x[0] = x_cur;
	v[0] = v_cur;
	t[0] = t_cur;

	for (int i = 1; i < N; i++) {


		float k = std::fmod(w*t[i-1], 2*PI)/(2*PI);



		if (k >= 0 && k <= 0.5) {
			T x_pred = x[i-1] + v[i-1] * delta;
			T v_pred = v[i-1] +(F  - (2*gamma*v[i-1] + w0*w0*x[i-1])) * delta;

			x_cur = x[i-1] + delta * (v[i-1] + v_pred) / 2;
			v_cur = v[i-1] + delta * (2*F - (2*gamma*v[i-1] + w0*w0*x[i-1] + 2*gamma*v_pred + w0*w0*x_pred ))/2;
			t_cur = t[i-1] + delta;

		} else if (k > 0.5 && k <= 1) {
			T x_pred = x[i-1] + v[i-1] * delta;
			T v_pred = v[i-1] +(0 - (2*gamma*v[i-1] + w0*w0*x[i-1])) * delta;

			x_cur = x[i-1] + delta * (v[i-1] + v_pred) / 2;
			v_cur = v[i-1] + delta * (0 - (2*gamma*v[i-1] + w0*w0*x[i-1] + 2*gamma*v_pred + w0*w0*x_pred ))/2;
			t_cur = t[i-1] + delta;
		
		}




		x[i] = x_cur;
		v[i] = v_cur;
		t[i] = t_cur;

	}

}



//дописать!!
template <typename T>
void rk4(double delta, int N, std::vector<T> &t, std::vector<T> &x, std::vector<T> &v, double gamma, double w0, double w, double F) {


	T v_cur = 0;
	T x_cur = 0;
	T t_cur = 0;

	x[0] = x_cur;
	v[0] = v_cur;
	t[0] = t_cur;

	for (int i = 1; i < N; i++) {

		float k = std::fmod(w*t[i-1], 2*PI)/(2*PI);




		if (k >= 0 && k <= 0.5) {
			T k1_v = (F -(2*gamma*v[i-1] + w0*w0*x[i-1]));
			T k1_x = v[i-1];

			T k2_v = (F -(2*gamma*(v[i-1] + delta*k1_v*0.5) + w0*w0*(x[i-1] + k1_x * delta*0.5)));
			T k2_x = v[i-1] +  delta*k1_v/2;

			T k3_v = (F -(2*gamma*(v[i-1] + delta*k2_v*0.5) + w0*w0*(x[i-1] + k2_x * delta*0.5)));
			T k3_x = v[i-1] +  delta*k2_v/2;

			T k4_v = (F -(2*gamma*(v[i-1] + delta*k3_v) + w0*w0*(x[i-1] + k3_x * delta)));
			T k4_x =  v[i-1] +  delta*k3_v;


			x_cur = x[i-1] + delta * (k1_x + 2*k2_x + 2*k3_x + k4_x) / 6;
			v_cur = v[i-1] + delta * (k1_v + 2*k2_v + 2*k3_v + k4_v)/6;
			t_cur = t[i-1] + delta;			





		} else if (k > 0.5 && k <= 1) {



			T k1_v = (0 -(2*gamma*v[i-1] + w0*w0*x[i-1]));
			T k1_x = v[i-1];

			T k2_v = (0 -(2*gamma*(v[i-1] + delta*k1_v*0.5) + w0*w0*(x[i-1] + k1_x * delta*0.5)));
			T k2_x = v[i-1] +  delta*k1_v/2;

			T k3_v = (0 -(2*gamma*(v[i-1] + delta*k2_v*0.5) + w0*w0*(x[i-1] + k2_x * delta*0.5)));
			T k3_x = v[i-1] +  delta*k2_v/2;

			T k4_v = (0 -(2*gamma*(v[i-1] + delta*k3_v) + w0*w0*(x[i-1] + k3_x * delta)));
			T k4_x =  v[i-1] +  delta*k3_v;


			x_cur = x[i-1] + delta * (k1_x + 2*k2_x + 2*k3_x + k4_x) / 6;
			v_cur = v[i-1] + delta * (k1_v + 2*k2_v + 2*k3_v + k4_v)/6;
			t_cur = t[i-1] + delta;		

		
		}



		x[i] = x_cur;
		v[i] = v_cur;
		t[i] = t_cur;	

	}


}


int main(int argc, char *argv[]) {

	std::string path1 = argv[1];
	std::string path2 = argv[2];
	std::string path3 = argv[3];
	long double delta = atof(argv[4]); 
	double gamma = atof(argv[5]);
	double w0 = atof(argv[6]);
	double w = atof(argv[7]);


	int T = 1000;
	int N = int(T/delta);
	std::vector<double> x = std::vector<double>(N);
	std::vector<double> v = std::vector<double>(N);
	std::vector<double> t = std::vector<double>(N);



	double F = 10;
	

	
	data_t(delta, N, t, x, v, gamma, w0, w, F);	


	std::ofstream out1(path1);


	if (out1.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out1 << x[i] << ' ' << v[i] << ' ' << t[i] << "\n";




        }
    }



    x.resize(0);
    v.resize(0);
    t.resize(0);

    predict_correct_data_t(delta, N, t, x, v, gamma, w0, w, F);




	std::ofstream out2(path2);


	if (out2.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out2 << x[i] << ' ' << v[i] << ' ' << t[i] << "\n";




        }
    }



    x.resize(0);
    v.resize(0);
    t.resize(0);

    rk4<double>(delta, N, t, x, v, gamma, w0, w, F);

    std::ofstream out3(path3);


	if (out3.is_open())
    {


        for (int i = 0; i < N; i++) {

        	out3 << x[i] << ' ' << v[i] << ' ' << t[i] << "\n";



        }
    }



}