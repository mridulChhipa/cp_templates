#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int n, k, res;
vector<int> adj[MAX];
bool vis[MAX];
bool status[MAX];
bool is_in_cycle[MAX];
vector<int> path;

bool dfs(int v)
{
    vis[v] = true;
    status[v] = true;
    path.push_back(v);

    bool found = false;
    for (int u : adj[v])
    {
        if (status[u])
        {
            found = true;
            for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i)
            {
                is_in_cycle[path[i]] = true;
                if (path[i] == u)
                    break;
            }
        }
        else if (!vis[u])
        {
            dfs(u);
        }
    }

    status[v] = false;
    path.pop_back();
    return found;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa < sb)
        {
            adj[a].push_back(b);
        }
        else
        {
            adj[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        res += is_in_cycle[i];
    }

    cout << res << "\n";

    return 0;
}
