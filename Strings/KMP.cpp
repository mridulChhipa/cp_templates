#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

const ll MAX = 2e5 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e13;

vector<int> lps(const string &s)
{
    int n = s.size();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j])
            j = lps[j - 1];

        if (s[i] == s[j])
            j++;

        lps[i] = j;
    }

    return lps;
}

int kmp(const string &s, const string &t)
{
    int n = s.size();
    int m = t.size();
    vector<int> LPS = lps(t);
    int count = 0;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && t[j] != s[i])
            j = LPS[j - 1];

        if (t[j] == s[i])
            j++;

        if (j == m)
        {
            count++;
            j = LPS[j - 1];
        }
    }

    return count;
}