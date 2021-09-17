#include <iostream>
#include <fstream>


using namespace std;


int main(int argc, char *argv[]) {
    int N = std::stoi(argv[1]);

    std::ofstream file;
    file.open("file12.txt", std::ios::binary);
    for (int i = 1; i < N+1; i++) {
        float a = 1.0/i;
        file.write((char*)&a, sizeof(a));   

    }
    file.close();
    




}


