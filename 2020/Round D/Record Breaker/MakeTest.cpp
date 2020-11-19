#include <bits/stdc++.h>



int main(){
    int T, N;
    std::cin >> T >> N;

    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        std::cout << N << std::endl;
        for (int n = 0; n < N; n++){
            std::cout << rand()%200000 << " ";
        }
        std::cout << std::endl;
    }
}

