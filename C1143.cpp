#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	map<int, vector<int>> children;
	map<int, bool> resp;
	int root;
	for(int i = 1; i < n+1; i++ )
	{
		int t; cin >> t;
		if(t == -1) 
		{
			root = i;
		}
		children[t].pb(i);
		int c; cin >> c;
		resp[i] = (c == 1 ? false : true);
	}
	
	queue<int> q;
	q.push(root);
	vector<int> toRemove;
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		bool rem = (!resp[u] ? true : false);
		for(int v : children[u])
		{
			if(resp[v]) rem = false;
			q.push(v);
		}
		if(rem) toRemove.pb(u);
	}
			
	sort(toRemove.begin(), toRemove.end());
	
	if(toRemove.empty()) cout << -1;
	else
	{
		for(int i : toRemove)
		{
			cout << i << " ";
		}
	}
	
	cout << endl;
	
	return 0;
}
