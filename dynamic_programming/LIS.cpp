#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> tails, predecessors(n, -1), pos;
    for (ll i = 0; i < n; i++)
    {
        ll num = a[i];
        ll j = lower_bound(tails.begin(), tails.end(), num, [&](ll idx, ll val)
                           { return a[idx] < val; }) -
               tails.begin();
        if (j == (ll)tails.size())
            tails.push_back(i);
        else
            tails[j] = i;
        if (j > 0)
            predecessors[i] = tails[j - 1];
    }

    vector<ll> lis;
    for (ll i = tails.back(); i != -1; i = predecessors[i])
        lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());

    for (ll x : lis)
        cout << x << ' ';
    cout << '\n';
    
    return 0;
}
