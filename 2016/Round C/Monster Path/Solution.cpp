#include <bits/stdc++.h>

int R, C, S;
int Rs, Cs;
double P, Q;
std::vector<std::vector<bool>> map;
std::vector<std::vector<int>> visits;

double dfs(int i, int j, int s){
    if (i < 0 || j < 0 || i >= R || j >= C) return 0;
    double expected = 0;
    double prob = map[i][j] ? P : Q;
    expected += prob * pow(1-prob, visits[i][j]++);
    
    if (s > 0){
        // if remaining steps
        // check neighbours
        expected += std::max({
            dfs(i-1, j, s-1),
            dfs(i+1, j, s-1),
            dfs(i, j-1, s-1),
            dfs(i, j+1, s-1),
        });
    }
    visits[i][j]--;
    return expected;
}

void solve(){
    double expected = 0;
    if (S>0){
        expected = std::max({
            dfs(Rs-1, Cs, S-1),
            dfs(Rs+1, Cs, S-1),
            dfs(Rs, Cs-1, S-1),
            dfs(Rs, Cs+1, S-1)
        });
    }

    printf("%.10f\n", expected);
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> R >> C >> Rs >> Cs >> S;
        std::cin >> P >> Q;
        map = std::vector<std::vector<bool>>(R, std::vector<bool>(C, false));
        visits = std::vector<std::vector<int>>(R, std::vector<int>(C, 0));
        char c;
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                std::cin >> c;
                map[i][j] = c=='A';
            }
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}