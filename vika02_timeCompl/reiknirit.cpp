#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
// #include <set>
// #include <list>
// #include <iterator>

using namespace std;

int main()
{
    long long n, e, result, eftir, oldDigit, count = 0;
    multiset<long long> myMultiset;
    set<long long>::iterator itr;
    list<long long> Counts;
    
    std::cin >> n;
    result = n;
    eftir = n;
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> e;
        myMultiset.insert(e);
    }

    itr = myMultiset.begin();
    oldDigit = *itr;
    for (itr = myMultiset.begin(); itr != myMultiset.end(); itr++)
    {
        if (oldDigit == *itr)
        {
            count++;
        }
        else
        {
            Counts.push_back(count);
            count = 1;
        }
        oldDigit = *itr;
    }
    Counts.push_back(count);

    Counts.sort();

    while (eftir != 0 || !Counts.empty())
    {
        eftir -= Counts.back();
        result += eftir;
        Counts.pop_back();
    }
    
    std::cout << result;

    return 0;
}