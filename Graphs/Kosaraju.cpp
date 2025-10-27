#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

vector<ll> adj[MAX], revAdj[MAX], order, component;
vector<bool> visited;
void dfs1(ll u)
{
    visited[u] = true;
    for (ll v : adj[u])
        if (!visited[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(ll u)
{
    visited[u] = true;
    component.push_back(u);
    for (ll v : revAdj[u])
        if (!visited[v])
            dfs2(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    visited.assign(n + 1, false);
    for (ll i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);
    visited.assign(n + 1, false);
    reverse(order.begin(), order.end());
    for (ll u : order)
    {
        if (!visited[u])
        {
            component.clear();
            dfs2(u);
            // component now contains all nodes in one strongly connected component
            for (ll node : component)
                cout << node << " ";
            cout << "\n";
        }
    }
    return 0;
}
