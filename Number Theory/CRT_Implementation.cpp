// https://open.kattis.com/problems/generalchineseremainder

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 5e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e13;

struct GCD_type
{
    ll x, y, d;
};

GCD_type ex_GCD(ll a, ll b)
{
    if (b == 0)
        return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}

inline ll normalize(ll x, ll mod)
{
    x %= mod;
    if (x < 0)
        x += mod;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    ll ans = 0;
    ll lcm = 0;
    bool possible = true;

    int total_equations = _;
    for (int i = 0; i < total_equations; ++i)
    {
        ll ai, ni;
        cin >> ai >> ni;
        ai = normalize(ai, ni);

        if (i == 0)
        {
            ans = ai;
            lcm = ni;
            continue;
        }

        if (!possible)
            continue;

        auto pom = ex_GCD(lcm, ni);
        ll x1 = pom.x;
        ll d = pom.d;

        if ((ai - ans) % d != 0)
        {
            possible = false;
        }
        else
        {
            ll next_lcm = lcm * (ni / d);
            ans = normalize(ans + x1 * ((ai - ans) / d % (ni / d)) * lcm, next_lcm);
            lcm = next_lcm;
        }
    }

    if (!possible)
    {
        cout << "No solutions" << endl;
    }
    else
    {
        cout << ans << " " << lcm << endl;
    }

    return 0;
}