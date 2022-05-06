#include <iostream>
#include <vector>

// AC

using namespace std;

// This is a brute-force solution of the Nine Knights problem
// mabye try to make it more efficient later

/**
 * @brief For each knight on the board; check if he can attack another knight.
 *  If no knight can be attacked then print "valid", otherwise print "invalid"
 *
 * @param solution a 9x9 vector of the board that has the solution
 * @return int returns 0 to exit the program
 */
int checkDeadzones(vector<vector<char>> solution)
{
    for (int i = 2; i < 7; i++)
    {
        for (int j = 2; j < 7; j++)
        {
            if (solution[i][j] == 'k')
            {
                if (solution[i + 2][j + 1] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i + 2][j - 1] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i + 1][j - 2] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i + 1][j + 2] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i - 1][j - 2] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i - 1][j + 2] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i - 2][j - 1] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
                else if (solution[i - 2][j + 1] == 'k')
                {
                    std::cout << "invalid" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "valid" << std::endl;
    return 0;
}

int main()
{
    vector<vector<char>> board(9);
    char t = '.';
    // start by filling a 9x9 board with dots (empty)
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            board[i].push_back(t);
            // board[i][j] = t;
        }
    }

    int counter = 0;
    char c;
    // fill in the center 5x5 of the board with the input
    for (int i = 2; i < 7; i++)
    {
        for (int j = 2; j < 7; j++)
        {
            std::cin >> c;
            if (c == 'k')
            {
                counter++;
                board[i][j] = c;
            }
            // board[i].push_back(c);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // board[i].push_back(t);
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    if (counter != 9)
    {
        std::cout << "invalid" << std::endl;
        return 0;
    }

    checkDeadzones(board);
    return 0;
}