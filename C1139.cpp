#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

vector<int> adj[200001];
bool visited[200001] = {0};

int power(int x, int y) 
{ 
    int res = 1; 
	//x = x%MOD;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % MOD; 

        y = y>>1;  
        x = (x*x)%MOD;  
    } 
    return res; 
}

int sz;
void dfs(int s)
{
	if(visited[s]) return;
	
	sz++;
	visited[s] = true;
	for(int u : adj[s])
		dfs(u);
	
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;
	
	int ans = power(n, k);
	
	for(int i = 0; i < n-1; i++)
	{
		int u, v, x; 
		cin >> u >> v >> x;
		
		if(x == 0)
		{
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	
	
	int sum = 0;
	for(int i = 1; i < n+1; i++)
	{
		if(visited[i]) continue;
		sz = 0;
		dfs(i);
		ans -= power(sz, k);
		ans += MOD;
		ans %= MOD;
	}

	cout << ans << '\n';
	
	return 0;
}
