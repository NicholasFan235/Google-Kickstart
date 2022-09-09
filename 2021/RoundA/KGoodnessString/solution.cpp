#include <bits/stdc++.h>


std::string s;
int N, K;

int solve()
{
    int score = 0;
    for (int i = 0; i < N/2; i++)
    {
        score += s[i] != s[N-i-1];
    }
    return abs(K-score);
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> N >> K;
        std::cin >> s;
        std::cout << "Case #" << t << ": " << solve() << std::endl;
    }
}
