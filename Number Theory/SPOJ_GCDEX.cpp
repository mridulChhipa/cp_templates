#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 1e6 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

ll phi[MAX];
ll sums[MAX];
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
        for (int j = 2 * i; j < MAX; j += i)
        {
            sums[j] += i * phi[j / i];
        }
    }

    for (int i = 1; i < MAX; i++)
    {
        res[i] = res[i - 1] + sums[i];
    }

    int n;
    while (cin >> n && n > 0)
    {
        cout << res[n] << "\n";
    }

    return 0;
}