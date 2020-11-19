#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100;

int max_energy[101][10010];

int S[N_MAX], E[N_MAX], L[N_MAX];
int T, N;

void clear(){
    memset(S, 0, sizeof(S));
    memset(E, 0, sizeof(E));
    memset(L, 0, sizeof(L));

    memset(max_energy, 0, sizeof(max_energy));
}

void swap(int i, int j){
    int temp = S[i];
    S[i] = S[j];
    S[j] = temp;
    temp = E[i];
    E[i] = E[j];
    E[j] = temp;
    temp = L[i];
    L[i] = L[j];
    L[j] = temp;
}

int compare(int i, int j){
    int i_first = S[i] * L[j];
    int j_first = S[j] * L[i];
    return i_first > j_first;
}

void custom_sort(){
    int swaps = 1;
    while (swaps > 0){
        swaps = 0;
        for (int j = 0; j < N-1; j++){
            if (compare(j, j+1)){
                swap(j, j+1);
                swaps++;
            }
        }
    }
}

void print_stones(){
    cout << "\n";
    for (int i = 0; i < N; i++){
        cout << S[i] << " " << E[i] << " " << L[i] << "\n";
    }
}

void solve(){
    cin >> N;
    clear();
    int S_sum;
    for (int i = 0; i < N; i++){
        cin >> S[i] >> E[i] >> L[i];
        S_sum += S[i];
    }
    custom_sort();
    
    int curr_max = 0;
    for (int i = N-1; i >= 0; i--){
        for (int t = 0; t < S_sum; t++){
            max_energy[i][t] = max(max_energy[i+1][t], max_energy[i+1][t+S[i]] + max(0, E[i]-t*L[i]));
            if (max_energy[i][t] > curr_max)
                curr_max = max_energy[i][t];
        }
    }

    cout << curr_max << "\n";
}

int main(){
    cin >> T;
    for (int i = 1; i <= T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
