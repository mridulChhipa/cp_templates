#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

vector<int> adj[MAX];
bool vis[MAX];

void dfs(int vertex, int &l)
{
    vis[vertex] = true;
    for (int child : adj[vertex])
    {
        if (!vis[child])
            dfs(child, ++l);
    }
}
