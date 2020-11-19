#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 100;

set<int> open_ends;
int max_energy[10010];
int max_energy_new[10010];

int S[N_MAX], E[N_MAX], L[N_MAX];
int T, N;

void clear(){
    memset(S, 0, sizeof(S));
    memset(E, 0, sizeof(E));
    memset(L, 0, sizeof(L));

    memset(max_energy, 0, sizeof(max_energy));
    memset(max_energy_new, 0, sizeof(max_energy_new));
    open_ends.clear();
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

void copyMaxEnergy(){
    for (int i = 0; i < 10010; i++){
        max_energy[i] = max_energy_new[i];
    }
}

void solve(){
    cin >> N;
    clear();
    for (int i = 0; i < N; i++){
        cin >> S[i] >> E[i] >> L[i];
    }
    custom_sort();
    
    int curr_max = 0;
    stack<int> newEnds;
    open_ends.insert(0);
    for (int i = 0; i < N; i++){
        for (int end : open_ends){
            int addEnergy = max(0, E[i] - end * L[i]);
            int newMax = max_energy[end] + addEnergy;
            if (max_energy_new[end + S[i]] < newMax){
                max_energy_new[end + S[i]] = newMax;
                if (curr_max < newMax){
                    curr_max = newMax;
                }
            }
            newEnds.push(end + S[i]);
        }
        copyMaxEnergy();
        while (!newEnds.empty()){
            open_ends.insert(newEnds.top());
            newEnds.pop();
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
