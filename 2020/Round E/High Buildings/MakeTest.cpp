#include <bits/stdc++.h>


const int T = 20;
const int NMax = 5;

int main(){
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        int N = rand()%NMax + 1;
        int C = rand()%N + 1;
        int A = rand()%(N-C+1) + C;
        int B = rand()%(N-C+1) + C;
        std::cout << N << " " << A << " " << B << " " << C << std::endl;
    }
}