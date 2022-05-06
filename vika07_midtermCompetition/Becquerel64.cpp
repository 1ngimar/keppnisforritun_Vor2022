#include <bits/stdc++.h>

// AC kattis time: 0.02 sec

// Súper stoltur af þessari lausn. Kredit fara líka til Vedda fyrir brainstorming
// á hugmyndum.

// PROBLEM DESCRIPTION:
// In the game Becquerel 64 there’s some things to do, all occurring in a nuclear 
// wasteland. Nothing thing seems to work properly, including the Geiger counter players 
// can use to measure radiation levels. It’s hard to know if this is because of intended 
// realism or poor coding. In either case an estimate has to be made regarding the possible 
// radiation levels. Up to 3 digits may have been scrambled in the reading. The counter has 
// a 9 digit display, so a number like 1 would have 8 leading zeroes which may have been 
// scrambled. To determine if this is intended realism or just poor coding we wish to 
// determine the highest power of two dividing any of the possible original values. 
// For example if all possible values are odd, this power would be 0. But if one of them 
// is divisible by 8 but not 16 it would be 3. We note that the original value is always 
// positive and does not contain more than 9 digits.

// INPUT
// The input contains one integer 0?x<109, the number the counter display

// OUTPUT
// Print the highest power of two that could divide the true value, as described above.


using namespace std;

int digits[9] = {0}; 

int increment(int x)
{
    if (x == 9)
    {
        return 0;
    }
    return x + 1;
}

int arrToInt()
{
    int res = 0, p = 0;
    for (int a2 = 8; a2 >= 0; a2--)
    {
        res += digits[a2] * pow(10, p++);
    }
    return res;
}

int countDiv2(int a)
{
    int count = 0;
    while (a % 2 == 0 && a > 0)
    {
        a /= 2;
        count++;
    }
    return count;
}

void change1(int a)
{
    digits[a] = increment(digits[a]);
}

int main()
{
    int x;
    int inputDigits[9] = {0};

    cin >> x;

    int iii = 8;
    while (x > 0)
    {
        digits[iii] = x % 10;
        inputDigits[iii--] = x % 10;
        x /= 10;
    }

    vector<int> results;

    // "Það er C(9, 3) = 84 og ítra má yfir það með þrefaldri for-lykkju
    // Samtals eru þetta 10 * 10 * 84 = 8400 leiðir til að breyta x...
    // ...allt að sexföld forlykkja"
    int tempRes = 0;
    int pi, pj, pk;
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        pi = 0;
        while (pi < 10)
        {
            for (int j = i+1; j < 9; j++)
            {
                pj = 0;
                while (pj < 10)
                {
                    for (int k = j+1; k < 9; k++)
                    {
                        pk = 0;
                        while (pk < 10)
                        {
                            change1(k);
                            tempRes = arrToInt();
                            if (tempRes % 2 == 0)
                                results.push_back(tempRes);
                            pk++;
                        }
                        digits[k] = inputDigits[k];
                    }
                    change1(j);
                    tempRes = arrToInt();
                    if (tempRes % 2 == 0)
                        results.push_back(tempRes);
                    pj++;
                }
                digits[j] = inputDigits[j];
            }
            change1(i);
            tempRes = arrToInt();
            if (tempRes % 2 == 0)
                results.push_back(tempRes);
            pi++;
        }
        digits[i] = inputDigits[i];
    }

    // cout << results.size() << endl;
    int mx = -1;
    for (auto item : results)
    {
        mx = max(countDiv2(item), mx);
    }

    cout << mx << endl;
    return 0;
}