#include <bits/stdc++.h>

#define maxn 10000005

long N;
std::vector<int> squares;
std::array<int, 100000> A;
std::array<int, 100005> sA;
std::array<int, 20000005> sActr;
const int offset = 10000002;

void calculateSquares(){
    int i = 0;
    while (true){
        int i2 = i*i;
        if (i2 >= maxn) break;
        squares.push_back(i2);
        i++;
    }
}


void solve(){
    long long int count = 0;
    
    sActr.fill(0);
    sActr[0+offset]++;
    
    int min = 0;
    sA[0] = 0;
    for (int i = 0; i < N; i++){
        sA[i+1] = sA[i] + A[i];
        if (sA[i+1] < min) min = sA[i+1];
    
        for (const int s : squares){
            count += sActr[sA[i+1] - s + offset];
            if (s > sA[i+1] - min) break;
        }
        
        sActr[sA[i+1] + offset]++;
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

