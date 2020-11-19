#include <bits/stdc++.h>

long N, L1, R1, A, B, C1, C2, M;
std::priority_queue<std::pair<int, std::pair<int, bool>>> intervals;

void generateInvervals(){
    while (!intervals.empty()) intervals.pop();
    long long xPrev = L1;
    long long yPrev = R1;
    int ctr = 1;
    while (ctr++ < N){
        long long x = (A*xPrev + B*yPrev + C1)%M;
        long long y = (A*yPrev + B*xPrev + C2)%M;
        intervals.push(std::make_pair(std::min(x, y), std::make_pair(ctr, true)));
        intervals.push(std::make_pair(std::max(x, y), std::make_pair(ctr, false)));
    }
}

void solve(){
    generateInvervals();
    std::set<long> covers;
    std::unordered_map<long, long> singles;
    long prevMark = 0;
    long maxCovered = 0;
    while (!intervals.empty()){
        auto mark = intervals.top();
        intervals.pop();
        if (mark.second.second = true){
            if (covers.size() == 1){
                
            }
            covers.insert(mark.second.first);
        }
        else{
            covers.erase(mark.second.first);
        }
        prevMark = mark.first;
    }
}


int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> L1 >> R1 >> A >> B >> C1 >> C2 >> M;
        std::cout << "Case #" << t << ": ";
        solve();
    }
}