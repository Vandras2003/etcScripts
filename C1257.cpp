#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

const int INF = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		
		int n; cin >> n;

		int mn = INF;
		
		vector<int> occ(n+1, -1);
		
		for(int i = 0; i < n; i++)
		{
			int x; cin >> x;
			
			if(occ[x] != -1)
			{
				mn = min(mn, i - occ[x]);
				occ[x] = i;
			}
			
			if(occ[x] == -1) 
			{
				occ[x] = i;
			}
			
		} 
		
		cout << (mn==INF?-1:mn+1) << '\n';
	}
	
	return 0;
}
