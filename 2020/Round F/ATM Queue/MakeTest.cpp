#include <bits/stdc++.h>

int main(){
    int T;
    std::cin >> T;

    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        int N = rand() % 10000 + 1;
        int X = rand() % 1000000000 + 1;

        std::cout << N << " " << X << std::endl;

        for (int i = 0; i < N; i++){
            if (i > 0) std::cout << " ";
            std::cout << rand()%1000000000 + 1;
        }
        std::cout << std::endl;
    }
}