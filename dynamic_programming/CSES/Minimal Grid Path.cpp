#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ull = uint64_t;

// constexpr ll MAX = 2e5 + 7;
constexpr ll MAX = 3e3 + 7;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e15;

int n;
string s[MAX];
bool vis[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }

    for (int i = 0; i <= n + 1; i++)
    {
        vis[i][n + 1] = true;
        vis[n + 1][i] = true;
    }

    string res;

    queue<pair<int, int>> q;
    q.emplace(1, 1);
    vis[1][1] = true;
    while (!q.empty())
    {
        queue<pair<int, int>> curr;
        char min_char = 'z' + 1;

        int k = q.size();
        {
            auto &[i, j] = q.front();
            res.push_back(s[i][j]);
        }

        while (k--)
        {
            auto &[i, j] = q.front();
            q.pop();

            int i1 = i + 1, j1 = j;
            int i2 = i, j2 = j + 1;
            if (!vis[i1][j1] && !vis[i2][j2])
            {
                if (s[i1][j1] < s[i2][j2])
                {
                    if (s[i1][j1] < min_char)
                    {
                        while (!curr.empty())
                            curr.pop();
                        min_char = min(min_char, s[i1][j1]);

                        if (!vis[i1][j1])
                        {
                            curr.emplace(i1, j1);
                        }
                    }
                    else if (s[i1][j1] == min_char)
                    {
                        if (!vis[i1][j1])
                        {
                            curr.emplace(i1, j1);
                        }
                    }
                }
                else if (s[i1][j1] == s[i2][j2])
                {
                    if (s[i1][j1] < min_char)
                    {
                        while (!curr.empty())
                            curr.pop();
                        min_char = min(min_char, s[i1][j1]);
                        if (!vis[i1][j1])
                        {
                            curr.emplace(i1, j1);
                        }
                        if (!vis[i2][j2])
                        {
                            curr.emplace(i2, j2);
                        }
                    }
                    else if (s[i1][j1] == min_char)
                    {
                        if (!vis[i1][j1])
                        {
                            curr.emplace(i1, j1);
                        }
                        if (!vis[i2][j2])
                        {
                            curr.emplace(i2, j2);
                        }
                    }
                }
                else
                {
                    if (s[i2][j2] < min_char)
                    {
                        while (!curr.empty())
                            curr.pop();
                        min_char = min(min_char, s[i2][j2]);

                        if (!vis[i2][j2])
                        {
                            curr.emplace(i2, j2);
                        }
                    }
                    else if (s[i2][j2] == min_char)
                    {
                        if (!vis[i2][j2])
                        {
                            curr.emplace(i2, j2);
                        }
                    }
                }
            }
            else if (!vis[i1][j1] && vis[i2][j2])
            {
                if (s[i1][j1] < min_char)
                {
                    while (!curr.empty())
                        curr.pop();
                    min_char = min(min_char, s[i1][j1]);

                    if (!vis[i1][j1])
                    {
                        curr.emplace(i1, j1);
                    }
                }
                else if (s[i1][j1] == min_char)
                {
                    if (!vis[i1][j1])
                    {
                        curr.emplace(i1, j1);
                    }
                }
            }
            else if (vis[i1][j1] && !vis[i2][j2])
            {
                if (s[i2][j2] < min_char)
                {
                    while (!curr.empty())
                        curr.pop();
                    min_char = min(min_char, s[i2][j2]);

                    if (!vis[i2][j2])
                    {
                        curr.emplace(i2, j2);
                    }
                }
                else if (s[i1][j1] == min_char)
                {
                    if (!vis[i2][j2])
                    {
                        curr.emplace(i2, j2);
                    }
                }
            }
        }

        while (!curr.empty())
        {
            auto &[i, j] = curr.front();
            if (!vis[i][j])
            {
                vis[i][j] = true;
                q.push(curr.front());
            }

            curr.pop();
        }
    }

    cout << res << '\n';

    return 0;
}
