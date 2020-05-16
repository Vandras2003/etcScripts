#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int INF = 1e9 + 7;

vector<int> adj[200005];
set<pii> isProblem;

vector<int> level[200005];
int p[200005];
bool seen[200005] = {0};

int main()
{
	FAST
	
	int n; cin >> n;
	for(int i = 1 ; i < n; i++)
	{
		int u, v, x; cin >> u >> v >> x;
		adj[u].pb(v);
		adj[v].pb(u);
		
		if(x == 2) { isProblem.insert({u,v}); isProblem.insert({v, u}); }
	}		
	
	queue<pii> q;
	
	q.push({1, 0});
	level[0].pb(1);
	p[1] = 1;
	int mx = 0;
	while(!q.empty())
	{
		int u = q.front().first;
		int lvl = q.front().second;
		q.pop();
		lvl++;
		for(int v : adj[u])
		{
			
			if(v != p[u])
			{
				mx = max(lvl, mx);
				p[v] = u;
				level[lvl].pb(v);
				q.push({v, lvl});
			}
		}
	}

	vector<int> res;

	for(int i = mx; i > 0; i--)
	{
		for(int v : level[i])
		{
			if(seen[v]) continue;
			auto it = isProblem.find({v, p[v]});

			if(it != isProblem.end())
			{
				seen[v] = 1;
				res.pb(v);
				isProblem.erase(it);
				v = p[v];
				
				while(v != 1)
				{
					if(seen[v]) break;
					seen[v] = 1;
					it = isProblem.find({v, p[v]});
					if(it != isProblem.end()) isProblem.erase(it);
					v = p[v];
				}
			}
			
		}
	}
	
	cout << res.size() << '\n';
	for(int i : res) cout << i << ' ';
	
	return 0;
}
