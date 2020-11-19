#include <bits/stdc++.h>
//#include "CheckSolution.h"

int T, A, B, C, N;
std::vector<int> result;

void addNumbers(int count, int n){
    for (int i = 0; i < count; i++){
        result.push_back(n);
    }
}

void solve(){
    result.clear();
    int numHidden = N+C-A-B;

    if (numHidden < 0){
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }

    if ( C >= 2 || numHidden == 0){
        addNumbers(A-C, N-1);
        addNumbers(1, N);
        addNumbers(numHidden, N-2);
        addNumbers(C-1, N);
        addNumbers(B-C, N-1);
    }
    else{
        // C==1 and there are hidden numbers have to hide either side
        addNumbers(A-C, N-1);
        if (A==1 && B==1){
            std::cout << "IMPOSSIBLE" << std::endl;
            return;
        }
        if (A==1){
            addNumbers(C, N);
            addNumbers(numHidden, N-2);
        }
        else{
            addNumbers(numHidden, N-2);
            addNumbers(C, N);
        }
        addNumbers(B-C, N-1);
    }

    for (int i = 0; i < N; i++){
        std::cout << result[i] << " ";
    }

    //std::cout << checkAnswer(result, A, B, C, N) << std::endl;

    std::cout << std::endl;
}


int main(){
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> A >> B >> C;

        std::cout << "Case #" << t << ": ";
        solve();
    }
}


