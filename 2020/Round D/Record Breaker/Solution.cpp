#include <bits/stdc++.h>


int N;
std::array<int, 200005> V;

void solve(){
    int ctr = 0;
    int currMax = 0;
    bool candidate = false;
    for (int i = 0; i < N; i++){
        if (candidate && V[i] < currMax){
            ctr++;
        }
        if (V[i] > currMax) {
            candidate = true;
            currMax = V[i];
            continue;
        }
        candidate = false;
    }
    if (candidate) ctr++;
    std::cout << ctr << std::endl;
}



int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        std::cout << "Case #" << i << ": ";

        std::cin >> N;
        for (int i = 0; i < N; i++){
            std::cin >> V[i];
        }

        solve();
    }
}

