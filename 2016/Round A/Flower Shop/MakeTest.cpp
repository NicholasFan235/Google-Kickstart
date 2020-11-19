#include <bits/stdc++.h>

int T;

int main(){
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        int M = rand()%100+1;
        long long c0 = rand();
        std::cout << M << std::endl;
        std::cout << c0 << " ";
        for (int i = 1; i < M; i++){
            std::cout << rand()%1000;
        }
    }
}