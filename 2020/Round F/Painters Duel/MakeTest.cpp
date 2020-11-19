#include <bits/stdc++.h>


int main(){
    srand(time(0));
    int T = 10;
    std::cout << T << std::endl;
    for (int t = 0; t < T; t++){
        int S = (rand()%4)+2;
        int Ra = (rand()%S)+1;
        int Pa = (rand()%(2*Ra-1)) + 1;
        int Rb = 0, Pb = 0;
        while (Rb==0 || (Ra==Rb && Pa==Pb)){
            Rb = (rand()%S)+1;
            Pb = (rand()%(2*Rb-1)) + 1;
        }

        int C = 0;
        std::vector<std::pair<int, int>> blocks;
        for (int i = 1; i <= S; i++){
            for (int j = 1; j < 2*i; j++){
                if (rand()%100 > 90){
                    if ((i==Ra && j == Pa)||(i==Rb && j == Pb)) continue;
                    C++;
                    blocks.push_back(std::make_pair(i, j));
                }
            }
        }

        printf("%d %d %d %d %d %d\n", S, Ra, Pa, Rb, Pb, C);
        for (const auto b : blocks){
            printf("%d %d\n", b.first, b.second);
        }
    }
}