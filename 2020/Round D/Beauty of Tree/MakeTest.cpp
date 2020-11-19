#include <bits/stdc++.h>




int main(){
    int T, N, A, B;
    std::cin >> T >> N;
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        std::cout << N << " " << 1+rand()%10 << " " << 1+rand()%10 << std::endl;
        for (int n = 0; n < N-1; n++){
            std::cout << 1+rand()%(n+1) << " ";
            //std::cout << 1+n << " ";
        }
        std::cout << std::endl;
    }
}

