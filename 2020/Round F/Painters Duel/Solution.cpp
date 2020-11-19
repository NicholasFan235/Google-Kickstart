#include <bits/stdc++.h>
// 1 hour 40 mins

int S, C;
std::vector<std::vector<bool>> museum;
std::pair<int, int> alma, berthe;

void reset(){
    museum = std::vector<std::vector<bool>>(0, std::vector<bool>());
}

void makeMuseum(){
    for (int s = 0; s <= S; s++){
        museum.push_back(std::vector<bool>(s*2, true));
    }
}

void getNeighbours(const std::pair<int, int> &p, std::vector<std::pair<int, int>> &neighbours){
    std::vector<std::pair<int, int>> tempN;
    if (p.second > 1) tempN.push_back(std::make_pair(p.first, p.second-1));
    if (p.second < p.first*2-1) tempN.push_back(std::make_pair(p.first, p.second+1));
    if (p.second%2==0){
        // try above
        if (p.first > 1) tempN.push_back(std::make_pair(p.first-1, p.second-1));
    }
    else{
        // below
        if (p.first < S) tempN.push_back(std::make_pair(p.first+1, p.second+1));
    }
    for (const auto p : tempN){
        if (museum[p.first][p.second]) neighbours.push_back(p);
    }
}

int predictScore(int turn, bool canTerminate){
    // Predict what the score will be by recursion
    //std::cout << (turn==0?"alma's" : "berthe's") << " turn, ";
    //printf("alma: (%d, %d), berthe: (%d, %d)\n", alma.first, alma.second, berthe.first, berthe.second);
    std::vector<std::pair<int, int>> neighbours;

    if (turn == 0){
        // alma's turn
        getNeighbours(alma, neighbours);
    }
    else{
        // berthe's turn
        getNeighbours(berthe, neighbours);
    }

    if (neighbours.size()==0){
        if (canTerminate) return 0;
        else return predictScore((turn+1)%2, true);
    }

    int bestScore;
    if (turn == 0){
        // alma
        bestScore = INT_MIN;
        std::pair<int, int> prevLocation = alma;
        for (const auto n : neighbours){
            alma = n;
            museum[n.first][n.second] = false;
            int predScore = predictScore(1, false);
            if (predScore > bestScore) bestScore = predScore;
            museum[n.first][n.second] = true;
        }
        alma = prevLocation;
        bestScore++;
    }
    else{
        // berthe
        bestScore = INT_MAX;
        std::pair<int, int> prevLocation = berthe;
        for (const auto n : neighbours){
            berthe = n;
            museum[n.first][n.second] = false;
            int predScore = predictScore(0, false);
            if (predScore < bestScore) bestScore = predScore;
            museum[n.first][n.second] = true;
        }
        berthe = prevLocation;
        bestScore--;
    }
    
    return bestScore;
}

void solve(){
    std::cout << predictScore(0, false) << std::endl;
}

int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        reset();
        int Ra, Pa, Rb, Pb;
        std::cin >> S >> Ra >> Pa >> Rb >> Pb >> C;
        alma = std::make_pair(Ra, Pa);
        berthe = std::make_pair(Rb, Pb);
        makeMuseum();
        int rc, pc;
        for (int c = 0; c < C; c++){
            std::cin >> rc >> pc;
            museum[rc][pc] = false;
        }
        museum[alma.first][alma.second] = false;
        museum[berthe.first][berthe.second] = false;

        std::cout << "Case #" << t << ": ";
        solve();
    }
}
