#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> i_s;

// AC, kattis runtime: 0.01 s

vector<int> perfect_numbers;

int sum_of_proper_divisors(int x)
{
    int res = 1;
    for (int i = 2; i <= sqrt(x) ; i++)
    {
        if (x % i == 0)
        {
            if (i == x / i)
                res += i;
            else
                res += i + x / i;
        }
    }
    return res;
}

bool is_perfect(int x)
{
    for (int i = 0; i < perfect_numbers.size(); i++)
        if (x == perfect_numbers[i])
            return true;
    return false;
}

bool is_almost_perfect(int x)
{
    int sum = sum_of_proper_divisors(x);
    if (x - 2 <= sum && x + 2 >= sum)
        return true;
    return false;
}

int main()
{
    perfect_numbers.push_back(6);
    perfect_numbers.push_back(28);
    perfect_numbers.push_back(496);
    perfect_numbers.push_back(8128);
    perfect_numbers.push_back(33550336);

    int t;
    vector<int> numbers_input;
    list<i_s> numbers_output;
    while (cin >> t)
        numbers_input.push_back(t);

    for (int i = 0; i < numbers_input.size(); i++)
    {
        if (is_perfect(numbers_input[i]))
        {
            numbers_output.push_back(i_s(numbers_input[i], "perfect"));
            continue;
        }
        if (is_almost_perfect(numbers_input[i]))
            numbers_output.push_back(i_s(numbers_input[i], "almost perfect"));
        else
            numbers_output.push_back(i_s(numbers_input[i], "not perfect"));
    }

    for (auto my_pair : numbers_output)
        cout << my_pair.first << " " << my_pair.second << endl;

    return 0;
}