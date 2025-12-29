// https://www.codechef.com/problems/KSIZEGCD : Maximum of GCDs

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e6 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int a[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;

        vector<map<int, int>> gcd_len(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            gcd_len[i][a[i]] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (auto &[g, len] : gcd_len[i - 1])
            {
                int g_prime = __gcd(g, a[i]);
                gcd_len[i][g_prime] = max(gcd_len[i][g_prime], len + 1);
            }
        }

        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (auto &[g, len] : gcd_len[i])
            {
                res[len] = max(res[len], g);
            }
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }

    return 0;
}
