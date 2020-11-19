#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <array>
#include <math.h>

using namespace std;

array<int, 2> dm[100000];

int compFunct(array<int, 2> a, array<int, 2> b){
    int da = ceil((float)a[0]/(float)a[1]);
    int db = ceil((float)b[0]/(float)b[1]);
    return da > db;
}

int solve(){
    int n, k;
    cin >> n >> k;

    memset(dm, 0, sizeof(dm));

    int prev;
    cin >> prev;
    for (int i = 0; i < n-1; i++){
        int curr;
        cin >> curr;
        dm[i][0] = curr-prev;
        dm[i][1] = 1;
        prev = curr;
    }

    //array<int, 2>::iterator result;
    for (int i = 0; i < k; i++){
        //result = max_element(dm, dm+n-1, compFunct);
        sort(dm, dm+n-1, compFunct);
        dm[0][1]+=1;
    }

    sort(dm, dm+n-1, compFunct);
    cout << ceil((float)dm[0][0]/dm[0][1]) << "\n";
}

int main(){
    int t;
    cin >> t;
    for (int i = 1; i<=t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
}