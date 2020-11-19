#include <bits/stdc++.h>
// 13 mins

int N, K;
std::vector<std::pair<int, int>> intervals;

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b){
    return a.first < b.first;
}

void reset(){
    intervals = std::vector<std::pair<int, int>>();
}

void solve(){
    int ptr = 0;
    int robots = 0;
    std::sort(intervals.begin(), intervals.end(), compare);
    for (const auto interval : intervals){
        int startTime = std::max(interval.first, ptr);
        int dur = interval.second - startTime;
        int needed = (dur + K - 1) / K;
        robots += needed;
        ptr = startTime + K*needed;
    }
    std::cout << robots << std::endl;
}


int main(){
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++){
        reset();
        std::cin >> N >> K;
        int S, E;
        for (int n = 0; n < N; n++){
            std::cin >> S >> E;
            intervals.push_back(std::make_pair(S, E));
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }
}

