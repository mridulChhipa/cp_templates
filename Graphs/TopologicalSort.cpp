#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll n, m;
vector<ll> adj[MAX], indeg, topo;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    indeg.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<ll> q;
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q.push(i);

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        topo.push_back(u);
        for (ll v : adj[u])
        {
            indeg[v]--;
            if (!indeg[v])
                q.push(v);
        }
    }

    for (ll x : topo)
        cout << x << " ";
    return 0;
}
