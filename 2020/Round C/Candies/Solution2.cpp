#include <iostream>
#include <cstring>
using namespace std;
 
int t, n, q, l, r, p, d;
long long a[200005], bit[2][200005], ans;
char C;
 
long long query(int x, int y){
    long long ret = 0;
    while (y){
        ret += bit[x][y];
        y -= y & (-y);
    }
    return ret;
}
void update(int x, int y, long long z){
    while (y <= n){
        bit[x][y] += z;
        y += y & (-y);
    }
}
 
int main() {
    cin >> t;
    for (int Case = 1; Case <= t; Case++){
        cin >> n >> q;
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if (i % 2 == 1){
                update(0, i, a[i]*i);
                update(1, i, a[i]);
            }
            else{
                update(0, i, -a[i]*i);
                update(1, i, -a[i]);
            }
        }
        ans = 0;
        for (int i = 0; i < q; i++){
            cin >> C;
            if (C == 'Q'){
                cin >> l >> r;
                long long ret = query(0, r)-query(0, l-1);
                ret -= (l-1) * (query(1, r)-query(1, l-1));
                if (l%2 == 0) ret = -ret;
                ans += ret;
            }
            else{
                cin >> p >> d;
                d -= a[p];
                if (p % 2 == 1){
                    update(0, p, d*p);
                    update(1, p, d);
                }
                else{
                    update(0, p, -d*p);
                    update(1, p, -d);
                }
                a[p] += d;
            }
        }
        cout << "Case #" << Case << ": " << ans << "\n";
    }
}