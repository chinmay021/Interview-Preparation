#include <iostream> 
using namespace std; 
   // All rotations of A are contained in A+A
 
int findRotations(string str) 
{ 

    string tmp = str + str; 
    int n = str.length(); 
    for (int i = 1; i <= n; i++) { 
        string substring = tmp.substr(i, str.size()); 
        if (str == substring) 
            return i; 
    } 
    return n; 
} 
  
 
int main() 
{ 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string str = "cacc"; 
    cout << findRotations(str) << endl; 
    return 0; 
} 