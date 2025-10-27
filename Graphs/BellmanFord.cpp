#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = 500;
const ll INF = 1e13;
const ll MOD = 1e9 + 7;

vector<array<ll, 3>> edges;
vector<ll> dist(MAX, INF);
ll n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    dist[1] = 0;
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto &[u, v, w] : edges)
        {
            if (dist[u] < INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycles
    for (auto &[u, v, w] : edges)
    {
        if (dist[u] < INF && dist[v] > dist[u] + w)
        {
            cout << "Graph contains a negative weight cycle\n";
            return 0;
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}