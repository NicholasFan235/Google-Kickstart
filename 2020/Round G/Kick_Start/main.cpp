#include <bits/stdc++.h>

std::string s;
std::vector<int> kickPositions;
std::vector<int> startPositions;


void reset()
{
    kickPositions = std::vector<int>();
    startPositions = std::vector<int>();
}

void findSubstrings(std::vector<int>& vec, const std::string& substr)
{
    size_t pos = s.find(substr);
    while (pos != std::string::npos)
    {
        vec.push_back(pos);
        pos = s.find(substr, pos+1);
    }
}

void printVec(const std::vector<int>& vec)
{
    for (const auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void solve()
{
    reset();
    findSubstrings(kickPositions, "KICK");
    findSubstrings(startPositions, "START");
    
    int numKicks = 0;
    int startPos = 0;
    
    long ans = 0;

    for (const int kickPos : kickPositions)
    {
        while (startPos < startPositions.size() && startPositions[startPos] < kickPos)
        {
            ans += numKicks;
            startPos++;
        }
        numKicks++;
    }
    ans += numKicks * (startPositions.size() - startPos);
    
    std::cout << ans;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> s;

        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
}


