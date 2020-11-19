#include <bits/stdc++.h>


int T, N;
long long ETotal;

std::list<std::pair<int, int>> toysList;
std::vector<std::pair<int, int>> toys;

class Compare{
    public:
    bool operator()(const std::list<std::pair<int, int>>::iterator &a,
        const std::list<std::pair<int, int>>::iterator &b){
        return a->first+a->second < b->first+b->second;
    }
};

std::priority_queue<std::list<std::pair<int, int>>::iterator,
    std::vector< std::list<std::pair<int, int>>::iterator >,
    Compare> checkQueue;


void reset(){
    toys.clear();
    toysList.clear();
    while (!checkQueue.empty()){
        checkQueue.pop();
    }
}


void solve(){

    int numRemoved = 0;

    long long ECycle = ETotal;
    long long EMax = 0;
    int numRemovedMax = 0;
    long long EPref = 0;
    
    for (const auto toy : toys){
        toysList.push_front(toy);
        checkQueue.push(toysList.begin());
        EPref += toy.first;

        while (!checkQueue.empty() && checkQueue.top()->first + checkQueue.top()->second > ECycle){
            ECycle -= checkQueue.top()->first;
            EPref -= checkQueue.top()->first;
            numRemoved++;
            toysList.erase(checkQueue.top());
            checkQueue.pop();
        }

        long long ECurr = ECycle + EPref;
        if (toysList.front() == toy){
            if (ECurr > EMax){
                numRemovedMax = numRemoved;
                EMax = ECurr;
            }
        }
        else{
            ECurr += toy.first;
            if (ECurr > EMax){
                numRemovedMax = numRemoved-1;
                EMax = ECurr;
            }
        }
        //std::cout << ECurr << " " << numRemoved << std::endl;
    }

    if (toysList.empty()){
        std::cout << numRemovedMax << " " << EMax << std::endl;
        return;
    }
    else{
        std::cout << toys.size() - toysList.size() << " " << "INDEFINITELY" << std::endl;
        return;
    }
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

