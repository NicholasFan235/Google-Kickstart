#include <bits/stdc++.h>





int main(){
    int T, NMax, QMax, N, Q;
    std::cin >> T >> NMax >> QMax;
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        N = rand()%NMax+1;
        Q = rand()%QMax+1;
        printf("%d %d\n", N, Q);

        for (int i = 0; i < N; i++){
            std::cout << rand()%1024 << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < Q; i++){
            std::cout << rand()%N << " " << rand()%1024 << std::endl;
        }
    }
}

