#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 500;
const ll INF = 1e13;
const ll MOD = 1e9 + 7;

vector<array<ll, 3>> edges;
ll n, m;
ll parent[MAX];

ll find(ll u)
{
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

void unionSets(ll u, ll v)
{
    ll rootU = find(u);
    ll rootV = find(v);
    if (rootU != rootV)
        parent[rootV] = rootU;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());
    ll mstWeight = 0;
    vector<array<ll, 3>> mstEdges;

    for (auto &[w, u, v] : edges)
    {
        if (find(u) != find(v))
        {
            unionSets(u, v);
            mstWeight += w;
            mstEdges.push_back({u, v, w});
        }
    }

    cout << "Weight of MST: " << mstWeight << "\n";
    cout << "Edges in the MST:\n";
    for (auto &[u, v, w] : mstEdges)
    {
        cout << u << " - " << v << " : " << w << "\n";
    }

    return 0;
}
