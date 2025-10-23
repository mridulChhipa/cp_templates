#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e18 + 7;

int number_of_wins(vector<int> &bessieCards, vector<int> &elsieCards,
                   function<bool(int, int)> compareFn)
{
    int n = bessieCards.size();
    assert((int)elsieCards.size() == n);

    sort(bessieCards.begin(), bessieCards.end(), compareFn);
    sort(elsieCards.begin(), elsieCards.end(), compareFn);

    int bessiePos = 0;
    int winCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (compareFn(bessieCards[bessiePos], elsieCards[i]))
        {
            winCount++;
            bessiePos++;
        }
    }

    return winCount;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    int n;
    cin >> n;

    vector<bool> elsieHas(2 * n + 1, false);
    vector<int> bessieFirst, bessieSecond;
    vector<int> elsieFirst(n / 2), elsieSecond(n / 2);

    for (int i = 0; i < n; i++)
    {
        int card;
        cin >> card;
        elsieHas[card] = true;
        if (i < n / 2)
        {
            elsieFirst[i] = card;
        }
        else
        {
            elsieSecond[i - n / 2] = card;
        }
    }

    for (int card = 2 * n; card >= 1; card--)
    {
        if (!elsieHas[card])
        {
            if ((int)bessieFirst.size() < n / 2)
            {
                bessieFirst.push_back(card);
            }
            else
            {
                bessieSecond.push_back(card);
            }
        }
    }

    int totalWins = 0;
    totalWins += number_of_wins(
        bessieFirst, elsieFirst,
        [](int a, int b)
        { return a > b; });
    totalWins += number_of_wins(
        bessieSecond, elsieSecond,
        [](int a, int b)
        { return a < b; });

    cout << totalWins << "\n";
    return 0;
}
