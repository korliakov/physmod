#include <iostream>
#include <fstream>


void my_func(int N) {
    std::ofstream file;
    file.open("file6.txt");
    for (int i = 1; i < N+1; i++) {
        file << i << std::endl;

    }
    file.close();
}

int main(int argc, char *argv[]) {
    int N = std::stoi(argv[1]);
     
    my_func(N);



}

