#include <iostream>
#include <string>
#include <vector>

// NOT FINISHED AND DO NOT PLAN TO FINISH

using namespace std;

bool isName(string word, int n)
{
    if (word == "Flatbakan" || word == "Bauk")
    {
        return true;
    }
    else
    {
        return false;
    }
}

string changeCharsInSingleWord(string word, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (word[i] == 'k')
        {
            word[i] = 'g';
        }
        else if (word[i] == 'y')
        {
            word[i] = 'u';
        }
    }
    return word;
}

// string changeWords(string str, int n)
// {
    
// }

int main()
{
    string str = "", word = "", result = "";
    std::cin >> std::ws;
    getline(std::cin, str);
    int n = str.length(), j = 0;

    vector<string> allWords;

    for (int i = 0; i < n; i++)
    {
        word += str[i];
        if (str[i] == ' ' || i == n)
        {
            result += changeCharsInSingleWord(word, word.size());
            word = "";
        }
    }
    
    


    // string result = changeWords(str, n);
    std::cout << result << std::endl;

    return 0;
}