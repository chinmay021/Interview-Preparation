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
	std::vector<int> v;
	int n,k;
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>k;
		v.push_back(k);
	}
	for (auto it=v.begin(); it!=v.end(); ++it)
	{
		if(*it == 0)
		{
			v.erase(it);
			v.insert(v.begin(),0);
		}
		else if(*it == 2)
		{
			v.erase(it);
			v.push_back(2);
		 }
	}
	for(auto it=v.begin(); it!=v.end(); ++it)
	{
		cout<<*it<<" ";
	}
	return 0;
}