#include <bits/stdc++.h>

// WA 
// �etta fail-ar � test case-inu a� ne�an
// 10 6
// 3 3 4 2 6 2 5 1 2 3

// �ttaki� � a� vera 6 en mitt �ttak er 7 fyrir inntaki� a� ofan

using namespace std;
typedef long long ll;

int main()
{
    int n, k, i, j;
    vector<ll> w;
    ll w_item;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w_item;
        w.push_back(w_item);
    }

    vector<ll> wOfEachBox(k);
    vector<list<ll>> wOfAll;
    vector<int> splits(n); // allt upphafsstillt sem 0

    double temp = 0.0;
    for (i = 0; i < k - 1; i++)
    {
        temp += ceil((n - temp) / (k - i)); //  ceil e�a round? (floor er ekki � lagi)
        splits[temp] = 1; // b�r til "t�kn" um split � milli temp-1 og temp
    }

    // vector<int> arr;
    // double temp2;
    // while (arr.size() < n)
    // {
    //     temp2 = floor(rand() * 2) + 1;
    //     if (arr[temp2] == 0)
    //     {
    //         arr.push_back(temp2);
    //     }
    // }
    

    i = 0, j = 0;
    list<ll> wOfBox;
    while (i < k)
    {
        wOfBox.clear();
        if (splits[j] == 1)
        {
            wOfBox.push_back(w[j]);
            wOfEachBox[i] += w[j];
            j++;
        }
        while (splits[j] == 0 && j < n)
        {
            wOfBox.push_back(w[j]);
            wOfEachBox[i] += w[j];
            j++;
        }
        wOfAll.push_back(wOfBox);
        i++;
    }
    // wOfBox.clear(); ef memory limit exceeded �� pr�fa a� taka kommenti� af, og � n�stu l�nu
    // w.clear();

    ll mx = *max_element(wOfEachBox.begin(), wOfEachBox.end());

    if (n == k)
    {
        cout << mx << endl;
        return 0;
    }

    ll t;
    list<ll> tlist;
    bool myBool = false;
    while (true)
    {
        i = 0;
        while (i < k - 1)
        {
            myBool = false;

            tlist = wOfAll[i];
            t = tlist.back();
            if (wOfEachBox[i] > wOfEachBox[i + 1] && wOfEachBox[i] > 0 && wOfEachBox[i + 1] > 0 && wOfEachBox[i + 1] + t <= mx)
            {
                wOfEachBox[i + 1] += t;
                wOfEachBox[i] -= t;
                wOfAll[i + 1].push_front(t);
                wOfAll[i].pop_back();
                myBool = true;
            }
            else
            {
                tlist = wOfAll[i + 1];
                t = tlist.front();
                if (wOfEachBox[i] < wOfEachBox[i + 1] && wOfEachBox[i] > 0 && wOfEachBox[i + 1] > 0 && wOfEachBox[i] + t < mx)
                {
                    wOfEachBox[i] += t;
                    wOfEachBox[i + 1] -= t;
                    wOfAll[i].push_back(t);
                    wOfAll[i + 1].pop_front();
                    myBool = true;
                }
            }
            if (myBool) // ef breyting var�, �� f�um vi� n�jan "�yngsta kassa" og byrjum aftur me� i = 0
            {
                mx = *max_element(wOfEachBox.begin(), wOfEachBox.end());
                break;
            }
            i++;
        }
        if (!myBool) // ef engin breyting var� me� �v� a� �tra yfir allt, �� h�tta
        {
            break;
        }
        // mx = *max_element(wOfEachBox.begin(), wOfEachBox.end());
    }

    cout << mx << endl;
    return 0;
}