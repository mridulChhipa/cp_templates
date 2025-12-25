// https://codeforces.com/contest/1851/problem/F
// F. Lisa and the Martians
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int n, k;
int a[MAX];

struct node
{
    node *child[2];
    int index;
    node()
    {
        child[0] = child[1] = nullptr;
        index = -1;
    }
};

void insert_trie(node *root, int val, int idx, int k)
{
    node *cur = root;
    for (int i = k - 1; i >= 0; --i)
    {
        int bit = (val >> i) & 1;
        if (!cur->child[bit])
            cur->child[bit] = new node();
        cur = cur->child[bit];
        cur->index = idx;
    }
}

int query_trie(node *root, int val, int k)
{
    node *cur = root;

    for (int i = k - 1; i >= 0; --i)
    {
        int bit = (val >> i) & 1;
        if (cur->child[bit])
            cur = cur->child[bit];
        else
            cur = cur->child[1 - bit];
    }

    return cur->index;
}

void delete_trie(node *root)
{
    if (!root)
        return;

    delete_trie(root->child[0]);
    delete_trie(root->child[1]);
    delete root;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _;
    cin >> _;
    while (_--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        if (n == 1)
        {
            cout << 1 << " " << 1 << " " << 0 << '\n';
            continue;
        }

        node *root = new node();
        insert_trie(root, a[0], 1, k);

        int res_val = -1;
        int res_i = 1;
        int res_j = 1;
        int res_x = 0;
        int mask = ((1 << k) - 1);

        for (int i = 1; i < n; ++i)
        {
            int match_idx = query_trie(root, a[i], k);

            int aj = a[match_idx - 1];
            int curr_x = (~a[i]) & mask;
            int curr_val = ((a[i] ^ curr_x) & (aj ^ curr_x));
            if (curr_val > res_val)
            {
                res_val = curr_val;
                res_i = i + 1;
                res_j = match_idx;
                res_x = curr_x;
            }

            insert_trie(root, a[i], i + 1, k);
        }

        cout << res_i << " " << res_j << " " << res_x << '\n';
        delete_trie(root);
    }

    return 0;
}
