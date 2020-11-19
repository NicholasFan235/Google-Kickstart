#include <bits/stdc++.h>


int R, C;
std::vector<std::vector<int>> heightMap;
std::vector<std::vector<int>> waterMap;

void solve(){
    waterMap = std::vector<std::vector<int>>(R, std::vector<int>(C, INT_MAX));

    std::queue<std::pair<int, int>> checkQueue;
    checkQueue.push(std::make_pair(0, 0));
    while(!checkQueue.empty()){
        auto curr = checkQueue.front();
        int i = curr.first, j = curr.second;
        checkQueue.pop();

        // check if water is at bottom
        if (waterMap[i][j] == heightMap[i][j]) continue;

        // find new water level from neighbours
        int newLevel = waterMap[i][j];
        if (i == 0 || i == R-1 || j == 0 || j == C-1){
            // at edge
            newLevel = heightMap[i][j];
        }
        else{
            newLevel = std::min({
                waterMap[i+1][j],
                waterMap[i-1][j],
                waterMap[i][j-1],
                waterMap[i][j+1],
            });
            newLevel = std::max(newLevel, heightMap[i][j]);
        }
        
        if (newLevel == waterMap[i][j]) continue; // if level didn't change
        waterMap[i][j] = newLevel;

        // check neighbours
        if (i>0) checkQueue.push(std::make_pair(i-1, j));
        if (i<R-1) checkQueue.push(std::make_pair(i+1, j));
        if (j>0) checkQueue.push(std::make_pair(i, j-1));
        if (j<C-1) checkQueue.push(std::make_pair(i, j+1));
    }

    int totalWater = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            totalWater += waterMap[i][j] - heightMap[i][j];
        }
    }

    std::cout << totalWater << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> R >> C;
        heightMap = std::vector<std::vector<int>>(R, std::vector<int>(C));
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                std::cin >> heightMap[i][j];
            }
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}