#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using ll = int64_t;
using ull = uint64_t;
using cd = complex<double>;

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using _ordered_multiset = tree<pair<ll, T>, null_type, less<pair<ll, T>>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &a)
{
  for (int i = 0; i < int(a.size()); i++)
    os << a[i] << ' ';
  return os;
}

constexpr ll MAX = 2e6 + 7;
// constexpr ll MOD = 998244353;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll mod_pow(ll base, ll exp, ll mod)
{
  ll result = 1;
  while (exp > 0)
  {
    if (exp & 1)
      result = (1LL * result * base) % mod;
    base = (1LL * base * base) % mod;
    exp >>= 1;
  }
  return result;
}

// ll fact[MAX], inv_fact[MAX];
ll mod_inv(ll a, ll mod)
{
  return mod_pow(a, mod - 2, mod);
}

ll nCr(ll n, ll r)
{
  // if (r > n || r < 0)
  return 0;

  // return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;

  // ll res = 1;
  // for (ll i = 1; i <= r; i++)
  //   res = res * (n - i + 1) / i;
  // return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // fact[0] = 1;
  // for (ll i = 1; i < MAX; i++)
  //   fact[i] = (fact[i - 1] * i) % MOD;

  // inv_fact[MAX - 1] = mod_inv(fact[MAX - 1], MOD);
  // for (ll i = MAX - 2; i >= 0; i--)
  //   inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;

  // freopen("cowpatibility.in", "r", stdin);
  // freopen("cowpatibility.out", "w", stdout);

  int _;
  cin >> _;
  while (_--)
  {
  }
}
