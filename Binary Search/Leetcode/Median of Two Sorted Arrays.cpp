#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b)
    {
        int n = a.size(), m = b.size();
        if (n > m)
            return findMedianSortedArrays(b, a);

        int k = (n + m + 1) / 2;
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = (l + r) / 2;

            int L = mid;
            int R = k - L;

            int l1 = (L == 0 ? -1e9 : a[L - 1]);
            int l2 = (R == 0 ? -1e9 : b[R - 1]);
            int r1 = (L == n ? 1e9 : a[L]);
            int r2 = (R == m ? 1e9 : b[R]);

            if (l1 <= r2 && l2 <= r1)
            {
                if ((n + m) & 1)
                    return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            if (l1 > r2)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
