#include <bits/stdc++.h>





int main(){
    int T, N;
    std::cin >> T >> N;

    std::cout << T << std::endl;
    for (int j = 0; j < T; j++){
        std::cout << N << std::endl;
        for (int i = 0; i < N; i++){
            std::cout << rand()%200-100 << " ";
        }
        std::cout << std::endl;
    }
}

