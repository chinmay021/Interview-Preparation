#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	//#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	//#endif


	// code from here
    int t;
    cin>>t;
    while(t--)
    {
    	std::vector<int> v;
    	int n,k;
    	cin>>n;
    	for(int i=0; i<n; ++i)
    	{
    		cin>>k;
    		v.push_back(k);
    	}
    	int rotation=1,temp;
    	for(int i=0 ; i<rotation; ++i)
    	{
    		//temp=v.back();
    		//cout<<temp<<endl;
    		v.insert(v.begin(),v.back());
            v.pop_back();
    	}
    	for(auto it=v.begin(); it!=v.end(); ++it)
    	{
    		cout<<*it<<" ";
    	}
    	cout<<endl;
    }

	return 0;
}