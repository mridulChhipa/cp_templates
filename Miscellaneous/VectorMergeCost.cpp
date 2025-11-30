#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int n, m;
vector<int> adj[MAX / 2];
bool vis[MAX / 2];
int cmp;
vector<int> cmps[MAX / 2];
int cmp_1, cmp_n;

void dfs(int v)
{
    vis[v] = true;
    cmps[cmp].push_back(v);

    if (v == 0)
        cmp_1 = cmp;
    if (v == n - 1)
        cmp_n = cmp;

    for (int u : adj[v])
        if (!vis[u])
            dfs(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;

    while (_--)
    {
        cmp = 0;
        cmp_1 = -1;
        cmp_n = -1;

        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            adj[i].clear();
            cmps[i].clear();
            vis[i] = false;
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                cmp++;
            }
        }

        if (cmp_1 == cmp_n)
        {
            cout << 0 << '\n';
            continue;
        }

        for (int i = 0; i < cmp; i++)
            sort(cmps[i].begin(), cmps[i].end());

        vector<int> A = cmps[cmp_1];
        vector<int> B = cmps[cmp_n];

        vector<ll> dA(n), dB(n);

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(A.begin(), A.end(), i);
            ll d = INF;
            if (it != A.end())
                d = min(d, static_cast<ll>(abs(i - *it)));
            if (it != A.begin())
                d = min(d, static_cast<ll>(abs(i - *prev(it))));
            dA[i] = d;
        }

        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(B.begin(), B.end(), i);
            ll d = INF;
            if (it != B.end())
                d = min(d, static_cast<ll>(abs(i - *it)));
            if (it != B.begin())
                d = min(d, static_cast<ll>(abs(i - *prev(it))));
            dB[i] = d;
        }

        ll direct = INF;
        int i = 0, j = 0;
        while (i < static_cast<int>(A.size()) && j < static_cast<int>(B.size()))
        {
            ll diff = A[i] - B[j];
            direct = min(direct, diff * diff);
            if (A[i] < B[j])
                i++;
            else
                j++;
        }

        ll res = direct;

        for (int x = 0; x < cmp; x++)
        {
            if (x == cmp_1 || x == cmp_n)
                continue;

            ll mA = INF, mB = INF;
            for (int y : cmps[x])
            {
                mA = min(mA, dA[y]);
                mB = min(mB, dB[y]);
            }

            res = min(res, mA * mA + mB * mB);
        }

        cout << res << '\n';
    }

    return 0;
}
