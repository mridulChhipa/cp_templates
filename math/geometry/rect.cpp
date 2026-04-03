#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

struct Rect
{
    ll x1, y1, x2, y2;
    ll area() { return (y2 - y1) * (x2 - x1); }
};

ll intersect(Rect p, Rect q)
{
    ll xOverlap = max(0LL, min(p.x2, q.x2) - max(p.x1, q.x1));
    ll yOverlap = max(0LL, min(p.y2, q.y2) - max(p.y1, q.y1));
    return xOverlap * yOverlap;
}

ll unionArea(Rect p, Rect q)
{
    return p.area() + q.area() - intersect(p, q);
}