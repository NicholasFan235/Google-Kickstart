#include <bits/stdc++.h>

const int T = 1;

const int NMin = 2;
const int NMax = 300;
const int MMin = 1;
const int MMax = 500;
const int SMin = 2;
const int SMax = 300;
const int RMin = 1;
const int RMax = 300;

int N, M, S, R;

std::array<std::pair<std::vector<int>, int>, RMax> recipies;
std::array<std::set<int>, NMax+1> stones;
std::array<std::array<int, NMax+1>, NMax+1> adj;

void reset(){
    recipies.fill(std::pair<std::vector<int>, int>());
    stones.fill(std::set<int>());
    adj.fill(std::array<int, NMax+1>());
}

void printInfo(){
    printf("%d %d %d %d\n", N, M, S, R);
    // Print map
    for (int i = 1; i <= N; i++){
        for (int j = 1; j < i; j++){
            if (adj[i][j] == 1){
                printf("%d %d\n", i, j);
            }
        }
    }
    // Print start stones
    for (int i = 1; i <= N; i++){
        std::cout << stones[i].size() << " ";
        for (const int s : stones[i]){
            std::cout << s << " ";
        }
        std::cout << std::endl;
    }
    // Print recipies
    for (int r = 0; r < R; r++){
        std::cout << recipies[r].first.size() << " ";
        for (const int s : recipies[r].first){
            std::cout << s << " ";
        }
        std::cout << recipies[r].second << std::endl;
    }
}

int main(){
    srand(time(NULL));
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        N = rand()%(NMax-NMin+1) + NMin;
        S = rand()%(SMax-SMin+1) + SMin;
        R = rand()%(RMax-RMin+1) + RMin;
        M = 0;
        
        // Generate adjacencies
        for (int i = 1; i <= N; i++){
            int other = i;
            while (other == i){
                other = rand()%N+1;
            }
            if (adj[i][other]==0){
                M++;
            }
            adj[i][other] = 1;
            adj[other][i] = 1;
        }

        int MTot = 0;// rand()%(MMax-MMin+1) + MMin;
        while (MTot>M){
            int i = rand()%N+1;
            int other = i;
            while (other==i){
                other = rand()%N+1;
            }
            if (adj[i][other]==0){
                M++;
            }
            adj[i][other] = 1;
            adj[other][i] = 1;
        }

        // Generate stone starting
        for (int s = 2; s <= S; s++){
            int n = rand()%N+1;
            stones[n].insert(s);
        }
        int extra = 0;//rand()%(S+1);
        for (int i = 0; i < extra; i++){
            int s = rand()%(S-1)+2;
            int n = rand()%N+1;
            stones[n].insert(s);
        }

        // Generate recipies
        for (int r = 0; r < R; r++){
            int k = rand()%3+1;
            for (int i = 0; i < k; i++){
                recipies[r].first.push_back(rand()%(S-1)+2);
            }
            recipies[r].second = rand()%(S-1)+2;
        }
        recipies[0].second = 1;

        // Output
        printInfo();
    }
}


