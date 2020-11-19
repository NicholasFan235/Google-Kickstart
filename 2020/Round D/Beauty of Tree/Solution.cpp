#include <bits/stdc++.h>


int N;
int A, B;

std::array<int, 500000> arr;
std::unordered_map<int, std::vector<int>> tree;
std::unordered_map<int, std::pair<int, int>> paints;
std::vector<int> currPath;

void reset(){
    arr.fill(0);
    tree.clear();
    paints.clear();
    currPath.clear();
}

void dfs(int currNode){
    currPath.push_back(currNode);

    if (tree.count(currNode)){
        for (const int child : tree[currNode]){
            dfs(child);
        }
    }

    paints[currPath.back()].first++;
    paints[currPath.back()].second++;
    if (currPath.size()>A){
        paints[currPath[currPath.size()-A-1]].first+=paints[currPath.back()].first;
    }
    if (currPath.size()>B){
        paints[currPath[currPath.size()-B-1]].second+=paints[currPath.back()].second;
    }

    currPath.pop_back();
}

void solve(){
    /*
    std::stack<int> checkQueue;

    checkQueue.push(0);

    while (!checkQueue.empty()){
        int currNode = checkQueue.top();
        checkQueue.pop();

        if (tree.count(currNode)){
            for (const int child : tree[currNode]){
                checkQueue.push(child);
            }
        }

        while (!currPath.empty() && currPath.back() != arr[currNode-1]-1) currPath.pop_back();
        currPath.push_back(currNode);

        paints[currPath.back()].first++;
        paints[currPath.back()].second++;
        if (currPath.size()>A){
            paints[currPath[currPath.size()-A-1]].first+=paints[currPath.back()].first;
        }
        if (currPath.size()>B){
            paints[currPath[currPath.size()-B-1]].second+=paints[currPath.back()].second;
        }
    }
    */
    dfs(0);

    double beauty = 0;
    for (const auto p : paints){
        beauty += 1 - (1-(double)p.second.first/N)*(1-(double)p.second.second/N);
    }
    printf("%.12f\n", beauty);
}


int main(){
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++){
        reset();
        std::cin >> N >> A >> B;
        for (int i = 0; i < N-1; i++){
            int parent;
            std::cin >> parent;
            arr[i] = parent;
            tree[parent-1].push_back(i+1);
        }
        std::cout << "Case #" << t  << ": ";
        solve();
    }
}



