// https://kilonova.ro/problems/127
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll mod_pow(ll a, ll b, ll mod = MOD)
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

ll mod_inv(ll x)
{
    return mod_pow(x, MOD - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("sumdiv.in", "r", stdin);
    freopen("sumdiv.out", "w", stdout);

    ll a, b;
    cin >> a >> b;

    vector<ll> primes;
    vector<ll> exps;

    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            ll exp = 0;
            while (a % i == 0)
            {
                a /= i;
                exp++;
            }

            primes.push_back(i);
            exps.push_back(exp);
        }
    }

    if (a > 1)
    {
        primes.push_back(a);
        exps.push_back(1);
    }

    int k = primes.size();
    ll res = 1;

    for (int i = 0; i < k; i++)
    {
        if ((primes[i] - 1) % MOD == 0)
        {
            ll x = ((b % MOD) * (exps[i] % MOD) % MOD + 1) % MOD;
            res = (res * x) % MOD;
        }
        else
        {
            ll exp = (b % (MOD - 1)) * (exps[i] % (MOD - 1)) % (MOD - 1);
            exp = (exp + 1) % (MOD - 1);

            ll num = (mod_pow(primes[i], exp) - 1 + MOD) % MOD;
            ll den_inv = mod_inv((primes[i] - 1) % MOD);
            res = (res * num % MOD * den_inv % MOD) % MOD;
        }
    }

    cout << res << '\n';

    return 0;
}
