#include <bits/stdc++.h>

#define maxn 10000005

long N;
std::array<char, maxn> squares;
std::array<int, 100000> A;
std::array<int, 100001> sA;

void calculateSquares(){
    squares.fill(0);
    int i = 0;
    while (true){
        long i2 = (long)i*i;
        if (i2 >= maxn) break;
        squares[i2] = 1;
        i++;
    }
}


void solve(){
    long long int count = 0;
    sA[0] = 0;
    int min = 0;
    for (int i = 0; i < N; i++){
        sA[i+1] = sA[i] + A[i];

        for (int j = 0; j <= i; j++){
            int s = sA[i+1] - sA[j];
            if (s<0) continue;
            if (squares[s] != 0) count++;
        }
    }

    std::cout << count << std::endl;
}


int main(){
    calculateSquares();
    
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++){
        std::cin >> N;
        for (int i = 0; i < N; i++){
            std::cin >> A[i];
        }
        std::cout << "Case #" << i << ": ";
        solve();
    }
}

