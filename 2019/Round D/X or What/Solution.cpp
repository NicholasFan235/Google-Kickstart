#include <bits/stdc++.h>


int T, N, Q;
std::array<int, 100007> A;
std::array<int, 100007> S;
std::array<std::pair<int, int>, 100007> modifications;


int parity(int a){
    int p = 0;
    for (int i = 0; i < 10; i++){
        p ^= a%2 != 0;
        a >>= 1;
    }
    return p;
}


void solve(){
    
    for (int q = 0; q < Q; q++){
        A[modifications[q].first] = modifications[q].second;

        int firstOdd = -1;
        int lastOdd = 0;

        S[0] = 0;
        for (int i = 1; i <= N; i++){
            S[i] = S[i-1] + A[i-1];
            if (firstOdd == -1 && A[i-1] == 1){
                firstOdd = i-1;
            }
            if (A[i-1] == 1){
                lastOdd = i-1;
            }
        }

        if (S[N]%2==0){
            std::cout << N << " ";
            continue;
        }

        int l1 = N-firstOdd-1;
        int l2 = lastOdd;
        
        std::cout << std::max(l1, l2) << " ";
    }

    std::cout << std::endl;
}


int main(){
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> Q;
        int a;
        for (int n = 0; n < N; n++){
            std::cin >> a;
            A[n] = parity(a);
        }

        int i, v;
        for (int q = 0; q < Q; q++){
            std::cin >> i >> v;
            modifications[q] = std::make_pair(i, parity(v));
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }
}
