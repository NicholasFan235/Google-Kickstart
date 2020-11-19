#include <bits/stdc++.h>

using namespace std;

map<char, int> DIRECTIONS = { {'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

int T, N, R, C;

map<array<int, 3>, array<int, 2>> from_to, to_from;

void reset(){
    from_to.clear();
    to_from.clear();
}

array<int, 3> toKey(array<int, 2> a, int b){
    return {a[0], a[1], b};
}

array<int, 2> getTo(int r, int c, int dir){
    if (from_to.find({r, c, dir})==from_to.end()){
        switch (dir){
            case 0:
                return {r-1, c};
                break;
            case 1:
                return {r, c+1};
                break;
            case 2:
                return {r+1, c};
                break;
            case 3:
                return {r, c-1};
                break;
        }
    }
    else {
        return from_to[{r, c, dir}];
    }
}

array<int, 2> getFrom(int r, int c, int dir){
    if (to_from.find({r, c, dir}) == to_from.end()){
        switch (dir){
            case 0:
                return {r+1, c};
                break;
            case 1:
                return {r, c-1};
                break;
            case 2:
                return {r-1, c};
                break;
            case 3:
                return {r, c+1};
                break;
        }
    }
    else {
        return to_from[{r, c, dir}];
    }
}

void makeOccupied(int r, int c){
    for (int i = 0; i < 4; i++){
        array<int, 2> from = getFrom(r, c, i);
        array<int, 2> to = getTo(r, c, i);
        //cout << "Link: (" << from[0] << ", " << from[1] << ") (" << to[0] << ", " << to[1] << ")\n";
        from_to[toKey(from, i)] = to;
        to_from[toKey(to, i)] = from;
    }
}

void solve(){
    int r, c;
    cin >> N >> R >> C >> r >> c;
    reset();
    makeOccupied(r, c);
    string instructions;
    cin >> instructions;
    array<int, 2> nextPosition = {r, c};
    for (int i = 0; i < N; i++){
        int dir = DIRECTIONS[instructions[i]];
        nextPosition = getTo(nextPosition[0], nextPosition[1], dir);
        //cout << "(" << nextPosition[0] << ", " << nextPosition[1] << ")\n";
        makeOccupied(nextPosition[0], nextPosition[1]);
    }
    cout << nextPosition[0] << " " << nextPosition[1] << "\n";
}

int main(){
    cin >> T;
    for (int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
