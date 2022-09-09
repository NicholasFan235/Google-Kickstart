#include <bits/stdc++.h>

int R, C;
long ctr;
std::vector<std::vector<int>> board;
std::vector<std::vector<int>> up, down, left, right;

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>> &v)
{
    for (const auto& r : v)
    {
        for (const auto& i : r)
        {
            os << i << " ";
        }
        os << std::endl;
    }
    return os;
}

void findLeft()
{
    left = std::vector<std::vector<int>>(R, std::vector<int>(C));
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            if (c == 0)
            {
                left[r][c] = board[r][c];
                continue;
            }
            left[r][c] = (board[r][c]>0) ? left[r][c-1]+1 : 0;
        }
    }
}

void findRight()
{
    right = std::vector<std::vector<int>>(R, std::vector<int>(C));
    for (int r = 0; r < R; r++)
    {
        for (int c = C-1; c >= 0; c--)
        {
            if (c == C-1)
            {
                right[r][c] = board[r][c];
                continue;
            }
            right[r][c] = (board[r][c]>0) ? right[r][c+1]+1 : 0;
        }
    }
}

void findUp()
{
    up = std::vector<std::vector<int>>(R, std::vector<int>(C));
    for (int c = 0; c < C; c++)
    {
        for (int r = 0; r < R; r++)
        {
            if (r == 0)
            {
                up[r][c] = board[r][c];
                continue;
            }
            up[r][c] = (board[r][c]>0) ? up[r-1][c]+1 : 0;
        }
    }
}

void findDown()
{
    down = std::vector<std::vector<int>>(R, std::vector<int>(C));
    for (int c = 0; c < C; c++)
    {
        for (int r = R-1; r >= 0; r--)
        {
            if (r == R-1)
            {
                down[r][c] = board[r][c];
                continue;
            }
            down[r][c] = (board[r][c]>0) ? down[r+1][c]+1 : 0;
        }
    }
}

void solvePass()
{
    ctr = 0;
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            for (int i = 2; i <= up[r][c]; i++)
            {
                if (left[r][c] >= i*2) ctr++;
                if (i%2==0 && i > 3 && left[r][c] >= i/2) ctr++;
                if (right[r][c] >= i*2) ctr++;
                if (i%2==0 && i > 3 && right[r][c] >= i/2) ctr++;
            }
            for (int i = 2; i <= down[r][c]; i++)
            {
                if (left[r][c] >= i*2) ctr++;
                if (i%2==0 && i > 3 && left[r][c] >= i/2) ctr++;
                if (right[r][c] >= i*2) ctr++;
                if (i%2==0 && i > 3 && right[r][c] >= i/2) ctr++;
            }
        }
    }
}

void solve()
{
    findRight();
    findLeft();
    findUp();
    findDown();

    solvePass();
    std::cout << ctr;
}

int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> R >> C;
        board = std::vector<std::vector<int>>(R+1, std::vector<int>(C+1));
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++)
                std::cin >> board[r][c];

        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
    return 0;
}

