#include <iostream>
#include <string>

// AC

using namespace std;

/**
 * @brief Takes in a single line of input as string and prints the abbreviation
 *  according to the seperator '-'
 * 
 * sample input:    Ingimar-Logi-Gudlaugsson
 * sample output:   ILG
 */
int main()
{
    string str;
    std::cin >> str;
    int n = str.length();
    char seperator = '-';
    string result;

    // getting the first char and putting it in result
    char c = str[0];
    string temp(1, c);
    result += temp;
    
    int i = 0;
    while (i <= n)
    {
        if (str[i-1] == seperator)
        {
            c = str[i];
            temp = c;
            result += temp;
        }
        i++;
    }
    std::cout << result << std::endl;
    return 0;   
}