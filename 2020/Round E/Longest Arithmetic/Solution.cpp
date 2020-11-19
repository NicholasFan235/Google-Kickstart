#include <bits/stdc++.h>


int T, N;
int A[200005];


void solve(){
    int longest = 2;
    int currDiff = A[1]-A[0];
    int currLength = 2;

    for (int i = 2; i < N; i++){
        int diff = A[i]-A[i-1];
        if (diff == currDiff){
            currLength++;
        }
        else{
            longest = std::max(longest, currLength);
            currLength = 2;
            currDiff = diff;
        }
    }
    longest = std::max(longest, currLength);

    std::cout << longest << std::endl;
}


int main(){
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        std::cin >> N;
        for (int n = 0; n < N; n++){
            std::cin >> A[n];
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}
