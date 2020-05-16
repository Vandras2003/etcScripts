#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll n, p, d, w; cin >> n >> p >> w >> d;
	
	for(ll y = 0; y < w; y++)
	{
		if((p-(y*d)) % w ==0)
		{
			ll x = (p-(y*d))/w;
			if(x+y > n || x < 0 || y < 0) break;
			cout << x << ' ' << y << ' ' << n-x-y;
			return 0;
		}
	}
	
	cout << -1 << '\n';

	return 0;
}
