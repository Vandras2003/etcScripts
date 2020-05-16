#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define INF 1e9

using namespace std;

vector<vector<int>> adj;

void bfs(int s, vector<int> &p)
{
	p[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{		
		int u = q.front(); q.pop();
		
		for(int v: adj[u])
		{
			if(p[v] == INF)
			{
				p[v] = p[u] + 1;
				q.push(v);
			}
		}
	}
	
	return; 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n, m, a, b, c; cin >> n >> m >> a >> b >> c;
		
		vector<int> paths(m);
		
		for(int &x : paths) cin >> x;
		sort(paths.begin(), paths.end());
		
		vector<ll> pref(m+1);
		
		for(int i = 0; i < m; i++)
		{
			pref[i+1] = pref[i] + paths[i];
		}
		
		adj = vector<vector<int>>(n+1);
		
		for(int i = 0; i < m; i++)
		{
			int u, v; cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		vector<int> pa(n+1, INF), pb(n+1, INF), pc(n+1, INF);		
		
		bfs(a, pa); bfs(b, pb); bfs(c, pc);

		ll ans = LLONG_MAX;
		
		for(int x = 1; x < n+1; x++)
		{
			if(pa[x] + pb[x] + pc[x] > m) continue;
			
			ans = min(ans, pref[pb[x]] + pref[pa[x] + pb[x] + pc[x]]);
		}
		
		cout << ans << '\n';

	}
	
	return 0;
}
