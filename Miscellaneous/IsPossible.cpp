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

    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {2, 3, 5, 4, 1};

    int n = a.size(), j = 0;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            j++;
        }
        else
        {
            while (j < n && !s.empty() && s.top() == b[j])
            {
                j++;
                cout << s.top() << " ";
                s.pop();
            }

            s.push(a[i]);
        }
    }

    while (!s.empty())
    {
        if (s.top() == b[j])
        {
            cout << s.top() << " ";
            s.pop();
            j++;
        }
        else
        {
            cout << "\nNO\n";
            return 0;
        }
    }

    cout << "\nYES\n";

    return 0;
}
