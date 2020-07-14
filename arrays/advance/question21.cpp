#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        std::vector<int> v(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>v[i];
        }
        int minimum=*(min_element(v.begin(),v.begin()+n));
        int maximum=*(max_element(v.begin(),v.begin()+n));
        if()
    }

	return 0;
}