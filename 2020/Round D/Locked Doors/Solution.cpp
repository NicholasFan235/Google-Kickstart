#include <bits/stdc++.h>

const int NMax = 100007;
const int QMax = 100007;


int N, Q, logN, root;
std::array<long, NMax> locks;
std::array<std::pair<int, int>, QMax> queries;

std::array<int, NMax> nextLeft, nextRight;

std::array<std::array<int, 50>, NMax+1> lift;

std::stack<int> nextMax;

struct node{
    int parent = -1, l = -1, r = -1, size = 0;
};
std::array<node, NMax> nodes; // cartesian tree node array

void reset(){
    locks.fill(0);
    queries.fill(std::make_pair(0, 0));
    nextLeft.fill(0);
    nextRight.fill(0);
    while (!nextMax.empty()) nextMax.pop();
    nodes.fill(node());
    root = -1;
    lift.fill(std::array<int,50>());
}

void dfs(int i){
    // i = current node
    if (nodes[i].l != -1){
        dfs(nodes[i].l);
        nodes[i].size += nodes[nodes[i].l].size;
    }
    if (nodes[i].r != -1){
        dfs(nodes[i].r);
        nodes[i].size += nodes[nodes[i].r].size;
    }
    nodes[i].size++;
}

void MakeTree(){
    for (int i = 1; i < N; i++){
        int parent = lift[i][0];
        nodes[i].parent = parent;
        if (i < parent){
            nodes[parent].l = i;
        }
        else{
            nodes[parent].r = i;
        }
    }
}

void BinaryLiftPre(){
    for (int i = 1; i < N; i++){
        if (nextLeft[i] == -1 && nextRight[i] == -1){
            root = i;
        }
        if (nextLeft[i] == -1 || nextRight[i] == -1){
            lift[i][0] = std::max(nextLeft[i], nextRight[i]);
            continue;
        }
        if (locks[nextLeft[i]] < locks[nextRight[i]]){
            lift[i][0] = nextLeft[i];
        }
        else{
            lift[i][0] = nextRight[i];
        }
    }
    
    for (int j = 1; j <= logN; j++){
        for (int i = 1; i < N; i++){
            if (lift[i][j-1] > 0){
                lift[i][j] = lift[ lift[i][j-1] ][j-1];
            }
        }
    }
}

int Query(int q, int k){
    //std::cout << "start: " << q << "\tK: " << k << std::endl;
    for (int i = logN; i >= 0; i--){
        if (lift[q][i] > 0 && nodes[ lift[q][i] ].size < k){
            //std::cout << "q: " << lift[q][i] << std::endl;
            q = lift[q][i];
        }
    }
    return nodes[q].parent;
}

int NextRoom(int s){
    if (s==1) return 1;
    if (s==N) return N-1;
    return locks[s-1] < locks[s] ? s-1 : s;
}

int KthRoom(int S, int K){
    int firstOpened = NextRoom(S);
    //std::cout << "First Opened: " << firstOpened << std::endl;

    if (K==1) return S;
    K--;
        
    if (nodes[firstOpened].size >= K){
        if (firstOpened >= S){
            // if opening to right
            return S+K;
        }
        else{
            // opening to left
            return S-K;
        }
    }
    else{
        // find first node with size > K
        int furthestNode = Query(firstOpened, K);
        //std::cout << "Furthest Node: " << furthestNode << std::endl;
        if (firstOpened < furthestNode){
            // started left of furthest node so open extra doors to right
            // furthest room = furthest node
            return furthestNode + (K - nodes[ nodes[furthestNode].l ].size);
        }
        else{
            // started to right of furthest node, so open extra doors to left
            // furthest room = furthest node + 1 since approaching from right
            return furthestNode + 1 - (K - nodes[ nodes[furthestNode].r ].size);
        }
    }
}

void solve(){
    for (int i = 1; i < N; i++){
        while (!nextMax.empty() && locks[nextMax.top()] <= locks[i]) nextMax.pop();
        if (nextMax.empty()) nextLeft[i] = -1;
        else nextLeft[i] = nextMax.top();
        nextMax.push(i);
    }
    while(!nextMax.empty()) nextMax.pop();
    for (int i = N-1; i > 0; i--){
        while (!nextMax.empty() && locks[nextMax.top()] <= locks[i]) nextMax.pop();
        if (nextMax.empty()) nextRight[i] = -1;
        else nextRight[i] = nextMax.top();
        nextMax.push(i);
    }

    BinaryLiftPre();
    /*
    std::cout << std::endl;
    for (int j = 0; j <= logN; j++){
        for (int i = 0; i < N; i++){
            std::cout << lift[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; */

    MakeTree();

    // dfs for Size of subtrees
    dfs(root);

    for (int i = 0; i < Q; i++){
        int S = queries[i].first;
        int K = queries[i].second;

        int answer = KthRoom(S, K);
        std::cout << answer << " ";
    }
    std::cout << std::endl;
}


int main(){
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; t++){
        reset();
        std::cin >> N >> Q;
        logN = (int)ceil(log2(N));

        for (int n = 1; n < N; n++){
            std::cin >> locks[n];
        }

        for (int q = 0; q < Q; q++){
            int s, k;
            std::cin >> s >> k;
            queries[q] = std::make_pair(s, k);
        }

        std::cout << "Case #" << t << ": ";
        solve();
    }

}


