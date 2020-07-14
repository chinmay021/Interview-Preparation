#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int n);
int main() {
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        printDuplicates(a, n);
        cout << endl;
    }
    return 0;
}// } Driver Code Ends
/*Complete the function below*/
void printDuplicates(int a[], int n) {
        int flag=1;
       std::map<int, int> mymap;
       for (int i = 0; i < n;  ++i)
       {
           mymap[a[i]]++;
       }
       for (int i = 0; i < n; ++i)
       {
           if(mymap[a[i]]>1)
           {
            cout<<a[i]<<" ";
            mymap[a[i]]=0;
            flag=0;
           }
       }
       if(flag)
       {
        cout<<"-1";
       }
}