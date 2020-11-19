#include <bits/stdc++.h>
//#include "CheckSolution.h"

int T, A, B, C, N;
std::vector<int> result;

void addInc(int n){
    for (int i = 0; i < n; i++){
        result.push_back(i+2);
    }
}

void addMax(int n){
    for (int i = 0; i < n; i++){
        result.push_back(N);
    }
}

void addDec(int n){
    for (int i = n-1; i >= 0; i--){
        result.push_back(i+2);
    }
}

void addHidden(int n){
    for (int i = 0; i < n; i++){
        result.push_back(1);
    }
}

void solve(){
    // check is possible
    if (A+B-C > N){
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }
    if (A==1 && B==1 && N>1){
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }
    int numInc = A-C;
    int numDec = B-C;
    int numHidden = N+C-A-B;

    result.clear();
    addInc(numInc);
    if (numInc == 0 && numDec == 0){
        if (C > 1 || numHidden == 0){
            addMax(1);
            addHidden(numHidden);
            addMax(C-1);
        }
        else{
            std::cout << "IMPOSSIBLE" << std::endl;
            return;
        }
    }
    else{
        if (numInc > 0){
            addHidden(numHidden);
            addMax(C);
        }
        else{
            addMax(C);
            addHidden(numHidden);
        }
    }
    addDec(numDec);

    for (const int i : result){
        std::cout << i << " ";
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


