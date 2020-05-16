#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

unordered_set<int> adj[200002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	bool ok = true;
	queue<int> bfs;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		bfs.push(x);
	}
	adj[1].insert(-1);
	queue<int> q;
	q.push(1);
	if(bfs.front() != 1)
	{
		cout << "No";
		return 0;
	}
	bfs.pop();
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		int x = adj[u].size()-1;
		
		for(int i = 0; i < x; i++)
		{
			int v = bfs.front(); bfs.pop();
			if(adj[u].count(v))
			{
				adj[u].erase(v);
				q.push(v);
			}
		}
		
		if(adj[u].size() > 1)
		{
			ok = 0; break;
		}
	}
			
	cout << (ok ? "Yes" : "No") << '\n';
	
	return 0;
}
