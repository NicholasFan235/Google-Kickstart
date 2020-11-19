#include <bits/stdc++.h>

struct person{
    int position, money, X;
};

struct Compare{
    bool operator()(const person &a, const person &b){
        if (a.money/a.X == b.money/a.X) return a.position > b.position;
        return a.money/a.X > b.money/a.X;
    }
};

int N, X;
std::priority_queue<person, std::vector<person>, Compare> queue;

void solve(){
    while (!queue.empty()){
        std::cout << queue.top().position << " ";
        queue.pop();
    }
    std::cout << std::endl;
}


int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N >> X;
        int A;
        for (int i = 0; i < N; i++){
            std::cin >> A;
            queue.push({i+1, A-1, X});
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}

