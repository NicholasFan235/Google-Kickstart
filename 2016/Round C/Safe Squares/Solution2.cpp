#include <bits/stdc++.h>

int R, C, K;
std::vector<std::vector<int>> map;


void solve(){
    for (int i = 1; i < R; i++){
        for (int j = 1; j < C; j++){
            if (map[i][j] == 0) continue;
            map[i][j] = std::min({map[i-1][j], map[i][j-1], map[i-1][j-1]}) + 1;
        }
    }
    long long count = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            count += map[i][j];
        }
    }
    std::cout << count << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> R >> C >> K;
        map = std::vector<std::vector<int>>(R, std::vector<int>(C, 1));
        int i, j;
        for (int k = 0; k < K; k++){
            std::cin >> i >> j;
            map[i][j] = 0;
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}