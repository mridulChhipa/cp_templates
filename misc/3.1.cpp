#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int n, k;
int a[MAX];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll l = 1000000, r = 1500000;
    ll M = 1000000000000;
    while (l < r)
    {
        ll m = (l + r) / 2;
        if (m * (m + 1) / 2 < M)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    
    l++;
    ll res = l * (l + 1) / 2;
    ll excess = 1326005;
    ll L = 1, R = 532600;
    while (L < R)
    {
        ll m = (L + R) / 2;
        ll x = m * (m + 1) / 2;

        if (x < excess)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }

    cout << l << ' ' << L << '\n';
    cout << res << ' ' << res - M << ' ' << res - L * (L + 1) / 2 << '\n';

    return 0;
}
