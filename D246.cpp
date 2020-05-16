#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[100002];
int c[100002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	for(int i = 1; i < n+1; i++)
	{
		int x; cin >> x;
		c[i] = x;
	}
	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	set<int> s[100002];
	int mx = 0;
	vector<int> ans(100002, INT_MAX);

	for(int i = 1; i < n+1; i++)
	{
		for(int x : adj[i])
		{
			if(c[x] != c[i]) s[c[i]].insert(c[x]);
		}
		
		if(s[c[i]].size() >= mx)
		{
			mx = s[c[i]].size();
			ans[mx] = (c[i] > ans[mx] ? ans[mx] : c[i]);
		}
		
	}
	
	cout << ans[mx] << '\n';
	
	return 0;
}
