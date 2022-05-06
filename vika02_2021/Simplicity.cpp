#include <iostream>
#include <string>
// #include <cstring>

// NOT FINISHED!!!!!!!!!!!!!!!!!!!!!!!!!!!!

using namespace std;

int len(string str)
{
    int counter = 0;
    for (int i = 0; str[i] == '\0'; i++)
    {
        counter++;
    }
    return counter;
}

// brute force of counting occurance of a char in string
int countOccurance(string str, char c, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (c == str[i])
        {
            count++;
        }
    }
    return count;
}

int main()
{
    string str;
    std::cin >> str;

    const int n = str.length();
    if (n <= 2)
    {
        std::cout << 0 << std::endl;
        return 0;
    }



    // GERA ÞETTA ENDURKVÆMT HELD ÉG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



    
    int simplicity = 0;
    int occurance;
    for (int i = 0; i < n; i++)
    {
        occurance = countOccurance(str, str[i], n);
        if (occurance == 1  && str.length() >= 2)
        {
            
            simplicity++;
        }
        else
        {
            /* code */
        }
        
        
    }
    std::cout << simplicity << std::endl;
    return 0;
}