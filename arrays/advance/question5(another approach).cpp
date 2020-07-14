#include <bits/stdc++.h>
using namespace std;

vector<int> duplicates(int a[], int n) {
    vector<int> ans;
    int index;
    for(int i=0; i<n ; ++i){
       index = a[i] % n;
       a[index] += n;
    }
    for(int i =0 ; i< n ; ++i){
        if(a[i]/n > 1)
            ans.push_back(i);
    }
    if(ans.size() ==0){
        ans.push_back(-1);
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        std::vector<int> ans;
        for (int i = 0; i < n; i++) cin >> a[i];
        ans=duplicates(a,n);
        for (auto it = ans.begin(); it != ans.end(); ++it)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}