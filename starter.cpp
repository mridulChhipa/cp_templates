#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll _, n, m, l, r, t, A, B, res;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> _;
    while (_--)
    {
        cin >> n;

        ll a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << res << "\n";
    }

    return 0;
}
