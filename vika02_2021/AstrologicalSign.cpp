#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>

using namespace std;

// This solution is very brute forcy, please consider making it better
// Test time by Kattis: 0.01 sec
// AC

int main()
{
    vector<tuple<int, int, int>> dateFromTo;
    dateFromTo.push_back(make_tuple(21, 20, 31));
    dateFromTo.push_back(make_tuple(21, 20, 30));
    dateFromTo.push_back(make_tuple(21, 21, 31));
    dateFromTo.push_back(make_tuple(22, 22, 30));
    dateFromTo.push_back(make_tuple(23, 22, 31));
    dateFromTo.push_back(make_tuple(23, 21, 31));
    dateFromTo.push_back(make_tuple(22, 22, 30));
    dateFromTo.push_back(make_tuple(23, 22, 31));
    dateFromTo.push_back(make_tuple(23, 21, 30));
    dateFromTo.push_back(make_tuple(22, 20, 31));
    dateFromTo.push_back(make_tuple(21, 19, 31));
    dateFromTo.push_back(make_tuple(20, 20, 29));

    vector<tuple<string, string, string>> monthFromToAstro;
    monthFromToAstro.push_back(make_tuple("Mar", "Apr", "Aries"));
    monthFromToAstro.push_back(make_tuple("Apr", "May", "Taurus"));
    monthFromToAstro.push_back(make_tuple("May", "Jun", "Gemini"));
    monthFromToAstro.push_back(make_tuple("Jun", "Jul", "Cancer"));
    monthFromToAstro.push_back(make_tuple("Jul", "Aug", "Leo"));
    monthFromToAstro.push_back(make_tuple("Aug", "Sep", "Virgo"));
    monthFromToAstro.push_back(make_tuple("Sep", "Oct", "Libra"));
    monthFromToAstro.push_back(make_tuple("Oct", "Nov", "Scorpio"));
    monthFromToAstro.push_back(make_tuple("Nov", "Dec", "Sagittarius"));
    monthFromToAstro.push_back(make_tuple("Dec", "Jan", "Capricorn"));
    monthFromToAstro.push_back(make_tuple("Jan", "Feb", "Aquarius"));
    monthFromToAstro.push_back(make_tuple("Feb", "Mar", "Pisces"));

    vector<tuple<int, string, string>> allDatesWithAstro;
    for (int i = 0; i < 12; i++)
    {
        string firstMonth = get<0>(monthFromToAstro[i]);
        string secondMonth = get<1>(monthFromToAstro[i]);
        string Astro = get<2>(monthFromToAstro[i]);
        int first = get<0>(dateFromTo[i]);
        int second = get<1>(dateFromTo[i]);
        int firstLimit = get<2>(dateFromTo[i]);
        while (first <= firstLimit)
        {
            allDatesWithAstro.push_back(make_tuple(first, firstMonth, Astro));
            first++;
        }
        firstLimit = 1;
        while (firstLimit <= second)
        {
            allDatesWithAstro.push_back(make_tuple(firstLimit, secondMonth, Astro));
            firstLimit++;
        }
    }

    // for (int i = 0; i < allDatesWithAstro.size(); i++)
    // {
    //     std::cout << get<0>(allDatesWithAstro[i]) << " " << get<1>(allDatesWithAstro[i]) << " " << get<2>(allDatesWithAstro[i]) << std::endl;
    // }
    // return 0;

    int t;
    std::cin >> t;

    int day;
    string month;
    vector<tuple<int, string>> birthday;
    for (int i = 0; i < t; i++)
    {
        std::cin >> day;
        std::cin >> month;
        birthday.push_back(make_tuple(day, month));
    }
    int bDay;
    string bMonth;
    int aDay;
    string aMonth;
    for (int i = 0; i < t; i++)
    {
        bDay = get<0>(birthday[i]);
        bMonth = get<1>(birthday[i]);
        for (int j = 0; j < allDatesWithAstro.size(); j++)
        {
            aDay = get<0>(allDatesWithAstro[j]);
            aMonth = get<1>(allDatesWithAstro[j]);
            if (bDay == aDay && bMonth == aMonth)
            {
                std::cout << get<2>(allDatesWithAstro[j]) << std::endl;
            }
        }
    }
    return 0;
}