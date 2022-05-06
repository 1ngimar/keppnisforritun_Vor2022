#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>

// AC

using namespace std;

int main()
{
    int t, n;
    string bandStr, songStr;
    int bandLetterCount = 0, songLetterCount = 0;
    set<string> songSet;
    queue<string> everything;
    queue<int> n_queue;

    // t = number of bands
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        // n = number of songs of one band
        std::cin >> n; 
        n_queue.push(n);

        // getting the name of the band
        std::cin >> std::ws;                        // glósa !!!!!!!!!!!!!
        bandStr = "";
        getline(std::cin, bandStr);                 // glósa !!!!!!!!!
        everything.push(bandStr);
        // -----------------------------

        // getting the name of each song by the band
        for (int j = 0; j < n; j++)
        {
            songStr = "";
            getline(std::cin, songStr);
            everything.push(songStr);
        }
        // -----------------------------------------
    }

    while (everything.size() > 0)
    {
        // getting the name of a band
        bandStr = everything.front();
        everything.pop();
        // --------------------------

        // getting letter count of the bandname
        bandLetterCount = bandStr.size() - std::count(bandStr.begin(), bandStr.end(), ' ');

        // printing the bandname
        bandStr += ":\n";
        std::cout << bandStr;
        // ---------------------

        // Checking all songs of one band
        for (int j = 0; j < n_queue.front(); j++)
        {
            // getting name of a song
            songStr = everything.front();
            everything.pop();
            // --------------------

            // getting lettercount of a song
            songLetterCount = songStr.size() - std::count(songStr.begin(), songStr.end(), ' ');

            // adding matches to a set so they will automatically be sorted
            if (bandLetterCount == songLetterCount)
            {
                songSet.insert(songStr);
            }
            // ------------------------------------------------------------
        }
        // printing the songs of one band in alphabetical order
        while (songSet.size() > 0)
        {
            songStr = *songSet.begin() + "\n";
            std::cout << songStr;
            songSet.erase(songSet.begin());
        }
        n_queue.pop(); // deleting the n that is first in the queue
    }
    return 0;
}