#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

constexpr int K_MAX = 101;

ll a[MAX];
ll dp[MAX][K_MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    /*
    Initialising Base Case correctly was important in this questions
    I initially inititalised dp[0][i] and not dp[1][i] and also
    started the loop from 1
    */
   
    if (a[1] == 0)
    {
        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = 1;
        }
    }
    else
    {
        dp[1][a[1]] = 1;
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i - 1][j - 1];
                if (j < m)
                    dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
        else
        {
            dp[i][a[i]] = dp[i - 1][a[i]];
            if (a[i] > 0)
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
            if (a[i] < m)
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
            dp[i][a[i]] %= MOD;
        }
    }

    ll res = 0;
    for (int i = 1; i <= m; i++)
    {
        res = (res + dp[n][i]) % MOD;
    }

    cout << res << '\n';

    return 0;
}