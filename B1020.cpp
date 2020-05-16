#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_backs

using namespace std;

int track(map<int, int> m, int s)
{
	bool visited[1001] = {0};
	
	while(!visited[s])
	{
		visited[s] = true;
		s = m[s];
	}
	
	return s;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	map<int, int> m;
	for(int i = 1; i <= n; i++)
	{
		int t; cin >> t;
		m[i] = t;
	}
	
	for(int y = 1; y <= n; y++)
	{
		cout << track(m, y) << ' ';
	}
	
	return 0;
}
