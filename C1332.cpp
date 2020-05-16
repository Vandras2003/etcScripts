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
		int n, k; cin >> n >> k;
		
		string s; cin >> s;
		vector<string> ss;
		for(int i = 0; i < n; i+=k)
		{
			ss.pb(s.substr(i, k));
		}
		
		int x = ss.size();

		int maxApp = 0;
		vector<map<char, int>> pos(k/2+1);
		
		int changes = 0;
		
		for(int i = 0; i < k/2; i++)
		{
			int maxApp = 0;
			for(auto y : ss)
			{
				pos[i][y[i]]++;
				if(pos[i][y[i]] > maxApp) maxApp = pos[i][y[i]];
				pos[i][y[k-i-1]]++;
				if(pos[i][y[k-i-1]] > maxApp) maxApp = pos[i][y[k-i-1]];
			}
			
			changes += 2*x - maxApp;
		}
		
		if(k%2 == 1)
		{
			int i = k/2;
			int maxApp = 0;
			for(auto y : ss)
			{
				pos[i][y[i]]++;
				if(pos[i][y[i]] > maxApp) maxApp = pos[i][y[i]];
			}
			changes += x - maxApp;
		}
		
		cout << changes << '\n';
	}
	return 0;
}
