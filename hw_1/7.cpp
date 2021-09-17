#include <iostream>
#include <fstream>


void my_func(int N) {
    std::ofstream file;
    file.open("file7.txt");
    long int prev = 1;
    long int cur = 1;
    file << 1 << ' ' << prev << std::endl; 
    for (int i = 2; i < N+1; i++) {
        file << i << ' ' << cur << std::endl;
        long int a = cur;
        cur += prev; 
        prev = a; 

    }
    file.close();
}

int main(int argc, char *argv[]) {
    int N = std::stoi(argv[1]);
     
    my_func(N);



}

