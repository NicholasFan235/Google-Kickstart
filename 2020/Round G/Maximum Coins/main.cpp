// 3:27
#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> C;

void solve()
{
    std::vector<long long int> sums = std::vector<long long int>(2*N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sums[i-j+N] += C[i][j];
        }
    }

    long long max = 0;
    for (int i = 0; i < sums.size(); i++)
    {
        max = std::max(sums[i], max);
    }
    std::cout << max;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> N;
        C = std::vector<std::vector<int>>(N, std::vector<int>(N));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cin >> C[i][j];
            }
        }

        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
}