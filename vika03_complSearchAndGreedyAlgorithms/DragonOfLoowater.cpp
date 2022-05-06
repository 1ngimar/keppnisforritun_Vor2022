#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <queue>

// AC

using namespace std;
typedef long long ll;

int printOutput(list<string> o)
{
    while (!o.empty())
    {
        cout << o.front() << endl;
        o.pop_front();
    }
    return 0;
}

int main()
{
    list<string> output;
    string impossible = "Loowater is doomed!";
    list<list<ll>> allHeads, allKnights;
    list<ll> d_heads, h_knights;
    queue<int> n_queue, m_queue;
    while (true)
    {
        ll item;
        int n, m;
        cin >> n >> m;
        n_queue.push(n);
        m_queue.push(m);
        if (n == 0 && m == 0)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> item;
            d_heads.push_back(item);
        }
        allHeads.push_back(d_heads);
        d_heads.clear();

        for (int i = 0; i < m; i++)
        {
            cin >> item;
            h_knights.push_back(item);
        }
        allKnights.push_back(h_knights);
        h_knights.clear();
    }

    while (!n_queue.empty())
    {
        int n = n_queue.front();
        int m = m_queue.front();
        n_queue.pop();
        m_queue.pop();

        if (n == 0 && m == 0) // end of input
        {
            return printOutput(output);
        }
        else if (n == 0) // no heads initially ... then why did I write this code anyway?
        {
            output.push_back("0");
        }
        else if (m < n) // not enaugh number of knights ... We are doomed!
        {
            output.push_back(impossible);
        }
        else
        {
            d_heads = allHeads.front();
            allHeads.pop_front();
            h_knights = allKnights.front();
            allKnights.pop_front();
            // work our way from smallest- to largest head
            d_heads.sort();
            h_knights.sort();

            ll sumGoldCoins = 0; // long long because worst case can be 10.000 * 20.000 = 200.000.000 gold coins
            while (!d_heads.empty())
            {
                if (h_knights.size() < d_heads.size()) // if we have run out of knights
                {
                    break;
                }
                if (d_heads.front() <= h_knights.front()) // if knight can slay a dragon
                {
                    d_heads.pop_front();
                    sumGoldCoins += h_knights.front();
                    h_knights.pop_front();
                }
                else // if the knight can't slay the dragon; then we don't hire him
                {
                    h_knights.pop_front();
                }
            }

            string longToString;
            if (d_heads.empty())
            {
                longToString = to_string(sumGoldCoins);
                output.push_back(longToString);
            }
            else
            {
                output.push_back(impossible);
            }
        }
    }
    return 0;
}