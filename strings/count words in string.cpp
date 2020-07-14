#include <bits/stdc++.h> 
using namespace std; 
  
/*  clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,
*/


int countWords(string str) 
{ 
    // breaking input into word using string stream 
    stringstream s(str); // Used for breaking words 
    string word; // to store individual words 
  
    int count = 0; 
    while (s >> word) //while we  are reading from the stream >>
        count++; 
    return count; 
} 
  
// Driver code 
int main() 
{ 
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s = "geeks for geeks geeks "
               "contribution placements"; 
    cout << " Number of words are: " << countWords(s); 
    return 0; 
} 