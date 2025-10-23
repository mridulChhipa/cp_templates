#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll custom_floor_log(ll a, ll b)
{
    ll out = 0;
    while (a > 1)
    {
        a /= b;
        out++;
    }

    return out;
}

int custom_ciel_log(int a, int b)
{
    int out = 0, curr = 1;
    while (curr < a)
    {
        curr *= b;
        out++;
    }
    return out;
}

vector<int> unique_vector(vector<int> v)
{
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    return v;
}

int mod_pow(int a, int b)
{
    
    if (b <= 0)
        return 1;
        
    int ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int mod_inv(int x)
{
    return mod_pow(x, MOD - 2);
}


int floor_sqrt(int &n)
{
    int x = sqrt(n) + 4;
    while (x * x > n)
        x--;
    return x;
}

string bin(int a)
{
    return bitset<64>(a).to_string().substr(64 - __lg(a) - 1);
}

double C(int n, int k)
{
    if (k > n || k < 0)
        return 0.0;

    double res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;

    for (int i = 1; i <= k; i++)
        res /= i;

    for (int i = 1; i <= n - k; i++)
        res /= i;

    return res;
}
