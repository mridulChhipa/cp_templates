#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

template <typename T>
vector<T> sorted(const vector<T> &v)
{
    vector<T> cp = v;
    sort(cp.begin(), cp.end());
    return cp;
}

template <typename T>
vector<T> unique_vector(vector<T> v)
{
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    return v;
}

