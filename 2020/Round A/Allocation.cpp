#include <iostream>
#include <algorithm>

using namespace std;

int n, b, a[100000];

void calc(){
    cin >> n >> b;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    
    int result = 0;
    for (int i = 0; i < n; i++){
        b -= a[i];
        if (b<0){
            break;
        }
        result++;
    }
    
    cout << result << "\n";
}


int main(){
    int t;
    cin >> t;
    
    for (int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        calc();
    }
}