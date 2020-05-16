#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[100005];

int start[100005];
int finish[100005];
vector<bool> visited(100005, 0);
int timer = 0;
int black_edges = 0;

vector<pair<int, int>> edges;

void dfs(int u)
{
	start[u] = timer;
	timer++;
	for(int v : adj[u])
	{
		if(!visited[v])
		{
			visited[v] = 1;
			dfs(v);
		}
	}
	finish[u] = timer;
	timer++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		edges.pb({u, v});
	}
	
	for(int s = 1; s < n+1; s++)
	{
		if(!visited[s]) {
			visited[s] = 1;
			dfs(s);
		}
	}
	
	vector<int> ans;
	
	for(auto e : edges)
	{
		if(start[e.second] < start[e.first] && finish[e.first] < finish[e.second])
		{
			ans.pb(2);
			black_edges++;
		}
		else ans.pb(1);
	}
	
	cout << (black_edges > 0 ? 2 : 1) << '\n';
	for(int i : ans) cout << i << ' ';
	
	
	return 0;
}
