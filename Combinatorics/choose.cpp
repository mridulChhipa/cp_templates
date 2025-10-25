#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll C(ll n, ll k)
{
    if (k > n || k < 0)
        return 0;

    if (k > n - k)
        k = n - k;
    ll res = 1;
    for (ll i = 1; i <= k; i++)
    {
        res = res * (n - i + 1) / i;
    }
    return res;
}
