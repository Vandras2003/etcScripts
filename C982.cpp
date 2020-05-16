#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[100005];
bool visited[100005];
vector<int> children[100005];
int size[100005];

int dfs(int u, int p)
{
	size[u] = 1;
	
	for(int v: adj[u])
	{
		if(v != p)
		{
			children[u].pb(v);
			size[u] += dfs(v, u);
		}
	}
	
	return size[u];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin>>n;
	
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	if(n % 2  == 1) 
	{
		cout << -1 << '\n';
		return 0;
	}
	
	//visited[1] = true;
	dfs(1, 0);
	int ans = 0;
	
	for(int u = 1; u < n+1; u++)
	{
		for(int v : children[u])
		{
			if(size[v] %2  == 0)
			{
				ans++;
			}
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
