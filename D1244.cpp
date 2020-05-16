#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int> adj[100005];

int deg[100005];

vector<int> color[100005];

int nxt[100005];

void dfs(int u, int p)
{
	for(int v : adj[u])
	{
		if(v != p)
		{
			nxt[u] = v;
			dfs(v, u);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	for(int j = 0; j < 3; j++)
	{
		for(int i = 1; i < n+1; i++)
		{
			int x; cin >> x; 
			color[i].pb(x);
		}
	}
	bool ok = 1;
	
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		
		adj[u].pb(v);
		adj[v].pb(u);
		
		deg[u]++;
		deg[v]++;
		if(deg[u] >= 3 || deg[v] >= 3) ok = false; 
	}
	
	vector<vector<int>> orders = {{0,1,2}, {0,2,1}, {1,2,0}, {1,0,2}, {2,1,0}, {2,0,1}};
	
	if(ok)
	{
		int s;
		for(int u = 1; u < n; u++)
		{
			if(deg[u]==1)
			{
				 s = u; break;
			}
		}
		
		dfs(s, -1);
		ll mn = LLONG_MAX;
		int mnColoring;
		
		int counter = 0;
		
		vector<vector<int>> colorings(6, vector<int>(n)) ;

		int u = s;

		for(auto ord: orders)
		{
			ll sum = 0;
			
			u = s;
			int i = 0;
			while(nxt[u])
			{
				sum += color[u][ord[i]];
				colorings[counter][u-1] = ord[i]+1;	
				u = nxt[u];
				i = (i==2? 0 : i+1);
			}

			sum += color[u][ord[i]];
			colorings[counter][u-1] = ord[i]+1;	
			u = nxt[u];
			
			if(sum < mn)
			{
				mn = sum;
				mnColoring = counter;
			}	
			counter++;	
		}
		
		cout << mn << '\n';
		for(int i: colorings[mnColoring]) cout << i << ' ';
		
	}
	else
	{
		cout << -1 << '\n';
	}
	
	return 0;
}
