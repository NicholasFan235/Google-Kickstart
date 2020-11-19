#include <bits/stdc++.h>

int M;
std::vector<long double> coeffs;


long double f(long double x){
    long double result = 0;
    for (int i = 0; i < M; i++){
        result += coeffs[i] * pow(x, M-i);
    }
    return result;
}

long double df(long double x){
    long double result = 0;
    for (int i = 0; i < M; i++){
        result += coeffs[i] * pow(x, M-i-1) * (M-i);
    }
    return result;
}

long double newtonRaphson(long double x){
    return x - f(x)/df(x);
}

void solve(){
    long double prev = 1;
    long double curr = newtonRaphson(prev);

    while (fabs(curr-prev) > 1e-10){
        prev = curr;
        curr = newtonRaphson(prev);
    }
    printf("%.10f\n", curr-1);
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