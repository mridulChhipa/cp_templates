#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

ll _, n, m, l, r, t, A, B, res;
string s;

int a[10];
void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
            res += (n1 - i);
        }
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}
void count_inversions(int l, int r)
{
    if (l >= r)
        return;

    int m = (l + r) / 2;
    count_inversions(l, m);
    count_inversions(m + 1, r);
    merge(l, m, r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 10; i++)
        a[i] = (i % 2 == 0) ? 10 - i / 2 : i / 2 + 1;

    int inv = 0;
    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 10; j++)
            if (a[i] > a[j])
                inv++;

    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";
    cout << "\n";

    count_inversions(0, 9);
    cout << inv << "\n";
    cout << res << "\n";

    return 0;
}
