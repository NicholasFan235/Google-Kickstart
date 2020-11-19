#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>


using namespace std;
int b[50][30];
int db[51][1501];
int sb[51];

void calc(){
    int n, k, p;
    memset(db, 0, sizeof(db));
    cin >> n >> k >> p;
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            cin >> b[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            sb[j] = sb[j-1] + b[i-1][j-1];
        }

        for (int j=1; j<=p; j++){
            db[i][j] = 0;
            for (int l = 0; l<=j && l<=k; l++){
                // l num of plates in new stack
                int newBeauty;
                newBeauty = sb[l] + db[i-1][j-l];
                if (newBeauty > db[i][j]){
                    db[i][j] = newBeauty;
                }
            }
        }
    }

    cout << db[n][p] << "\n";
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        calc();
    }
}