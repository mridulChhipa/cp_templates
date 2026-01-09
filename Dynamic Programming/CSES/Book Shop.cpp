#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int h[1000];
int s[1000];

// Don't create n * x size dp because that can go 1e8 space 
// Which will give TLE
int dp[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (j - h[i] >= 0)
                dp[j] = max(dp[j - h[i]] + s[i], dp[j]);
        }
    }

    cout << dp[x] << '\n';

    return 0;
}