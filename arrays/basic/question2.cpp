#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	std::vector<int> v;
	int n,m,k;
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		cin>>k;
		v.push_back(k);
	}
	auto it=v.begin();
	for( ; it!=v.end(); ++it){
		if(*it == n)
		{
			cout<<"YES";
			break;
		}
	}
	if(it==v.end())
	{
		cout<<"NO";
	}
	return 0;
}