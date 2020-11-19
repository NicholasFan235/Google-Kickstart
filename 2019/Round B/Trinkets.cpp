#include <bits/stdc++.h>

using namespace std;

int type[100000];
int nextLocation[100000];
int segmentTree[400000];
int sumArray[100000];
int typeCounter[100000];
int N, S;

void clear(){
    memset(type, 0, sizeof(type));
    memset(nextLocation, 0, sizeof(nextLocation));
    memset(segmentTree, 0, sizeof(segmentTree));
    memset(sumArray, 0, sizeof(sumArray));
    memset(typeCounter, 0, sizeof(typeCounter));
}

void initiateNextLocations(){
    for (int i = 0; i < N; i++){
        int ctr = 0;
        int j = 0;
        while (true){
            if (type[j] == i){
                nextLocation[i] = j;
                ctr++;
                if (ctr > S){
                    break;
                }
            }
            if (++j >= N){
                nextLocation[i] = N;
                break;
            }
        }
    }
}

void updateNextLocation(int i){
    int j = nextLocation[i];
    while (true){
        j++;
        if (j >= N){
            nextLocation[i] = N;
            break;
        }
        if (type[j] == type[nextLocation[i]]){
            nextLocation[i] = j;
            break;
        }
    }
}

void build(int rootVertex, int left, int right){
    //cout << rootVertex << ": " << left << ", " << right << "\n";
    if (left == right){
        segmentTree[rootVertex] = sumArray[left];
    }
    else {
        int middle = (left + right) / 2;
        build(rootVertex*2, left, middle);
        build(rootVertex*2 + 1, middle+1, right);
        segmentTree[rootVertex] = segmentTree[rootVertex*2] + segmentTree[rootVertex*2 + 1];
    }
}

void createSegmentTree(){
    for (int i = 0; i < N; i++){
        if (typeCounter[type[i]] < S){
            sumArray[i] = 1;
        }
        else if (typeCounter[type[i]] == S){
            sumArray[i] = -S;
        }
        else {
            sumArray[i] = 0;
        }
        typeCounter[type[i]]++;
    }

    build(1, 0, N-1);
}

int sum(int rootVertex, int vertexLeft, int vertexRight, int left, int right){
    if (left>right){
        return 0;
    }
    if (left == vertexLeft && right == vertexRight){
        return segmentTree[rootVertex];
    }
    int vertexMiddle = (vertexLeft + vertexRight) / 2;
    return sum(rootVertex*2, vertexLeft, vertexMiddle, left, min(right, vertexMiddle)) + 
        sum(rootVertex*2+1, vertexMiddle+1, vertexRight, max(left, vertexMiddle+1), right);
}

void update(int rootVertex, int vertexLeft, int vertexRight, int position, int newValue){
    if (vertexLeft == vertexRight){
        segmentTree[rootVertex] = newValue;
    }
    else {
        int vertexMiddle = (vertexLeft + vertexRight) / 2;
        if (position <= vertexMiddle) {
            update(rootVertex*2, vertexLeft, vertexMiddle, position, newValue);
        }
        else {
            update(rootVertex*2 + 1, vertexMiddle + 1, vertexRight, position, newValue);
        }
        segmentTree[rootVertex] = segmentTree[rootVertex*2] + segmentTree[rootVertex*2 + 1];
    }
}

void solve(){
    cin >> N >> S;
    clear();
    for (int i = 0; i < N; i++){
        cin >> type[i];
    }

    initiateNextLocations();
    createSegmentTree();

    int currMax = 0;
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            // sum from i-j
            int max = sum(1, 0, N-1, i, j);
            if (max > currMax){
                currMax = max;
            }
        }
        // Remove ith item
        if (nextLocation[type[i]] < N){
            update(1, 0, N-1, nextLocation[type[i]], 1);
            updateNextLocation(type[i]);
            if (nextLocation[type[i]] < N){
                update(1, 0, N-1, nextLocation[type[i]], -S);
            }
        }
    }

    cout << currMax << "\n";
}

int main(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}