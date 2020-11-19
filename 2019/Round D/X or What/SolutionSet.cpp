#include <bits/stdc++.h>


int T, N, Q;
std::array<int, 100007> A;
std::array<std::pair<int, int>, 100007> M;
std::set<int> odds;


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
        int i = M[q].first;
        int v = M[q].second;
        if (A[i] != v){
            if (v==1){
                odds.insert(i);
            }
            else{
                odds.erase(i);
            }
            A[i] = v;
        }


        if (odds.size()%2==0){
            printf("%d ", N);
            continue;
        }

        int l1 = N - *odds.begin() - 1;
        int l2 = *odds.rbegin();
        printf("%d ", std::max(l1, l2));
    }

    std::cout << std::endl;
}


int main(){
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> Q;
        odds.clear();

        int a;
        for (int n = 0; n < N; n++){
            std::cin >> a;
            int p = parity(a);
            if (p==1) odds.insert(n);
            A[n] = p;
        }

        int i, v;
        for (int q = 0; q < Q; q++){
            std::cin >> i >> v;
            M[q] = std::make_pair(i, parity(v));
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }
}
