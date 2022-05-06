// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

// Bjarki Mar wrote this code, not me

using namespace std;

int main()
{
    const int ROWS = 9;
    const int COLUMNS = 9;
    char board[ROWS][COLUMNS] = {{'.','.','.', '.', '.', '.', '.','.','.'},
                                 {'.','.','.', '.', '.', 'k', '.','.','.'},
                                 {'.','.','.', '.', '.', 'k', '.','.','.'},
                                 {'.','.','k', '.', 'k', '.', '.','.','.'},
                                 {'.','.','.', 'k', '.', 'k', '.','.','.'},
                                 {'.','.','k', '.', 'k', '.', 'k','.','.'},
                                 {'.','.','.', '.', '.', '.', '.','.','.'}};
    // char inputLn[5] = {""};
    // for(int i = 0; i < 5; ++i)
    // {
    //     for (int j = 0; j < 5; ++j)
    //         cin >> board[i][j];
    // }


    // cout << board[1][0];
    // cout << endl;
    int counter = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
            cout << board[i][j];
        cout << endl;
    }

    for(int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++) {
            if(board[i][j] == 'k') {
                counter++;
                if(board[i+2][j+1] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;                   
                } 
                else if(board[i+2][j-1] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i-2][j+1] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i-2][j-1] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i+1][j-2] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i+1][j+2] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i-1][j+2] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }
                else if(board[i-1][j-2] == 'k') {
                    cout << "invalid";
                    cout << endl;
                    cout << i;
                    cout << endl;
                    cout << j;
                    cout << endl;
                }

            }
        }
    }
    if(counter < 9) {
        cout << "invalid";
        cout << endl;
    }
    return 0;
}