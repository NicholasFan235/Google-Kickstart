#include <bits/stdc++.h>

int R, C, K;
std::vector<std::vector<bool>> map;

bool possible(int i, int j, int d){
    if (i+d > R || j+d > C) return false;
    for (int k = 0; k < d; k++){
        if (map[i+k][j+d-1]) return false;
    }
    for (int l = 0; l < d-1; l++){
        if (map[i+d-1][j+l]) return false;
    }
    return true;
}

void solve(){
    long long count = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            int d = 1;
            while (possible(i, j, d++)){
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> R >> C >> K;
        map = std::vector<std::vector<bool>>(R, std::vector<bool>(C, false));
        int i, j;
        for (int k = 0; k < K; k++){
            std::cin >> i >> j;
            map[i][j] = true;
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}