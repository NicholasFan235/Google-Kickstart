#include <bits/stdc++.h>

using namespace std;

const int NUM_LETTERS = 26;

int parities[100001];

void solve(){
    int N, Q;
    cin >> N >> Q;
    string letters;
    cin >> letters;

    memset(parities, 0, sizeof(parities));
    for (int i = 0; i < N; i++){
        int letter = (int) letters[i] - 'A';
        parities[i+1] = parities[i] ^ (1 << letter);
    }

    int yesses = 0;
    for (int i = 0; i < Q; i++){
        int L, R;
        cin >> L >> R;
        int parity = parities[L-1] ^ parities[R];
        if ((R-L+1)%2==0){
            if (parity == 0){
                yesses++;
            }
        }
        else
        {
            if (parity == 0 || parity && !(parity & (parity-1))){
                yesses++;
            }
        }
    }
    cout << yesses << "\n";
}

int main(){
    int T;
    cin >> T;
    for (int i = 1; i<=T; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}
