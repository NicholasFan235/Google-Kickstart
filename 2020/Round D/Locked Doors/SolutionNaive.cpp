#include <bits/stdc++.h>


const int NMax = 100007;
const int QMax = 100007;

int N, Q, logN, root;
std::array<long, NMax> locks;
std::array<std::pair<int, int>, QMax> queries;

void reset(){
    locks.fill(0);
    queries.fill(std::make_pair(0, 0));
}

int query(int S, int K){
    int lastRoom = S;
    int furthestLeft = S;
    int furthestRight = S;
    for (int k = 1; k < K; k++){
        if (furthestRight == N ||
            (furthestLeft != 1 && locks[furthestLeft-1] < locks[furthestRight])){
            // open left
            furthestLeft--;
            lastRoom = furthestLeft;
        }
        else{
            // open right
            furthestRight++;
            lastRoom = furthestRight;
        }
    }
    return lastRoom;
}

void solve(){
    for (int q = 0; q < Q; q++){
        int answer = query(queries[q].first, queries[q].second);
        std::cout << answer << " ";
    }
    std::cout << std::endl;
}

int main(){
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++){
        reset();
        std::cin >> N >> Q;
        logN = (int)ceil(log2(N));

        for (int n = 1; n < N; n++){
            std::cin >> locks[n];
        }

        for (int q = 0; q < Q; q++){
            int s, k;
            std::cin >> s >> k;
            queries[q] = std::make_pair(s, k);
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }

}


