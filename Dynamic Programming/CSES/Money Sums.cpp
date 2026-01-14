#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int n;
int x[101];
int dp[MAX][101];
int visa[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x, x + n);

    dp[0][0] = 1;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < MAX; i++)
        {
            dp[i][j + 1] = dp[i][j];

            if (i >= x[j] && dp[i - x[j]][j])
            {
                dp[i][j + 1] = true;
            }
        }
    }

    vector<int> res;
    for (int i = 1; i < MAX; i++)
    {
        if (dp[i][n])
        {
            res.push_back(i);
        }
    }

    cout << res.size() << '\n';
    for (int x : res)
        cout << x << ' ';
    cout << '\n';

    return 0;
}