#include <bits/stdc++.h>


int T, R, C, K;


std::array<std::array<int, 512>, 512> board;
std::array<std::array<int, 1024>, 512> minSt;
std::array<std::array<int, 1024>, 512> maxSt;
std::array<std::array<int, 512>, 512> maxLength;


void reset(){
    board.fill(std::array<int, 512>());
    minSt.fill(std::array<int, 1024>());
    maxSt.fill(std::array<int, 1024>());
    maxLength.fill(std::array<int, 512>());
}

int maxLength(int r, int c, int lowBound, int upBound, int curr){
    if (lowBound==curr){
        return curr;
    }
}

int constructStMin(int r, int ss, int se, int si){
    if (ss==se){
        minSt[r][si] = board[r][ss];
        return board[r][ss];
    }
    int mid = (ss+se)/2;
    minSt[r][si] = std::min(
        constructStMin(r, ss, mid, 2*si+1),
        constructStMin(r, mid+1, se, 2*si+2)
    );
}

int constructStMax(int r, int ss, int se, int si){
    if (ss==se){
        maxSt[r][si] = board[r][ss];
        return board[r][ss];
    }
    int mid = (ss+se)/2;
    maxSt[r][si] = std::max(
        constructStMax(r, ss, mid, 2*si+1),
        constructStMax(r, mid+1, se, 2*si+2)
    );
}

int getMin(int r, int ss, int se, int qs, int qe, int si){
    if (qs<=ss && qe>=se){
        return minSt[r][si];
    }
    if (qs>ss || qe<se){
        return INT_MAX;
    }
    int mid = (ss+se)/2;
    return std::min(
        getMin(r, ss, mid, qs, qe, 2*si+1),
        getMin(r, mid+1, se, qs, qe, 2*si+2)
    );
}

int getMax(int r, int ss, int se, int qs, int qe, int si){
    if (qs<=ss && qe>=se){
        return maxSt[r][si];
    }
    if (qs>ss || qe<se){
        return 0;
    }
    int mid = (ss+se)/2;
    return std::max(
        getMax(r, ss, mid, qs, qe, 2*si+1),
        getMax(r, mid+1, se, qs, qe, 2*si+2)
    );
}

void buildSegmentTrees(){
    for (int r = 0; r < R; r++){
        constructStMin(r, 0, C, 0);
        constructStMax(r, 0, C, 0);
    }
}


int main(){

}


