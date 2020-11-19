#include <bits/stdc++.h>


int N;
std::array<int, 200005> V;

void solve(){
    int ctr = 0;
    int currMax = 0;
    for (int i = 0; i < N; i++){
        bool newRecord = V[i] > currMax || i == 0;
        bool nextLower = i==N-1 || V[i+1] < V[i];
        if (newRecord && nextLower) ctr++;
        currMax = std::max(currMax, V[i]);
    }
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

