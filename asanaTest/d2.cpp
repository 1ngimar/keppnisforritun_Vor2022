#include<bits/stdc++.h>
using namespace std;


vector<int> solution(vector<string> words, string letters) {
    multiset<char> mymultiset;
    set<char> mySet;
    string tempWord;
    char tempLetter, tempLetter2;
    vector<int> counts;
    int count;
    
    for (int i = 0; i < words.size(); i++) {
        tempWord = words[i];
        for (int j = 0; j < letters.length(); j++) {
            tempLetter = letters[j];
            for (int k = 0; k < tempWord.length(); k++) {
                tempLetter2 = tempWord[k];
                if (tempLetter2 != tempLetter) {
                    mymultiset.insert(tempLetter);
                }
            }
        }
        int size = mymultiset.size();
        count = 0;
        for (auto item : mymultiset) {
            if (mymultiset.count(item) == 1) {
                count++;
            }
        }
        counts.push_back(count);
        mymultiset.clear();
    }
    return counts;
}

int main()
{
    vector<string> words;
    string letters;
    int n;
    cin >> n;
    string word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        words.push_back(word);
    }
    cin >> letters;
    solution(words, letters);
    
    
    return 0;
}