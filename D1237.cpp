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
	double mx = INT_MIN, mn = INT_MAX;
	vector<int> tracks;
	
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x; 
		mx = max(x, mx);
		mn = min(x, mn);
		tracks.pb(x);
	}
	
	if(mn > mx/2)
	{
		for(int i = 0; i < n; i++) cout << -1 << ' ';
		cout << '\n';
		return 0;
	}
	
	
	
	return 0;
}
