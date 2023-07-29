#include <bits/stdc++.h>

#define MAX_DICE 50
#define MAX_SIDES 50


int N, M, K;
std::vector<int> finalGroups;

struct State{
    std::vector<int> state;
    std::string hash;
    std::pair<double, double> evaluation;
    State(std::vector<int> s = {}) : state(s) {
        std::sort(state.begin(), state.end());
        auto newIt = std::remove_if(state.begin(), state.end(), [&](int i)->bool{return i==0;});
        state.resize(newIt-state.begin());
        hash = "";
        for (const auto i : state){
            hash += (std::to_string(i) + " ");
        }
        hash.pop_back();
    }
};

std::unordered_map<std::string, State> goodStates;

std::string to_string(const std::vector<int> &v){
    std::string s;
    for (const auto i : v) s += std::to_string(i) + " ";
    s.pop_back();
    return s;    
}

std::string to_string (const std::pair<double, double> &p){
    return "(" + std::to_string(p.first) + ", " + std::to_string(p.second) + ")";
}

void reset(){
    goodStates.clear();
    State base = State({1});
    base.evaluation = std::make_pair(1.0f, 0);
    goodStates["1"] = base;
}

std::pair<double, double> recursion(std::vector<int> &s){
    // return pair of prob to reach state and expected rolls
    State state = State(s);
    if (goodStates.find(state.hash) != goodStates.end()) std::cout << state.hash << " -> " << to_string(goodStates[state.hash].evaluation) << std::endl;
    if (goodStates.find(state.hash) != goodStates.end()) return goodStates[state.hash].evaluation;
    
    double probability = 0;
    double rolls = 0;

    int maxProcessed = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i]==0) continue;
        if (s[i] <= maxProcessed) continue;
        maxProcessed = s[i];

        s[i]--;
        auto newEval = recursion(s);
        int possRolls = std::count(s.begin(), s.end(), s[i]);
        double thisProb = (double)possRolls / (double) M;
        probability += newEval.first * thisProb;
        rolls += newEval.first * newEval.second + (1.0f/thisProb);
        s[i]++;
    }

    state.evaluation = std::make_pair(probability, rolls);
    goodStates[state.hash] = state;
    std::cout << state.hash << " -> " << to_string(state.evaluation) << std::endl;
    return state.evaluation;
}

void solve(){
    reset();
    std::cout << to_string(finalGroups) << std::endl;
    auto result = recursion(finalGroups);
    std::cout << "Probability: " << result.first << "\tExpected Rerolls: " << result.second << std::endl;
}



int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> M >> K;
        finalGroups = std::vector<int>(M, 0);
        for (int k = 0; k < K; k++){
            std::cin >> finalGroups[k];
        }
        std::sort(finalGroups.begin(), finalGroups.end());

        std::cout << "Case #" << t << ": ";
        solve();
    }
}