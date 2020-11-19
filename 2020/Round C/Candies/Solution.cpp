#include <bits/stdc++.h>


const int nMax = 524288;

int N, Q;
std::array<long long, nMax> A;
std::array<long long, nMax> iA;
std::array<long long, 2*nMax> SegSquare;
std::array<long long, 2*nMax> SegTri;
std::vector<std::tuple<char, int, int>> O;
long long total;

void reset(){
    A.fill(0);
    iA.fill(0);
    SegSquare.fill(0);
    SegTri.fill(0);
    O.clear();
    total = 0;
}

long long getSum(const std::array<long long, 2*nMax> &st, int ss, int se, int qs, int qe, int si){
    // segment start, segment end, query start, query end, curr node
    if (qs <= ss && qe >= se){
        // if query is part of segment
        return st[si];
    }
    if (se < qs || ss > qe){
        // if query is outside range
        return 0;
    }
    // Part overlap
    int mid = (ss+se)/2;
    return getSum(st, ss, mid, qs, qe, 2*si+1) +
        getSum(st, mid+1, se, qs, qe, 2*si+2);
}

long long constructST(const std::array<long long, nMax> &arr, std::array<long long, 2*nMax> &st, int ss, int se, int si){
    // seg start, seg end, curr node
    if (ss==se){
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    st[si] = constructST(arr, st, ss, mid, si*2+1) +
        constructST(arr, st, mid+1, se, si*2+2);
    return st[si];
}

void updateValue(std::array<long long, 2*nMax> &st, int ss, int se, int i, int diff, int si){
    // segment start, segment end, index of element in input arr, change, index of node
    if (i < ss || i > se) return; // outside range
    // is in range, so update this node and children
    st[si] = st[si]+diff;
    if (se != ss){
        int mid = (ss+se)/2;
        updateValue(st, ss, mid, i, diff, 2*si+1);
        updateValue(st, mid+1, se, i, diff, 2*si+2);
    }
}

long long getSweetness(int i, int j){
    int mul = (i%2==0)*2-1;
    //long long tri = getSum(SegTri, 0, N-1, i, j, 0);
    //long long square =  i * getSum(SegSquare, 0, N-1, i, j, 0);
    //std::cout << "mul: " << mul << "\ttri: " << tri << "\tsquare: " << square << std::endl;
    //long sweetness = mul * (getSum(SegTri, 0, N-1, i, j, 0) -
    //    i * getSum(SegSquare, 0, N-1, i, j, 0));
    return (long long)mul * (getSum(SegTri, 0, N-1, i, j, 0) -
        (long long)i * getSum(SegSquare, 0, N-1, i, j, 0));
}

void updateSweetness(int i, int newVal){
    newVal *= (i%2==0)*2-1;
    int diffSquare = newVal - A[i];
    A[i] = newVal;
    updateValue(SegSquare, 0, N-1, i, diffSquare, 0);
    int diffTri = (i+1)*newVal - iA[i];
    iA[i] = (i+1)*newVal;
    updateValue(SegTri, 0, N-1, i, diffTri, 0);
}

void solve(){
    // Make seg trees
    constructST(A, SegSquare, 0, N-1, 0);
    constructST(iA, SegTri, 0, N-1, 0);

    for (const auto o : O){
        char q = std::get<0>(o);
        int i = std::get<1>(o);
        int j = std::get<2>(o);

        if (q=='Q'){
            //std::cout << "Q: " << i << " -> " << j << std::endl;
            long long sweet = getSweetness(i-1, j-1);
            total += sweet;
        }
        if (q=='U'){
            updateSweetness(i-1, j);
        }
    }

    std::cout << total << std::endl;
}


int main(){
    int T;
    std::cin >> T;

    for (int i = 1; i <= T; i++){
        std::cout << "Case #" << i << ": ";

        reset();
        
        std::cin >> N >> Q;
        for (int j = 0; j < N; j++){
            int a;
            std::cin >> a;
            a *= (j%2==0)*2-1;
            A[j] = a;
            iA[j] = (long long)a*(j+1);
        }

        for (int j = 0; j < Q; j++){
            char c;
            int i1, i2;
            std::cin >> c >> i1 >> i2;
            O.push_back(std::make_tuple(c, i1, i2));
        }

        solve();
    }
}

