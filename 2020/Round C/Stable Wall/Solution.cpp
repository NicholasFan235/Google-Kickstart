#include <bits/stdc++.h>

int R, C;

void solve(std::vector<std::vector<int>> wall, std::set<int> keys){
    std::vector<std::vector<int>> adj(26, std::vector<int>(26));

    for (int c = 0; c < C; c++){
        int above = wall[0][c];
        for (int r = 1; r < R; r++){
            int curr = wall[r][c];
            if (curr != above){
                adj[curr][above] = 1;
            }
            above = curr;
        }
    }
/*
    std::cout << std::endl;
    for (const auto i : keys){
        printf("%c ", i+'A');
    }
    
    std::cout << std::endl;
    for (const auto i : keys){
        for (const auto j : keys){
            std::cout << adj[i][j] << " ";
        }
        std::cout << std::endl;
    }
    */
    
    std::string sorted = "";
    std::map<int, std::stack<int>> edges;
    std::map<int, int> incoming;
    std::stack<int> check;
    for (const auto j : keys){
        int incomingCtr = 0;
        for (const auto i : keys){
            if (adj[i][j] != 0){
                incomingCtr++;
                edges[i].push(j);
            }
        }
        if (incomingCtr == 0){
            check.push(j);
        }
        incoming[j] = incomingCtr;
    }

    while (!check.empty()){
        int n = check.top();
        check.pop();
        sorted += n + 'A';
        while (!edges[n].empty()){
            int m = edges[n].top();
            edges[n].pop();
            if (--incoming[m]==0){
                check.push(m);
            }
        }
    }

    for (const auto e : edges){
        if (!e.second.empty()){
            std::cout << -1 << std::endl;
            return;
        }
    }

    std::cout << sorted << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++){
        std::cin >> R >> C;
        std::vector<std::vector<int>> wall(30, std::vector<int>(30));
        std::set<int> keys;
        //auto itr = keys.begin();
        for (int r = 0; r < R; r++){
            for (int c = 0; c < C; c++){
                char val;
                std::cin >> val;
                wall[r][c] = val - 'A';
                //itr = keys.insert(itr, val-'A');
                keys.insert(val-'A');
            }
        }
        std::cout << "Case #" << i << ": ";
        solve(wall, keys);
    }

}

