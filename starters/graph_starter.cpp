#include <bits/stdc++.h>;
using namespace std;

class Solution
{
public:
    bool dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[node] = true;
        for (int neighbor : adj[node])
        {
            if (!vis[neighbor])
            {
                if (dfs(neighbor, node, vis, adj))
                    return true;
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && dfs(i, -1, vis, adj))
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    void dfs(
        int i, int j, vector<vector<char>> &grid,
        int &n, int &m, vector<vector<bool>> &vis)
    {
        if (vis[i][j])
            return;
        if (grid[i][j] != 'L')
            return;

        vis[i][j] = true;

        if (i > 0 && j > 0)
            dfs(i - 1, j - 1, grid, n, m, vis);
        if (i < n - 1 && j < m - 1)
            dfs(i + 1, j + 1, grid, n, m, vis);
        if (j < m - 1)
            dfs(i, j + 1, grid, n, m, vis);
        if (j > 0)
            dfs(i, j - 1, grid, n, m, vis);
        if (i > 0)
            dfs(i - 1, j, grid, n, m, vis);
        if (i > 0 && j < m - 1)
            dfs(i - 1, j + 1, grid, n, m, vis);
        if (i < n - 1 && j > 0)
            dfs(i + 1, j - 1, grid, n, m, vis);
        if (i < n - 1)
            dfs(i + 1, j, grid, n, m, vis);
    }

    int countIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 'L')
                {
                    dfs(i, j, grid, n, m, vis);
                    res++;
                }
            }
        }

        return res;
    }
};

int main()
{
    return 0;
}
