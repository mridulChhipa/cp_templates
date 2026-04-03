#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    int res = 0;
    do
    {
        int cnt = 0;
        stack<int> s1;
        stack<int> s2;

        int i = 0;
        while (i < a.size())
        {
            cnt++;
            if (!s1.empty() && s1.top() < a[i])
            {
                if (!s2.empty() && s2.top() < a[i])
                {
                    s1.push(s2.top());
                    s2.pop();
                }
                else
                {
                    s1.push(a[i]);
                    i++;
                }
            }
            else
            {
                if (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
                else
                {
                    s1.push(a[i]);
                    i++;
                }
            }
        }

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }

        while (!s1.empty())
        {
            // cout << s1.top() << " ";
            s1.pop();
        }

        // cout << "\n";
        res = max(res, cnt);
    } while (next_permutation(a.begin(), a.end()));

    cout << res << "\n";
    return 0;
}
