#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 5e3 + 7;
// constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int n, m;
int dp[MAX][MAX];
int s[MAX];
int t[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> s[i + 1];

    for (int i = 0; i < m; i++)
        cin >> t[i + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i] == t[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }

    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s[i] == t[j])
        {
            lcs.emplace_back(s[i]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    cout << dp[n][m] << '\n';
    for (int i = 0; i < dp[n][m]; i++)
        cout << lcs[i] << ' ';
    cout << '\n';

    return 0;
}
