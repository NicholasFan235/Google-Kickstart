#include <bits/stdc++.h>




void solve(){
    int N, n, K, k;
    std::cin >> N >> K;

    k = K;
    int ctr = 0;
    for (int i = 0; i < N; i++){
        std::cin >> n;
        if (n==k){
            k--;
            if (k==0) {
                ctr++;
                k=K;
            }
        }
        else if (n==K){
            k = K-1;
        }
        else{
            k = K;
        }
    }
    std::cout << ctr << std::endl;
}



int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        std::cout << "Case #" << i << ": ";
        solve();
    }
}
