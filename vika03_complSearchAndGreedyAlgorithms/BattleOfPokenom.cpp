#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

// Have not finished!!!!!!!!!!!!!!!!!!!!!!!!! and probably never will

using namespace std;

int main()
{
    char ac, bc;
    int T, K;
    list<int> all_k, all_k2, aStatEnd, bStatEnd, aStatPerRound, bStatPerRound, S_list, C_list;
    vector<int> battle;
    vector<vector<int>> allBattles;
    vector<int> prepForCee;
    vector<vector<int>> whatCeeKnows;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> K;
        all_k.push_front(K);
        int S;
        int aCountE = 0, ai = 0, bi = 0, bCountE = 0, aCountN = 0, bCountN = 0;
        int turn = 0, turnsLeft = K * 2, aOverB = 0, bOverA = 0;
        bool foundS = false;
        for (int round = 1; round <= K; round++)
        {
            cin >> ac >> bc;
            // Update turn (a's turn)
            turn++;
            turnsLeft--;

            if (ac == 'E') // if a's attack was effective
            {
                ai = 1;
                battle.push_back(ai);
                aStatPerRound.push_front(++aCountE);
            }
            else
            {
                ai = 0;
                battle.push_back(ai);
                aStatPerRound.push_front(aCountE);
            }

            aOverB = aCountE - bCountE;
            bOverA = bCountE - aCountE;

            if ((!foundS && aOverB > 1) || (!foundS && bOverA + 1 > 1))
            {
                if (turnsLeft <= aOverB || turnsLeft <= bOverA)
                {
                    S = turn;
                    S_list.push_front(S);
                    foundS = true;
                }
            }

            // Update turn (b's turn)
            turn++;
            turnsLeft--;

            if (bc == 'E') // if b's attack was effective
            {
                bi = 1;
                battle.push_back(bi);
                bStatPerRound.push_front(++bCountE);
            }
            else
            {
                bi = 0;
                battle.push_back(bi);
                bStatPerRound.push_front(bCountE);
            }

            aOverB = aCountE - bCountE;
            bOverA = bCountE - aCountE;

            if (!foundS)
            {
                if (turnsLeft <= aOverB || turnsLeft <= bOverA)
                {
                    S = turn;
                    S_list.push_front(S);
                    foundS = true;
                }
            }
        }
        foundS = false; // only to get the bool ready for next battle
        aStatEnd.push_front(aCountE);
        bStatEnd.push_front(bCountE);
        allBattles.push_back(battle);
        battle.clear();
        prepForCee.push_back(K);
        prepForCee.push_back(S);
        prepForCee.push_back(aCountE);
        prepForCee.push_back(bCountE);
        whatCeeKnows.push_back(prepForCee);
        prepForCee.clear();
    }

    all_k2 = all_k;

    cout << "printing what Cee knows" << endl;
    int i = 0;
    while (!all_k2.empty())
    {
        all_k2.pop_back();
        for (int j = 0; j < 4; j++)
        {
            cout << whatCeeKnows[i][j] << " ";
        }
        i++;
        cout << endl;
    }

    i = 0;
    while (i < whatCeeKnows.size())
    {
        int k = whatCeeKnows[i][0]; // Number of rounds
        int S = whatCeeKnows[i][1]; // The number of turns that Bash needed to see to determine victor or a draw
        int a = whatCeeKnows[i][2]; // Final score of opponent a
        int b = whatCeeKnows[i][3]; // Final score of opponent b
        int r = 2 * k;              // Number of turns
        int indexOfEquality, indexOfGiven = 0, aScoreAtIndex, bScoreAtindex;
        int givenNumber;
        int lower = 0, upper = r - 1;

        int CeePrediction[r];

        if (S == r && b == a && a > 1)
        {
            givenNumber = allBattles[i][indexOfGiven++];
            CeePrediction[lower++] = givenNumber;
        }
        while (lower != upper)
        {
            if (b > a)
            {
                if (S == r)
                {
                    CeePrediction[upper] = 1;
                    indexOfEquality = upper--;
                }
                else if (a + 1 == b)
                {
                    // now I think we know that b won every round in the first S turns
                    // THIS PROBLEM IS IMPOSSIBRUUUUUU
                }
            }
        }

        i++;
    }

    // int i = 0;
    // while (!all_k.empty())
    // {
    //     cout << endl;
    //     cout << "Result of game number " << i << endl;
    //     cout << "A Score per round--    aE \t -- \t bE \t-- B score per round" << endl;
    //     for (int j = 0; j < allBattles[i].size(); j += 2)
    //     {
    //         cout << allBattles[i][j] << " " << allBattles[i][j + 1] << endl;
    //     }
    //     i++;
    //     cout << "\nOpponent A got " << aStatEnd.back() << " points";
    //     cout << "\nOpponent B got " << bStatEnd.back() << " points" << endl;
    //     cout << "S = " << S_list.back() << endl;
    //     S_list.pop_back();
    //     aStatEnd.pop_back();
    //     bStatEnd.pop_back();
    //     all_k.pop_back();
    // }
    return 0;
}