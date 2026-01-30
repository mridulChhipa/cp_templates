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
    vector<int> tree;

public:
    SegmentTree(int n) : len(4 * n)
    {
        tree.resize(len, 0);
    }

    void build(const vector<int> &arr, int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = arr[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(arr, 2 * i + 1, l, mid);
            build(arr, 2 * i + 2, mid + 1, r);
            tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    int query(int x, int i, int l, int r)
    {
        if (tree[i] < x)
        {
            return -1;
        }

        if (l == r)
        {
            tree[i] -= x;
            update(i);
            return l;
        }

        int mid = (l + r) / 2;
        if (tree[2 * i + 1] >= x)
        {
            return query(x, 2 * i + 1, l, mid);
        }
        else
        {
            return query(x, 2 * i + 2, mid + 1, r);
        }
    }

    void update(int i)
    {
        while (i > 0)
        {
            i = (i - 1) / 2;
            tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> h(n), r(m);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> r[i];

    SegmentTree segtree(n);
    segtree.build(h, 0, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int res = segtree.query(r[i], 0, 0, n - 1);
        cout << res + 1 << " ";
    }

    cout << "\n";
    return 0;
}