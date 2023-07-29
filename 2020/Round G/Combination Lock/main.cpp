#include <bits/stdc++.h>


int W;
int N;
std::vector<int> X;
std::map<int, int> Values;


void solve()
{
    long long int dist = LONG_LONG_MAX;
    for (const auto val : Values)
    {
        long long int curr = 0;
        for (const auto val2 : Values)
        {
            curr += val2.second * std::min(
                (val.first - val2.first + N) % N,
                (val2.first - val.first + N) % N
            );
        }
        if (curr < dist)
            dist = curr;
    }
    std::cout << dist << std::endl;
}


int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> W >> N;
        X = std::vector<int>(W);
        Values.clear();
        for (int i = 0; i < W; i++)
        {
            std::cin >> X[i];
            Values[X[i]]++;
        }
        printf("Case #%d: ", t);
        solve();
    }
}