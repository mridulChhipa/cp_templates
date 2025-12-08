#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 300000 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int n, m, t = 1;

vector<int> adj[MAX];
vector<int> adj1[MAX];
int vis_t[MAX];
bool vis[MAX];

vector<int> topo;

vector<pair<int, int>> res;

void dfs(int v, int par)
{
    vis_t[v] = t++;

    for (int u : adj[v])
    {
        if (!vis_t[u])
        {
            dfs(u, v);

            res.emplace_back(v, u);
        }
        else if (vis_t[v] > vis_t[u] && u != par)
        {
            res.emplace_back(v, u);
        }
    }
}

void dfs_topo(int v)
{
    vis[v] = true;
    for (int u : adj1[v])
        if (!vis[u])
            dfs_topo(u);
    topo.emplace_back(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1, 0);

    for (auto &[u, v] : res)
        adj1[v].emplace_back(u);

    dfs_topo(1);

    if (static_cast<int>(topo.size()) < n)
    {
        cout << 0 << "\n";
        return 0;
    }

    for (auto &[u, v] : res)
    {
        cout << u << " " << v << "\n";
    }

    return 0;
}
