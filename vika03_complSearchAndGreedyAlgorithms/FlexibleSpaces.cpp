#include <iostream>
#include <vector>
#include <set>
#include <iterator>

// AC

using namespace std;

int main()
{
    int width, numPartitions, p, l, counter = 0, k;
    vector<int> partitions;
    set<int> eachDistinctWidth;
    set<int>::iterator itr;

    std::cin >> width >> numPartitions;
    partitions.push_back(0);
    for (int i = 0; i < numPartitions; i++)
    {
        std::cin >> p;
        partitions.push_back(p);
    }

    l = numPartitions;
    while (!partitions.empty())
    {
        k = partitions.back();
        while (l > 0)
        {
            counter++;
            eachDistinctWidth.insert(width - k);
            l--;
            k = partitions[l];
        }
        eachDistinctWidth.insert(width);
        l = counter - 1;
        counter = 0;
        width = partitions.back();
        partitions.pop_back();
    }

    for (itr = eachDistinctWidth.begin(); itr != eachDistinctWidth.end(); itr++)
    {
        std::cout << *itr << " ";
    }
}