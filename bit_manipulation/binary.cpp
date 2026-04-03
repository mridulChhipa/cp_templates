#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

string bin(ll a)
{
    return bitset<64>(a).to_string().substr(64 - __lg(a) - 1);
}