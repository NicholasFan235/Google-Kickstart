#include <bits/stdc++.h>

int M;
std::vector<long double> coeffs;


long double f(long double x){
    long double result = 0;
    for (int i = 0; i < M; i++){
        result += coeffs[i] * powl(1+x, M-i);
    }
    return result;
}

long double abs(long double x){
    return x>0 ? x : -x;
}

void solve(){
    long double upper = 1, lower = -1;
    while (upper - lower > 1e-10){
        long double mid = (upper + lower)/2;
        if (f(mid) > (long double)0) lower = mid;
        else upper = mid;
    }
    printf("%.10Lf\n", upper);
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> M;
        M++;
        coeffs = std::vector<long double>(M);
        for (int i = 0; i < M; i++){
            std::cin >> coeffs[i];
        }
        coeffs[0]*=-1;
        std::cout << "Case #" << t << ": ";
        solve();
    }
}