#include <bits/stdc++.h>




int main(){
    int KMax;
    std::cin >> KMax;

    int T = 10;
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        int N = rand()%100000+1;
        int K = rand()%KMax+1;
        std::cout << N << " " << K << std::endl;
        std::set<int> times;
        while (times.size() < N*2){
            times.insert(rand()%1000000000+1);
        }

        int ctr = 0;
        for (const int i : times){
            std::cout << i;
            if (ctr++%2==0) std::cout << " ";
            else std::cout << std::endl;
        }
    }
}