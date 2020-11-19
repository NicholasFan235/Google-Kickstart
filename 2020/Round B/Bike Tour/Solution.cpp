#include <bits/stdc++.h>


void solve(){
    int N;
    std::cin >> N;

    std::vector<int> H;
    for (int i = 0; i < N; i++){
        int h;
        std::cin >> h;
        H.push_back(h);
    }

    bool isup = false;
    int prev = H[0];
    int ctr = 0;
    for (int i = 1; i < N; i++){
        if (isup == true && H[i] < prev){
            ctr++;
        }
        isup = H[i] > prev;
        prev = H[i];
    }

    std::cout << ctr << std::endl;
}


int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        std::cout << "Case #" << i << ": ";
        solve();;
    }


    return 0;
}

