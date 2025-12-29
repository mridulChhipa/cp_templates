#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e6 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll phi[MAX];
ll res[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < MAX; i++)
        phi[i] = i;
    for (int i = 2; i < MAX; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j < MAX; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i; j < MAX; j += i)
            res[j] += phi[i] * i;
    }

    int _;
    cin >> _;
    while (_--)
    {
        int n;
        cin >> n;

        cout << (res[n] + 1) * n / 2 << "\n";
    }

    return 0;
}
