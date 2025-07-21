#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> player_cards;

    for (int i = 0; i < n; i++)
    {
        int power;
        cin >> power;
        player_cards.push_back(power);
    }

    sort(player_cards.begin(), player_cards.end());
    int rounds = 0;
    bool lose = false;

    for (int i = 0; i < m; i++)
    {
        int e;
        cin >> e;

        if (lose)
        {
            break;
        }
        else
        {
            rounds++;
        }

        for (int j = 0; j < e; j++)
        {
            int temp;
            cin >> temp;

            auto it = upper_bound(player_cards.begin(), player_cards.end(), temp);
            if (it == player_cards.end())
            {
                lose = true;
            }
            else
            {
                *it = -1;
            }
        }
        player_cards.erase(remove(player_cards.begin(), player_cards.end(), -1), player_cards.end());
    }

    if (!lose)
    {
        rounds++;
    }

    cout << rounds;

    return 0;
}