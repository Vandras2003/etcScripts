#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int maxPathThroughX = 0;
map<int, vector<int>> adj;
vector<int> parent;
vector<int> level;
map<int, vector<int>> children;
int finalX;
int maxDepth = 0;

void dfs(int s, int lvl)
{
	if(adj[s].size() == 1 && parent[s] > 0)
	{
		level[s] = lvl;
		maxDepth = max(maxDepth, lvl);
		return;
	}
	
	for(int u : adj[s])
	{
		if(parent[u] <= 0)
		{
			children[s].pb(u);
			parent[u] = s;
			level[u] = lvl;
			maxDepth = max(maxDepth, lvl);
			dfs(u, lvl+1);
		}
	}
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, x;
	cin >> n >> x;
	parent.resize(n, 0);
	level.resize(n, 0);
	
	for(int i = 0; i<n-1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	parent[1] = -1;
	dfs(1, 0);
	
	int a = maxDepth;

	for(int &i : level)
	{
		i = maxDepth - i;
	}
	
	int moves = 0;
	
	while(true)
	{
		if(level[x] = a-1)
		{
			moves += level[x]+1;
			break;
		}
		
		int bestX = 0;
		int posX = x;
		for(int i : children[x])
		{
			if(bestX < level[i])
			{
				bestX = level[i];
				posX = i;
			}	
		}
		if(level[parent[x]] != a)
		{
			if(bestX < level[parent[x]])
			{
				bestX = level[parent[x]];
				posX = parent[x];
			}	
		}
		
		a--;
		moves++;
	}
	
	cout << moves*2 << '\n';
	
	return 0;
}
