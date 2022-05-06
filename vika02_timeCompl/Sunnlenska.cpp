#include <iostream>
#include <string>

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

string changeCharsInWord(string word, int n)
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

string changeWords(string str, int n)
{
    string word = "", result = "", leftovers = "";
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        if (str[i] == ' ' || i == n)
        {
            word = "";
            for (int k = j; k < i; k++)
            {
                word += str[k];
            }
            if (!isName(word, i - j))
            {
                word = "";
                leftovers = "";
                if (str[j] == 'b') // checking for "bauk"
                {
                    for (int k = j; k < j + 4; k++)
                    {
                        word += str[k];
                    }
                    if (word == "bauk")
                    {
                        result += "dos";
                        for (int k = j + 4; k < i; k++)
                        {
                            leftovers += str[k];
                        }
                        result += changeCharsInWord(leftovers, i - j + 4);
                        if (i + 1 < n)
                        {
                            result += " ";
                        }
                    }
                    else
                    {
                        word = "";
                        for (int k = j; k < i; k++)
                        {
                            word += str[k];
                        }
                        result += changeCharsInWord(word, i - j);
                        if (i + 1 < n)
                        {
                            result += " ";
                        }
                    }
                }

                else if (str[j] == 'f') // checking for "flatbaka"
                {
                    for (int k = j; k < j + 8; k++)
                    {
                        word += str[k];
                    }
                    if (word == "flatbaka")
                    {
                        result += "petsa";
                        for (int k = j + 8; k < i; k++)
                        {
                            leftovers += str[k];
                        }
                        result += changeCharsInWord(leftovers, i - j + 8);
                        if (i + 1 < n)
                        {
                            result += " ";
                        }
                    }
                    else
                    {
                        word = "";
                        for (int k = j; k < i; k++)
                        {
                            word += str[k];
                        }
                        result += changeCharsInWord(word, i - j);
                        if (i + 1 < n)
                        {
                            result += " ";
                        }
                    }
                }
                else
                {
                    for (int k = j; k < i; k++)
                    {
                        word += str[k];
                    }
                    result += changeCharsInWord(word, i - j);
                    if (i + 1 < n)
                    {
                        result += " ";
                    }
                }
            }
            else
            {
                result += word;
                if (i + 1 < n)
                {
                    result += " ";
                }
            }
            j = i + 1;
        }
    }
    return result;
}

// #define MAX_LEN (5 * pow(10.0, 5.0))
// #define MAX_LEN 500001
int main()
{
    string str = "";
    // char y_name[MAX_LEN];
    // std::cin.getline(y_name, MAX_LEN);
    // str = y_name;

    std::cin >> std::ws; // glósa !!!!!!!!!!!!!
    getline(std::cin, str);

    int n = str.length();

    string result = changeWords(str, n);
    std::cout << result << std::endl;

    return 0;
}
