#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;
int parent[200005];
int depth[200005];
vector<int> adj[200005];
vector<int> children[200005];
void dfs(int u, int lvl)
{
	for(int v: adj[u])
	{
		if(!parent[v])
		{
			depth[v] = lvl;
			parent[v] = u;
			dfs(v, lvl+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	
	for(int u = 1; u < n+1; u++)
	{
		if(!parent[u])
		{
			parent[u] = -1;
			depth[u] = 0;
			dfs(
	
	
	return 0;
}
