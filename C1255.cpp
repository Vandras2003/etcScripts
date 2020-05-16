#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

vector<int>v[100005];
int f[100005] = {0};
int seen[100005] = {0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	
	for(int i = 0; i < n-2; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		f[x]++; f[y]++; f[z]++;
		v[x].pb(z); v[x].pb(y);
		v[y].pb(x); v[y].pb(z);
		v[z].pb(y); v[z].pb(x);
	}
	int start;
	for(int i = 1; i <= n; i++)
	{
		if(f[i] == 1)
		{
			start = i;
			break;
		}
	}

	cout << start << ' ';
	
	int p1 = start, p2 ;
	
	for(int i: v[p1])
	{
		
		if(f[i] == 2)
		{
			p2 = i;
			cout << i << ' ';
			break;
		}
	}
	
	seen[p1] = 1; seen[p2] = 1;
	
	for(int i = 0; i < n-2; i++)
	{
		for(int x: v[p1])
		{
			if(seen[x] == 0)
			{
				cout << x << ' ';
				seen[x] = 1;
				p1 = p2;
				p2 = x;
				break;
			}
		}
	}
	
	return 0;
}
