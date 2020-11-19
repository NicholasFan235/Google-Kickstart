#include <bits/stdc++.h>


const int T = 10;
const int NMax = 100000;


int main(){
    std::cout << T << std::endl;

    for (int t = 0; t < T; t++){
        int N = rand()%NMax + 1;
        std::cout << N << std::endl;
        for (int n = 0; n < N; n++){
            int E = rand()%10000+1;
            int R = rand()%(10000*N)+1;
            std::cout << E << " " << R << std::endl;
        }
    }
}
