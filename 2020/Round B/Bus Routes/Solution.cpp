#include <bits/stdc++.h>

unsigned long long int solve(std::vector<unsigned long long int> X, unsigned long long int D){
    for (int i = X.size()-1; i>=0; i--){
        D-=D%X[i];
    }
    return D;
}

int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        int N;
        unsigned long long int D;
        std::cin >> N >> D;
        std::vector<unsigned long long int> busses;
        for (int i = 0; i < N; i++){
            long long int b;
            std::cin >> b;
            busses.push_back(b);
        }

        std::cout << "Case #" << i << ": " << solve(busses, D) << std::endl;
    }
}

