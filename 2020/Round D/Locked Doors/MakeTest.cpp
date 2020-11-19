#include <bits/stdc++.h>



const int T = 10;
const int NMin = 10, NMax = 20;
const int QMin = 10, QMax = 15;

std::vector<int> locks;


int main(){
    std::cout << T << std::endl;

    for (int t = 0; t < T; t++){
        locks.clear();
        int N = rand()%(NMax-NMin+1)+NMin;
        int Q = rand()%(QMax-QMin+1)+QMin;

        std::cout << N << " " << Q << std::endl;

        for (int i = 1; i < N; i++){
            locks.push_back(i);
        }

        for (int i = N-2; i > 0; i--){
            int other = rand()%i;
            std::swap(locks[i], locks[other]);
        }

        for (const int l : locks){
            std::cout << l << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < Q; i++){
            std::cout << rand()%N+1 << " " << rand()%N+1 << std::endl;
        }
    }
}


