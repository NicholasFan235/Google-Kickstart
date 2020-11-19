#include <bits/stdc++.h>


int T, N;

std::vector<std::pair<int, int>> toys;






int main(){
    std::cin >> T;
    int E, R;
    for (int t = 1; t <= T; t++){
        toys.clear();
        std::cin >> N;
        for (int n = 0; n < N; n++){
            std::cin >> E >> R;
            toys.push_back(std::make_pair(E, R));
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}

