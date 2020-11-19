#include <bits/stdc++.h>

int K;
std::array<int, 1000005> A;

void solve(){
    int ups = 0;
    int downs = 0;
    int curr = 0;
    int ctr = 0;

    for (int k = 1; k < K; k++){
        if (A[k] > A[k-1]){
            downs = 0;
            if (++ups > 3){
                ctr++;
                ups = 0;
            }
        };
        if (A[k] < A[k-1]){
            ups = 0;
            if (++downs > 3){
                ctr++;
                downs = 0;
            }
        };
    }
    std::cout << ctr << std::endl;
}


int main(){
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++){
        std::cin >> K;
        for (int k = 0; k < K; k++){
            std::cin >> A[k];
        }

        std::cout << "Case #" << i << ": ";
        solve();
    }
}


