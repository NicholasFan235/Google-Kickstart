#include <bits/stdc++.h>

#define maxn 200005

double lg2f[maxn];
double lastX[100005];
double lastY[100005];

void makeLogTable(){
    lg2f[0] = 0;
    for (int i = 1; i < maxn; i++){
        lg2f[i] = lg2f[i-1] + log2(i);
    }
}

double bin(int n, int r){
    return pow(2, lg2f[n] - lg2f[r] - lg2f[n-r] - n);
}

void solve(int W, int H, int L, int U, int R, int D){
    double prob = 0;
    
    lastX[0] = pow(2, -W+1);
    lastY[0] = pow(2, -H+1);
    for (int i = 1; i < H; i++){
        lastX[i] = lastX[i-1] + 0.5f * bin(W-2+i, i);
    }
    for (int i = 1; i < W; i++){
        lastY[i] = lastY[i-1] + 0.5f * bin(H-2+i, i);
    }

    for (int i = 0; i < L-1; i++){
        int d = D+L-i-2;
        if (d > H-1) continue;
        if (d==H-1){
            prob += lastY[i];
        }
        else{
            prob += bin(d+i, i);
        }
    }

    for (int i = 0; i < U-1; i++){
        int r = R+U-i-2;
        if (r > W-1) continue;
        if (r == W-1){
            prob += lastX[i];
        }
        else{
            prob += bin(r+i, i);
        }
    }

    printf("%.12lf\n", prob);
}

int main(){
    int T;
    std::cin >> T;

    makeLogTable();

    for (int i = 1; i <= T; i++){
        int W, H, L, U, R, D;

        std::cin >> W >> H >> L >> U >> R >> D;

        std::cout << "Case #" << i << ": ";
        solve(W, H, L, U, R, D);
    }
}

