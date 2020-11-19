#include <bits/stdc++.h>
// 15:46

int N, M, K;
std::vector<int> finalGroups;

std::unordered_map<std::vector<int>, std::pair<int>> solvedStates;



void reset(){

}

std::pair<int, int> recursion(std::vector<int> state){
    // return pair of prob to reach state and expected rolls

    for (int i = 0; i < state.size(); i++){

    }
}

void solve(){

}



int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> M >> K;
        finalGroups = std::vector<int>(K);
        for (int k = 0; k < K; k++){
            std::cin >> finalGroups[k];
        }
    }
}