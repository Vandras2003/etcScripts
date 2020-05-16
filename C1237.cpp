#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;


const int D = 3;
vector<vector<int>> p;

int solve(vector<int> id, int lvl)
{
	if(lvl==D) return id[0];
	
	map<int, vector<int>> mp;
	
	for(int i: id)
	{
		mp[p[i][lvl]].pb(i);
	}
	
	vector<int> res;
	for(auto m: mp)
	{
		int cur = solve(m.second, lvl+1);
		if(cur != -1)
		{
			res.pb(cur);
		}
	}
	
	for(int i = 0; i < (int)res.size() - 1; i += 2)
	{
		cout << res[i]+1 << ' ' << res[i+1]+1 << '\n';
	}
	
	if(res.size() & 1) return res.back();
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	p.resize(n, vector<int>(D));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < D; j++)
		{
			cin >> p[i][j];
		}
	}
	
	vector<int> id(n);
	iota(id.begin(), id.end(), 0);
	
	solve(id, 0);
	
	return 0;
}
