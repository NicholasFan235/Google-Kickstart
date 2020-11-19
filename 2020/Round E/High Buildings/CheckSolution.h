#include <bits/stdc++.h>



std::string checkAnswer(std::vector<int> buildings, int A, int B, int C, int N){
    int numInc = 0;
    int numDec = 0;
    int numMax = 0;

    int currMax = 0;
    for (int i = 0; i < N; i++){
        if (buildings[i] >= currMax){
            if (buildings[i] > currMax) numMax = 0;
            numMax++;
            numInc++;
            currMax = buildings[i];
        }
    }

    currMax = 0;
    for (int i = N-1; i >= 0; i--){
        if (buildings[i] >= currMax){
            numDec++;
            currMax = buildings[i];
        }
    }

    return numInc == A && numDec == B && numMax == C ? "True" : "False";
}



