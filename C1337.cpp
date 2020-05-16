#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[200005];

int size[200005];
int depth[200005];
bool visited[200005];
vector<int> placeTurism;

int dfs(int u, int p)
{
	size[u] = 1;
	depth[u] = depth[p] + 1;
	
	for(int v : adj[u])
	{
		if(v != p)
		{
			size[u] += dfs(v, u);
		}
	}
	
	placeTurism.pb(size[u]-1 - depth[u]);
	
	return size[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;
	
	for(int i = 0; i < n-1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	depth[-1] = -1;
	depth[1] = 0;
	visited[1] = true;
	dfs(1, -1);
	
	sort(placeTurism.rbegin(), placeTurism.rend());
	ll sum = 0;
	for(int i = 0; i < n-k; i++)
	{
		sum+=placeTurism[i];
	}
	
	cout << sum << '\n';
	
	return 0;
}
