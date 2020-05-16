#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[200005];
int parent[200005];
int level[200005];

int b[200005];
int f[200005];
int timer = 0;
void dfs(int s, int lvl)
{
	b[s] = timer; timer++;
	for(int v : adj[s])
	{
		if(!parent[v])
		{
			parent[v] = s;
			level[v] = lvl;
			dfs(v, lvl+1);
		}
	}
	f[s] = timer; timer++;
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	for(int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	parent[1] = 1;
	level[1] = 0;
	dfs(1, 1);
		
	for(int i = 0; i < m; i++)
	{
		int k; cin >> k;
		vector<int> path;
		int s;
		int maxLvl = INT_MIN;
		for(int i = 0; i < k; i++)
		{
			int v; cin >> v;
			v = parent[v];
			if(level[v] > maxLvl)
			{
				maxLvl = level[v];
				s = v;
			}
			path.pb(v);
		}
		
		bool ok = true;
		for(int v : path) 
		{
			if(!(b[v] <= b[s] && f[v] >= f[s]))
			{
				ok = false;
			}
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	
	return 0;
}
