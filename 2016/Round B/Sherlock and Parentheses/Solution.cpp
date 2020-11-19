#include <bits/stdc++.h>

int L, R;

void solve(){
    int x = std::min(L, R);
    long long ans = (long long)x*(x+1)/2;
    std::cout << ans << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> L >> R;
        std::cout << "Case #" << t << ": ";
        solve();
    }
}