#include <bits/stdc++.h>

int R, C;
std::vector<std::vector<int>> board;
long ctr;


void solve()
{
    ctr = 0;
    auto checkQueue = std::priority_queue<std::pair<int, std::pair<int, int>>>();
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            checkQueue.push(std::make_pair(board[r][c], std::make_pair(r, c)));
        }
    }

    auto check = [&](int r, int c, int h)
    {
        if (h > board[r][c]+1)
        {
            ctr += h-board[r][c]-1;
            board[r][c] = h-1;
            checkQueue.push(std::make_pair(h-1, std::make_pair(r, c)));
        }
    };

    while (!checkQueue.empty())
    {
        auto curr = checkQueue.top();
        checkQueue.pop();
        int r = curr.second.first;
        int c = curr.second.second;
        int h = curr.first;
        if (curr.first != board[r][c]) continue;

        if (r > 0) check(r-1, c, h);
        if (c > 0) check(r, c-1, h);
        if (r < R-1) check(r+1, c, h);
        if (c < C-1) check(r, c+1, h);
    }

    std::cout << ctr;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> R >> C;
        board = std::vector<std::vector<int>>(R, std::vector<int>(C));
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                std::cin >> board[r][c];
        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
}

