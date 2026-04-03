#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll mod_pow(ll a, ll b, ll mod)
{
    if (b <= 0)
        return 1;
    ll ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1LL)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ll exp = mod_pow(b, c, MOD - 1);
        cout << mod_pow(a, exp, MOD) << '\n';
    }

    return 0;
}
