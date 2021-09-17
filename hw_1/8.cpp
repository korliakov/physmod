#include <iostream>
//#include <fstream>
#include <array>



  




int main(int argc, char *argv[]) {
    int N = std::stoi(argv[1]);
    
    std::array<int, N+1> my_arr; //Error
    int prev = 1;
    int cur = 1;
    my_arr[1] = prev;
    for (int i = 2; i < N+1; i++) {
        my_arr[i] = cur;
        int a = cur;
        cur += prev; 
        prev = a; 

    }

    for (int i = 1; i < N+1; i++) {
        
        std::cout << i << ' ' << my_arr[i];
    }


}

