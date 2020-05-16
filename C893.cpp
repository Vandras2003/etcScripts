#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[100001];
int cost[100001];
bool visited[100001] = {0};
ll minCost;

void dfs(int s)
{
	if(adj[s].size() == 0) return;
	for(int v : adj[s])
	{
		if(!visited[v])
		{
			visited[v] = true;
			minCost = (cost[v] < minCost ? cost[v] : minCost);
			dfs(v);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i < n+1; i++)
	{
		int x; cin >> x;
		cost[i] = x;
	}
	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	ll ans = 0;
	
	for(int i = 1; i < n+1; i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			minCost = cost[i];
			dfs(i);
			ans+=minCost;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
