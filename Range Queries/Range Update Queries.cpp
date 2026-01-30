#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

constexpr ll MAX = 2e5 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

class SegmentTree
{
    int len;
    vector<ll> tree;
    vector<ll> lazy;

public:
    SegmentTree(int n) : len(4 * n)
    {
        tree.resize(len, 0);
        lazy.resize(len, 0);
    }

    void build(const vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2 * i + 1, l, mid);
        build(arr, 2 * i + 2, mid + 1, r);
    }

    void update(int i, const int &a, const int &b, const ll &u, int l, int r)
    {
        if (a > r || b < l)
        {
            return;
        }

        if (a <= l && b >= r)
        {
            lazy[i] += u;
            return;
        }

        int mid = (l + r) / 2;
        update(2 * i + 1, a, b, u, l, mid);
        update(2 * i + 2, a, b, u, mid + 1, r);
    }

    ll query(int k, int i, int l, int r)
    {
        if (l == r)
        {
            return lazy[i] + tree[i];
        }

        int mid = (l + r) / 2;
        if (k <= mid)
        {
            return lazy[i] + query(k, 2 * i + 1, l, mid);
        }
        else
        {
            return lazy[i] + query(k, 2 * i + 2, mid + 1, r);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    SegmentTree segtree(n);
    segtree.build(x, 0, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        ll j, a, b, u, k;
        cin >> j;
        if (j == 1)
        {
            cin >> a >> b >> u;
            a--;
            b--;

            segtree.update(0, a, b, u, 0, n - 1);
        }
        else
        {
            cin >> k;
            k--;
            ll res = segtree.query(k, 0, 0, n - 1);
            cout << res << '\n';
        }
    }

    return 0;
}