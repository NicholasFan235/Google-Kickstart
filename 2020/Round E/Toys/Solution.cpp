#include <bits/stdc++.h>


int T, N;
long long ETotal;

std::list<std::pair<int, int>> toysList;
std::vector<std::pair<int, int>> toys;


void reset(){
    toys.clear();
    toysList.clear();
}


void solve(){
    std::copy(toys.begin(), toys.end(), std::back_inserter(toysList));

    int numRemoved = 0;

    long long ECycle = ETotal;
    long long EMax = 0;
    int numRemovedEMax = 0;
    
    while (!toysList.empty()){
        auto it = toysList.begin();
        long long EPref = 0;

        while (it != toysList.end()){
            if (ECycle - it->first < it->second){

                long long Ecurr = ECycle + EPref;
                
                if (Ecurr > EMax){
                    EMax = Ecurr;
                    numRemovedEMax = numRemoved;
                }
                numRemoved++;
                ECycle -= it->first;
                toysList.erase(it);
                break;
            }
            EPref += it->first;
            it++;
        }
        if (it==toysList.end()){
            std::cout << numRemoved << " INDEFINITELY" << std::endl;
            return;
        }
    }

    std::cout << numRemovedEMax << " " << EMax << std::endl;
}


int main(){
    std::cin >> T;
    int E, R;
    for (int t = 1; t <= T; t++){
        ETotal = 0;
        reset();
        std::cin >> N;
        for (int n = 0; n < N; n++){
            std::cin >> E >> R;
            ETotal += E;
            toys.push_back(std::make_pair(E, R));
        }
        std::cout << "Case #" << t << ": ";
        solve();
    }
}

