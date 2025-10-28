#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 1e3 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;
    vector<ll> weights(n), values(n);
    for (ll i = 0; i < n; i++)
        cin >> weights[i] >> values[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll w = 0; w <= W; w++)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << dp[n][W] << '\n';

    return 0;
}