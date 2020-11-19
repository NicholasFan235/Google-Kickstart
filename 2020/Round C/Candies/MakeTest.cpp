#include <bits/stdc++.h>

const int T = 10;
const int N = 200000;
const int Q = 100000;

int main(){
    std::cout << T << std::endl;

    for (int t = 0; t < T; t++){
        std::cout << N << " " << Q << std::endl;

        for (int i = 0; i < N; i++){
            std::cout << rand()%100+1 << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < Q; i++){
            int r = rand()%100;
            if (r>=30){
                int i = rand()%N+1;
                int j = rand()%N+1;
                std::cout << "Q " << std::min(i, j) << " " << std::max(i, j) << std::endl;
            }
            else{
                int i = rand()%N+1;
                int j = rand()%100+1;
                std::cout << "U " << i << " " << j << std::endl;
            }
        }
    }
}