#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

// constexpr ll MAX = 5e2 + 7;
constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> tails;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it != tails.end())
            *it = x;
        else
            tails.push_back(x);
    }

    cout << tails.size() << '\n';

    return 0;
}
