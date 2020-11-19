#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <array>
#include <queue>

using namespace std;

struct Delta{
    int total, sessions, difficulty;

    bool operator < (const Delta &other) const{
        return difficulty < other.difficulty;
    }
};


int solve(){
    int n, k;
    cin >> n >> k;

    priority_queue<Delta> deltas;

    int prev;
    cin >> prev;
    for (int i = 0; i < n-1; i++){
        int curr;
        cin >> curr;
        deltas.push({curr-prev, 1, curr-prev});
        prev = curr;
    }

    for (int i = 0; i < k; i++){
        Delta top = deltas.top();
        deltas.pop();
        top.sessions += 1;
        top.difficulty = top.total / top.sessions;
        if (top.total%top.sessions != 0) top.difficulty++;
        deltas.push(top);
    }

    cout << deltas.top().difficulty << "\n";
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i<=t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}