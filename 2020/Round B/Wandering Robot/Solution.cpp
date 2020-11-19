#include <bits/stdc++.h>

#define maxn 200000
double fact[maxn];

void makeFactTable(){
    fact[0] = 1;
    for (long i = 1; i < maxn; i++){
        fact[i] = fact[i-1] * i;
    }
}

float nCr(int n, int r){
    return fact[n]/(fact[n-r]*fact[r]);
}

void solve(int W, int H, int L, int U, int R, int D){
    double prob1 = 0;
    double prob2 = 0;
    
    int totalSteps1 = L+D-2;
    for (int i = std::max(0, totalSteps1 - H + 1); i < L-1; i++){
        prob1 += nCr(totalSteps1, i);
    }
    prob1 = prob1 / pow(2, totalSteps1);

    int totalSteps2 = U+R-2;
    for (int i = std::max(0, totalSteps2 - W + 1); i < U-1; i++){
        prob2 += nCr(totalSteps2, i);
    }
    prob2 = prob2 / pow(2, totalSteps2);

    std::cout << prob1+prob2 << std::endl;
}

int main(){
    int T;
    std::cin >> T;

    makeFactTable();

    for (int i = 1; i <= T; i++){
        int W, H, L, U, R, D;

        std::cin >> W >> H >> L >> U >> R >> D;

        std::cout << "Case #" << i << ": ";
        solve(W, H, L, U, R, D);
    }
}

