#include <bits/stdc++.h> 
using namespace std; 


int main() 
{ 
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string s;
 		getline(cin,s);
 		cout<<s;
		unordered_map<string,int> mp;
		for (int i = 0; i < s.size(); ++i)
		{
			string word;
			if(s[i]==' '){
				continue;
			}
			while(i<s.size() && s[i]!=' '){
				word+=s[i];
				i++;
			}
			if(mp[word] > 0){
				cout<<word<<endl;
				break;
			}
			else{
				mp[word]++;
			}

		}
	}
	return 0;
} 