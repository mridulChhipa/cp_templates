#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 200000 + 7;
const ll MOD = 1000000007;
const ll INF = (ll)9e18;

vector<ll> dt(const vector<ll> &f)
{
    int n = f.size();
    vector<int> v(n);
    vector<long double> z(n + 1);
    vector<ll> g(n);
    int k = 0;
    v[0] = 0;
    z[0] = -1e100L;
    z[1] = 1e100L;
    for (int q = 1; q < n; q++)
    {
        long double s;
        while (true)
        {
            ll fq = f[q] + 1LL * q * q;
            ll fv = f[v[k]] + 1LL * v[k] * v[k];
            long double num = (long double)(fq - fv);
            long double den = 2.0L * (q - v[k]);
            s = num / den;
            if (s <= z[k])
                k--;
            else
                break;
        }
        k++;
        v[k] = q;
        z[k] = s;
        z[k + 1] = 1e100L;
    }
    int ptr = 0;
    for (int q = 0; q < n; q++)
    {
        while (z[ptr + 1] < q)
            ptr++;
        int id = v[ptr];
        ll d = q - id;
        g[q] = f[id] + d * d;
    }
    return g;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> sets(m);
    vector<int> belong(n + 1);

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        sets[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            sets[i][j] = x;
            belong[x] = i;
        }
    }

    int A = belong[1];

    vector<ll> src(n, INF);
    for (int x : sets[A])
        src[x - 1] = 0;
    vector<ll> distA = dt(src);

    vector<ll> mA(m, INF);
    for (int i = 1; i <= n; i++)
    {
        int id = belong[i];
        mA[id] = min(mA[id], distA[i - 1]);
    }

    vector<ll> f(n);
    for (int i = 1; i <= n; i++)
        f[i - 1] = mA[belong[i]];
    vector<ll> H = dt(f);

    vector<ll> ans_set(m, INF);
    for (int i = 0; i < m; i++)
        ans_set[i] = mA[i];
    for (int i = 0; i < m; i++)
    {
        for (int x : sets[i])
            ans_set[i] = min(ans_set[i], H[x - 1]);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans_set[belong[i]] << (i == n ? '\n' : ' ');
    }

    return 0;
}
