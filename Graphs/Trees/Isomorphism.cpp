// Reference: https://codeforces.com/blog/entry/101010
// https://cses.fi/problemset/task/1701/
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 5e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e13;

ll powr[MAX];

struct Tree
{
    int n;
    vector<vector<int>> adj;
    vector<int> sub;
    vector<ll> hash_id;
    vector<int> centroids;

    Tree(int n) : n(n), adj(n), sub(n), hash_id(n) {}

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Combined DFS to find sub-tree sizes and identify centroids
    void find_centroids(int u, int p)
    {
        sub[u] = 1;
        bool is_centroid = true;
        for (int v : adj[u])
        {
            if (v != p)
            {
                find_centroids(v, u);
                sub[u] += sub[v];
                if (sub[v] > n / 2)
                    is_centroid = false;
            }
        }

        if (n - sub[u] > n / 2)
            is_centroid = false;
        if (is_centroid)
            centroids.push_back(u);
    }

    // AHU-like hashing to compute a unique ID for a rooted tree
    ll compute_hash(int u, int p)
    {
        sub[u] = 1;
        vector<ll> child_hashes;
        for (int v : adj[u])
        {
            if (v != p)
            {
                child_hashes.push_back(compute_hash(v, u));
                sub[u] += sub[v];
            }
        }

        sort(child_hashes.begin(), child_hashes.end());

        ll h = 1;
        for (ll ch : child_hashes)
        {
            // We use a simplified version of AHU string hashing
            h = (h * powr[sub[u]] % MOD + ch) % MOD;
        }
        h = (h * 2) % MOD;
        return hash_id[u] = h;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    powr[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        powr[i] = (2 * powr[i - 1]) % MOD;
    }

    int _;
    cin >> _;
    while (_--)
    {
        int N;
        cin >> N;

        Tree t1(N), t2(N);
        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            t1.add_edge(u - 1, v - 1);
        }
        for (int i = 0; i < N - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            t2.add_edge(u - 1, v - 1);
        }

        t1.find_centroids(0, -1);
        t2.find_centroids(0, -1);

        bool isomorphic = false;
        // Two trees are isomorphic if any centroid-rooted hash of T1
        // matches any centroid-rooted hash of T2
        for (int c1 : t1.centroids)
        {
            ll h1 = t1.compute_hash(c1, -1);
            for (int c2 : t2.centroids)
            {
                ll h2 = t2.compute_hash(c2, -1);
                if (h1 == h2)
                {
                    isomorphic = true;
                    break;
                }
            }
            if (isomorphic)
                break;
        }

        cout << (isomorphic ? "YES" : "NO") << "\n";
    }

    return 0;
}