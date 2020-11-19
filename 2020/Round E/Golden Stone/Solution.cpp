#include <bits/stdc++.h>

const int NMax = 307;
const int MMax = 507;
const int SMax = 307;
const int RMax = 307;

const long long INF = 1000000000000;

int T, N, M, S, R;

struct node{
    std::array<long long, SMax> costs;
    std::vector<int> links;
    node(){
        costs.fill(INF);
        links.clear();
    }
};
std::array<node, NMax> map;

std::array<std::pair<std::vector<int>, int>, RMax> recipies;
std::queue<std::tuple<int, int, int>> checkQueue;

long long minCost;

void reset(){
    map.fill(node());
    recipies.fill(std::pair<std::vector<int>, int>());
    minCost = LLONG_MAX;
}


void printInfo(){
    for (int n = 1; n <= N; n++){
        std::cout << "Node #" << n << std::endl;
        std::cout << "\tLinks: ";
        for (const int v : map[n].links){
            std::cout << v << " ";
        }
        std::cout << std::endl << "\tCosts: " << std::endl;
        for (int s = 1; s <= S; s++){
            std::cout << "\t\t" << s << ": " << map[n].costs[s] << std::endl;
        }
    }
}


void addToCheckQueue(int u, int s){
    for (const int v : map[u].links){
        checkQueue.push(std::make_tuple(u, v, s));
    }
}


void loopCheckQueue(){
    while (!checkQueue.empty()){
        int u = std::get<0>(checkQueue.front());
        int v = std::get<1>(checkQueue.front());
        int s = std::get<2>(checkQueue.front());
        checkQueue.pop();
        if (map[u].costs[s]+1 < map[v].costs[s]){
            long long cost = map[u].costs[s]+1;
            if (cost >= INF) cost = INF;
            map[v].costs[s] = cost;
            addToCheckQueue(v, s);
        }
    }
}


void checkRecipes(){
    for (int n = 1; n <= N; n++){
        for (int r = 0; r < R; r++){
            long long cost = 0;
            for (const int s : recipies[r].first){
                cost += map[n].costs[s];
            }
            if (cost >= INF){
                cost = INF;
            }
            int target = recipies[r].second;
            if (cost < map[n].costs[target]){
                map[n].costs[target] = cost;
                addToCheckQueue(n, target);
            }
            if (target==1 && cost < minCost){
                minCost = cost;
            }
        }
    }
}


void solve(){
    //std::cout << "Computing... \t";
    while (!checkQueue.empty()){
        loopCheckQueue();
        //printInfo();
        checkRecipes();
    }
    if (minCost >= INF){
        std::cout << -1 << std::endl;
    }
    else{
        std::cout << minCost << std::endl;
    }
}


int main(){
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        reset();
        std::cin >> N >> M >> S >> R;

        int u, v;
        for (int m = 0; m < M; m++){
            std::cin >> u >> v;
            map[u].links.push_back(v);
            map[v].links.push_back(u);
        }

        int c;
        for (int n = 1; n <= N; n++){
            std::cin >> c;
            int s;
            for (int i = 0; i < c; i++){
                std::cin >> s;
                map[n].costs[s] = 0;
                addToCheckQueue(n, s);
            }
        }

        int k;
        for (int r = 0; r < R; r++){
            std::cin >> k;
            int s;
            for (int i = 0; i < k; i++){
                std::cin >> s;
                recipies[r].first.push_back(s);
            }
            std::cin >> s;
            recipies[r].second = s;
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }
}
