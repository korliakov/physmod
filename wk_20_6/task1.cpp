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

class Gas {


private:

	int n1 = 10;
	int n2 = 0;
	int k = 5;

	double average_vel = 0;
	double vel_standart_dev_light = 5;
	double vel_standart_dev_heavy = 1;
	double average_coord = 0;
	double coord_standart_dev = 1;

	//coordinates and velocities of ALL particles; first n1 elements - 1 type particles;  second n2 - 2 type particles
	std::vector<double> x;
	std::vector<double> v;



	double t = 0;
	double dt = 0.01;
	int N = 100;
	std::string coord_path = "coords.csv";
	std::string vel_path = "vel.csv";



public:

	void get_collisions() {

		for (int i = 0; i < n1 + n2; i++) {
			for (int j = i+1; j < n1 + n2; j++) {
				double t_collision =  (x[j] - x[i])/(v[i] - v[j]);
				if ( t_collision < dt) {

					double x_collision = (x[j]*v[i] - x[i] * v[j])/(v[i] - v[j]);

					if (i < n1 && j >= n1) {
						double vel_swp_i = v[i];
						double vel_swp_j = v[j];
						v[i] = (2*k*vel_swp_j + vel_swp_i* (1-k))/(1+k);
						v[j] = (2*vel_swp_i + vel_swp_j* (k-1))/(1+k);
						x[i] = x_collision +  v[i] * (dt - t_collision);
						x[j] = x_collision +  v[j] * (dt - t_collision);



					} else if (i >= n1 && j < n1) {
						double vel_swp_i = v[i];
						double vel_swp_j = v[j];
						v[i] = (2*vel_swp_j + vel_swp_i*(k-1))/(k+1);
						v[j] = (2*k*vel_swp_i + vel_swp_j*(1-k))*(k+1);
						x[i] = x_collision +  v[i] * (dt - t_collision);
						x[j] = x_collision +  v[j] * (dt - t_collision);

					}


				}

			}

		}
	}

	Gas() {

		std::random_device r;

		std::mt19937  gen(r());
		std::normal_distribution<double> vel_light_normal_dist(average_vel, vel_standart_dev_light);
		std::normal_distribution<double> vel_heavy_normal_dist(average_vel, vel_standart_dev_heavy);
		std::normal_distribution<double> coord_normal_dist(average_coord, coord_standart_dev);



	    for (int i =0; i < n1; i++) {

	    	v.push_back(vel_light_normal_dist(gen));
	    	x.push_back(coord_normal_dist(gen));
	    }

	    for (int i =n1; i < n2; i++) {

	    	v.push_back(vel_heavy_normal_dist(gen));
	    	x.push_back(coord_normal_dist(gen));
	    }



	}

	void get_x() {

		for (int i = 0; i < n1 + n2; i++) {

			std::cout << x[i] << '\n';
		}
	}

	void move() {

		for (int i =0; i < n1+n2; i++) {

			x[i] += v[i] * dt;
		}

		t += dt;
	}

	void write_to_file() {
		std::ofstream out_coord;
		std::ofstream out_vel;
		out_coord.open(coord_path, std::ios::app);
		out_vel.open(vel_path, std::ios::app);
		
		out_coord << t << ", ";
		out_vel << t << ", ";

		for (int i = 0; i < n1 + n2 - 1; i++) {
			out_coord << x[i] << ", ";
			out_vel << v[i] << ", ";

		}
		out_coord << x[n1+n2-1] << "\n";
		out_vel << v[n1+n2-1] << "\n";

	}


	void main_loop() {

		for (int i =0; i < N; i++) {
			write_to_file();
			get_collisions();
			move();

		}
	}





};


int main() {

	Gas gas;
	gas.main_loop();




}