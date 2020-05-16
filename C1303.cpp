#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		string s; cin >> s;
		
		set<char> rem;
		for(char c = 'a'; c <= 'z'; c++)
		{
			rem.insert(c);
		}
		
		if(s.length() <= 1)
		{
			 rem.erase(rem[s[0]]);
			 cout << s[0];
			 for(auto y : rem)
			 {
				 cout << y;
			 }
			 cout << '\n';
			 break;
		 }
		
		map<char, set<char>> adj;
		int n = s.size();
		adj[s[0]].insert(s[1]);
		adj[s[n-1]].insert(s[n-2]);
		
		bool ok = true;
		
		for(int i = 1; i < n-1; i++)
		{
			adj[i].insert[s[i+1]];
			adj[i].insert[s[i-1]];
			if(adj[i].size() > 2)
			{
				ok = false;
				break;
			}
		}
		
		if(!ok){
			cout << "NO" << '\n';
			break;
		}
		
		string ans = "";
		char c1 = s[0];
		while(true)
		{
			
			 
			
		}
	}
	
	
	return 0;
}
