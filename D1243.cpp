#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

set<pair<int, int>> E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		
		E.insert({u, v});
		E.insert({v, u});
	}
	
	
	return 0;
}
