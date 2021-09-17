#include <iostream>
#include <fstream>




int main() {
    std::ofstream file;
    file.open("file4.txt");

    int N = 30;
    for (int i = 1; i < N+1; i++) {
        file << i << std::endl;

    }
    file.close();
}
