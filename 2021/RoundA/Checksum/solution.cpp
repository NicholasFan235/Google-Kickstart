#include <bits/stdc++.h>

int N;
std::vector<std::vector<int>> A, B;
std::vector<int> R, C;

std::vector<std::vector<int>> edges;
long total;

void solve()
{
    edges = std::vector<std::vector<int>>(2*N, std::vector<int>(2*N));
    total = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            edges[i][N+j] = B[i][j];
            edges[N+j][i] = B[i][j];
            total += B[i][j];
        }
    }

    auto visited = std::vector<bool>(2*N, false);
    auto checkQueue = std::priority_queue<std::pair<int, int>>();
    for (int i = 0; i < 2*N; i++) checkQueue.push(std::make_pair(0, i));

    long count = 0;
    while (!checkQueue.empty())
    {
        auto curr = checkQueue.top();
        checkQueue.pop();

        int i = curr.second;
        int w = curr.first;
        if (visited[i]) continue;
        visited[i] = true;
        count += w;
        for (int j = 0; j < 2*N; j++)
        {
            if (!visited[j]) checkQueue.push(std::make_pair(edges[i][j], j));
        }
    }

    std::cout << total-count;
}


int main()
{
    int T;
    std::cin >> T;
    for (int t = 1; t <= T; t++)
    {
        std::cin >> N;
        A = std::vector<std::vector<int>>(N, std::vector<int>(N));
        B = std::vector<std::vector<int>>(N, std::vector<int>(N));
        R = std::vector<int>(N);
        C = std::vector<int>(N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                std::cin >> A[i][j];
        for (int i = 0; i < N; i++)
             for (int j = 0; j < N; j++)
                std::cin >> B[i][j];
        for (int i = 0; i < N; i++)
            std::cin >> R[i];
        for (int i = 0; i < N; i++)
            std::cin >> C[i];

        std::cout << "Case #" << t << ": ";
        solve();
        std::cout << std::endl;
    }
}

