#include <bits/stdc++.h>

#define MAX_DICE 50
#define MAX_SIDES 50


int N, M, K;
std::vector<int> finalGroups;

std::string makeHash(const std::vector<int> &v){
    std::string hash = "";
        for (const auto i : v){
            hash += (std::to_string(i) + " ");
        }
    hash.pop_back();
    return hash;
}

struct State{
    std::vector<int> state;
    std::string hash;
    double probability;
    State(const std::vector<int> &s = {}, double p=0) : state(s), probability(p) {
        //std::sort(state.begin(), state.end());
        hash = makeHash(state);
    }

    State(const std::vector<int> &s, const std::string &hash, const double p) : state(s), hash(hash), probability(p){}
};

std::unordered_map<std::string, State> states;

std::string to_string(const std::vector<int> &v){
    std::string s;
    for (const auto i : v) s += std::to_string(i) + " ";
    s.pop_back();
    return s;
}

std::string to_string (const std::pair<double, double> &p){
    return "(" + std::to_string(p.first) + ", " + std::to_string(p.second) + ")";
}

bool isGood(const std::vector<int> s){
    for (int i = 0; i < s.size(); i++){
        if (finalGroups[i] < s[i]) return false;
    }
    return true;
}

void reset(){
    states.clear();

    std::vector<int> s = std::vector<int>(M, 0);
    s[M-1] = 1;

    states.insert(std::make_pair("1", State(s, 1.0f))); // Create start
    std::string finalHash = makeHash(finalGroups);
    states.insert(std::make_pair(finalHash, State(finalGroups, finalHash, 0)));
}

void solve(){
    reset();
    std::queue<std::string> checkQueue;
    checkQueue.push("1");
    double expectedRolls = 1;
    
    while (!checkQueue.empty()){
        std::string hash = checkQueue.front();
        checkQueue.pop();

        double probAllowed = 0;
        std::vector<int> s = states[hash].state;
        std::vector<std::tuple<std::string, int, double>> nextStates;

        for (int i = 0; i < s.size(); i++){
            if (i==s.size()-1 || s[i] < s[i+1]){
                s[i]++;
                if (isGood(s)){
                    int numOptions = std::count(s.begin(), s.end(), s[i]-1) + 1;;

                    std::string nextHash = makeHash(s);
                    double thisProb = (double)numOptions / (double)M;
                    probAllowed += thisProb;
                    nextStates.push_back(std::make_tuple(nextHash, i, thisProb));
                }
                s[i]--;
            }
        }

        expectedRolls += states[hash].probability/probAllowed;

        for (const auto next : nextStates){
            double pathProb = states[hash].probability * std::get<2>(next) / probAllowed;
            if (states.find(std::get<0>(next)) == states.end()){
                s[std::get<1>(next)]++;
                states.insert(std::make_pair(std::get<0>(next), State(s, std::get<0>(next), pathProb)));
                s[std::get<1>(next)]--;
                checkQueue.push(std::get<0>(next));
            }
            else{
                states[std::get<0>(next)].probability += pathProb;
            }
        }
    }
    printf("%.10f\n", expectedRolls);
    //std::cout << expectedRolls << std::endl;
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