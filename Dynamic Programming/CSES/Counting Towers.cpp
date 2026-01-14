#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e6 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll dp[MAX][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < MAX; i++)
    {
        dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][1] * 2 + dp[i - 1][0]) % MOD;
    }

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }

    return 0;
}