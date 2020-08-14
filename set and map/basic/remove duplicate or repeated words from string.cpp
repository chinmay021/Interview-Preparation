#include <bits/stdc++.h>
using namespace std;

void removeDupWord(string str)
{
    // Used to split string around spaces.
    stringstream ss(str);
    unordered_set<string> hsh;
    while (ss)
    {
        string word;
        ss >> word;
        while (hsh.find(word) == hsh.end())
        {
            cout << word << " ";
            hsh.insert(word);
        }
    }
}

// Driver function
int main()
{
    string str = "Geeks for Geeks A Computer"
                 " Science portal for Geeks";
    removeDupWord(str);
    return 0;
}
// Output:
// Geeks for A Computer Science portal