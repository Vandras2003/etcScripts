#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[102];
vector<bool> visited(102, 0);

void dfs(int u)
{
	for(int v : adj[u])
	{
		if(!visited[v])
		{
			visited[v] = true;
			dfs(v);
		}
	}
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
		adj[v].pb(u);
	}
	
	bool ok = true;
	
	int count= 0;
	if(n != m) ok = 0;
	
	for(int i = 1; i < n+1; i++)
	{
		if(!ok) break;
		
		if(!visited[i])
		{
			visited[i] = true;
			dfs(i);
			count++;
		}
		if(count > 1) 
		{
			ok = 0; break;
		}
	}
	
	cout << (ok ? "FHTAGN!" : "NO") << '\n';
	
	
	return 0;
}
