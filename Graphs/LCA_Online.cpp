#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 300000 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;
const int LOG = 20;

int n, m, t = 1;
int next_cycle_id;

vector<int> adj[MAX];
vector<int> adj1[MAX];
int vis_t[MAX];
bool vis[MAX];
int parent[MAX];
int cycle_id[MAX];

vector<pair<int, int>> res;
int cnt[MAX];

int up[LOG + 1][MAX];
int depthArr[MAX];

int mod_pow(ll a, ll b)
{
    if (b <= 0)
        return 1;
    int ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void dfs(int v, int par)
{
    parent[v] = par;
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
            int curr = v;
            while (curr != 0 && vis_t[curr] >= vis_t[u])
            {
                cycle_id[curr] = next_cycle_id;
                if (curr == u)
                    break;
                curr = parent[curr];
            }
            next_cycle_id++;
        }
    }
}

void dfs_cnt(int v, int par)
{
    vis[v] = true;
    cnt[v] = cnt[par] + (v > n);
    for (int u : adj1[v])
        if (!vis[u])
            dfs_cnt(u, v);
}

void dfs_lca(int v, int p)
{
    up[0][v] = p;
    if (p == 0)
        depthArr[v] = 0;
    else
        depthArr[v] = depthArr[p] + 1;
    for (int u : adj1[v])
        if (u != p)
            dfs_lca(u, v);
}

int lca(int a, int b)
{
    if (a == 0 || b == 0)
        return a ^ b;
    if (depthArr[a] < depthArr[b])
        swap(a, b);
    int diff = depthArr[a] - depthArr[b];
    for (int i = 0; i <= LOG; i++)
        if (diff & (1 << i))
            a = up[i][a];
    if (a == b)
        return a;
    for (int i = LOG; i >= 0; i--)
        if (up[i][a] != up[i][b])
        {
            a = up[i][a];
            b = up[i][b];
        }
    return up[0][a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    next_cycle_id = n + 1;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        if (cycle_id[i] == 0)
            cycle_id[i] = i;

    for (int i = 1; i <= n; i++)
        for (int j : adj[i])
            if (cycle_id[i] != cycle_id[j])
                adj1[cycle_id[i]].push_back(cycle_id[j]);

    for (int i = 1; i < next_cycle_id; i++)
    {
        sort(adj1[i].begin(), adj1[i].end());
        adj1[i].erase(unique(adj1[i].begin(), adj1[i].end()), adj1[i].end());
    }

    for (int i = 0; i < next_cycle_id; i++)
        vis[i] = false;

    int root = cycle_id[1];
    cnt[0] = 0;
    dfs_cnt(root, 0);

    for (int i = 0; i < next_cycle_id; i++)
    {
        for (int j = 0; j <= LOG; j++)
            up[j][i] = 0;
        depthArr[i] = 0;
    }

    dfs_lca(root, 0);

    for (int k = 1; k <= LOG; k++)
        for (int v = 1; v < next_cycle_id; v++)
            up[k][v] = up[k - 1][up[k - 1][v]];

    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        x = cycle_id[x];
        y = cycle_id[y];
        int v = lca(x, y);
        int alpha = cnt[x] + cnt[y] - 2 * cnt[v] + (v > n);
        cout << mod_pow(2, alpha) << "\n";
    }

    return 0;
}
