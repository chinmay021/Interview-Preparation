#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	// code from here
    int t;
    cin>>t;
  //  cout<<"hello";
    while(t--)
    {
        int n,target,double_count=0,k;
        cin>>n>>target;
        std::vector<int> v(n);
        std::map<int, int> mymap;
        std::vector<int> arr(2);
        for(int i=0; i<n; ++i) {
            cin>>v[i];
            // v.push_back(k);
        }
        // for(int i=0; i<n; ++i) {
        //     cout<<v[i];
        //     // v.push_back(k);
        // }

        // for(auto it=v.begin(); it!=v.end(); ++it) 
        //     cout<<*it<<" ";
        //std::map<int, int> mymap;
        for (int i = 0; i < n; ++i)
        {
            mymap[v[i]]++;
        }

        for (int i = 0; i < n; ++i)
        {
            if(mymap[target-v[i]])
            {
                double_count+=mymap[target-v[i]];
                if(target-v[i]==v[i])
                    double_count--;


            }
        }
        cout<<double_count/2<<endl;
    }
	return 0;
}