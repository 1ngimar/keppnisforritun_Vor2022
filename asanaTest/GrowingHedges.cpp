#include <bits/stdc++.h>
using namespace std;




// function that simulates the growth of hedges over a given number of years
int pairsOfAdjacentHedges(int years, vector<vector<bool>> garden) // including diagonally
{
    vector<vector<bool>> gardenCopy;
    for (int year = 0; year < years; year++)
    {
        for (int i = 0; i < garden.size(); i++)
        {
            for (int j = 0; j < garden[i].size(); j++)
            {
                gardenCopy = simulate_one_year(garden);
            }
        }
    }
    return count_adjacent_hedges(gardenCopy);
}

int main()
{
    vector<vector<bool>> garden;
    // int height = garden.size();
    // int width = garden[0].size();
    bool spot;
    vector<bool> one_line_of_garden;
    
    while(cin >> ws)
    {

        one_line_of_garden.push_back()
    }
    
    return 0;
}