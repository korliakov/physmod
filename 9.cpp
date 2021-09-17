#include <iostream>
//#include <fstream>
#include <array>
#include <iostream>


  




int main(int argc, char *argv[]) {
    const int N = 11;

    std::cout.setf(std::ios::scientific);
    int a = 1;
    std::array<float, N> my_arr;

    for (int i = 0; i < N ; i++) {
        my_arr[i] = 1.0/a;
        a++;

    }
    for (int i = 0; i < N; i++) {
        std::cout << my_arr[i] << std::endl;
    }

}

