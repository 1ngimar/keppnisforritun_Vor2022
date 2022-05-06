#include <bits/stdc++.h>
using namespace std;

// UNFINISHED

int main()
{

    vector<vector<int>> grid;
    vector<int> v;
    int n, m, d;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> d;
            v.push_back(d);
        }
        grid.push_back(v);
        v.clear();
    }

    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> seven_sums;
    for (int i = 0; i < (rows % 3) + 1; i++)
    {
        for (int j = 0; j < (cols % 3) + 1; j++)
        {
            int row_sum = 0;
            int col_sum = 0;
            int diag_sum = 0, count_diag = 0;
            for (int r = i; r < i + 3; r++)
            {
                for (int c = j; c < j + 3; c++)
                {
                    row_sum += grid[r][c];
                    // col_sum += grid[c][r];
                    if (r == c)
                    {
                        count_diag++;
                        diag_sum += grid[r][c];
                    }
                }
                seven_sums.push_back(row_sum);
                // seven_sums.push_back(col_sum);
                if (count_diag == 3)
                {
                    seven_sums.push_back(diag_sum);
                    count_diag = 0;
                    diag_sum = 0;
                }
                row_sum = 0;
                // col_sum = 0;
            }

            for (int c = j; c < j + 3; c++)
            {
                for (int r = i; r < i + 3; r++)
                {
                    col_sum += grid[r][c];
                }
                seven_sums.push_back(col_sum);
                col_sum = 0;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < 6; i++)
    {
        if (seven_sums[i] != seven_sums[i + 1])
        {
            cout << "not magical!" << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
    {
        cout << "magical!" << endl;
    }
    return 0;
}