#include <iostream>
#include <fstream>


void my_func(int N) {
    std::ofstream file;
    file.open("file5.txt");
    for (int i = 1; i < N+1; i++) {
        file << i << std::endl;

    }
    file.close();
}

int main() {
    std::cout << "Enter N: ";
    int N;
    std::cin >> N;     
    my_func(N);


}
