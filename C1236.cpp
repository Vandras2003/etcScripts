#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	vector<vector<int>> groups(n);
	
	int counter = 1;
	
	for(int x = 0; x < n; x++)
	{
		if(x%2==0)
		{
			for(int i = 0; i < n; i++)
			{
				groups[i].pb(counter++);
			}
		
		}else
		{
			for(int i = n-1; i >= 0; i--)
			{
				groups[i].pb(counter++);
			}
		}
	}
	
	for(auto y:groups)
	{
		for(int i: y) cout << i << ' ';
		cout << '\n';
	}
	
	return 0;
}
