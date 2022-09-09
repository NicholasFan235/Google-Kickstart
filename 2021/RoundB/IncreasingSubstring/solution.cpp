#include <bits/stdc++.h>

int N;
std::string s;

void solve()
{
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        if (i > 0 && s[i] <= s[i-1]) start = i;
        std::cout << i-start+1 << " ";
    }
}


int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> N >> s;

        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
}
