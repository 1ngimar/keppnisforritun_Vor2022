#include <iostream>
#include <string>

// AC

using namespace std;


// /**
//  * @brief Get the length of a string
//  * 
//  * @param str 
//  * @return int length of the string 
//  */
// int len(string str)
// {
//     int length = 0;
//     for (int i = 0; str[i] != '\0'; i++)
//     {
//         length++;
//     }
//     return length;
// }

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
    int i = 0;
    string result;

    // getting the first char and putting it in result
    char c = str[0];
    string temp(1, c);
    result += temp;

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