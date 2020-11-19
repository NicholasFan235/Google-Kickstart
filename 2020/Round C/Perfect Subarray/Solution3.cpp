#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 7;
const int INF = 1e7 + 7;

unordered_map<int,int> mp;
int a[maxn],sum[maxn];

int main() {
    int T;scanf("%d",&T);
    int kase = 0;
    while(T--) {
        int n;scanf("%d",&n);
        int mi = 0;
        for(int i = 1;i <= n;i++) {
            scanf("%d",&a[i]);
            sum[i] = sum[i - 1] + a[i];
            mi = min(mi,sum[i]);
        }
        mp.clear();
        ll ans = 0;
        mp[0] = 1;
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j * j < INF;j++) {
                if(mp.count(sum[i] - j * j)) ans += mp[sum[i] - j * j];
                if(sum[i] - j * j < mi) break;
            }
            mp[sum[i]]++;
        }
        
        printf("Case #%d: %lld\n",++kase,ans);
    }
    return 0;
}
