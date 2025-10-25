#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    static vector<bool> sieve(MAX, true);
    sieve[0] = sieve[1] = false;

    static vector<int> spf(MAX, 0);
    static vector<int> hpf(MAX, 0);
    for (int i = 2; i < MAX; i++)
    {
        if (sieve[i])
        {
            spf[i] = i;
            for (int j = i * 2; j < MAX; j += i)
            {
                sieve[j] = false;
                hpf[j] = i;
                
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }

    vector<vector<int>> prime_factors(MAX);
    for (int i = 2; i < MAX; i++)
    {
        int x = i;
        while (x > 1)
        {
            int p = spf[x];

            prime_factors[i].push_back(p);
            while (x % p == 0)
                x /= p;
        }
    }

    return 0;
}
