#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    ll result = 0;
    vector<ll> mealsAvailable, mealsEaten, reserve;
    vector<vector<ll>> stan;

    ll meal;
    for (int i = 0; i < n; i++)
    {
        cin >> meal;
        mealsAvailable.push_back(meal);
    }
    

    // initialize reserve
    ll m_copy = m;
    for (int i = 0; i < n; i++)
    {
        reserve.push_back(m_copy);
        m_copy -= ceil(m_copy * (1.0 / 3.0));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (mealsAvailable[k])
                {
                    /* code */
                }
                
            }
            
        }
        
    }
    
    
    
    

    return 0;
    

    


}