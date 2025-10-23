#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll range_xor(int l, int r)
{
    auto pref_xor = [&](ll n)
    {
        if (n < 0)
            return 0LL;
        if (n % 4 == 0)
            return n;
        else if (n % 4 == 1)
            return 1LL;
        else if (n % 4 == 2)
            return n + 1;
        return 0LL;
    };

    return l > r ? 0 : pref_xor(r) ^ pref_xor(l - 1);
}
