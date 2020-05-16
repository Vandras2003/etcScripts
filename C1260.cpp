#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		ll r, g, k; cin >> r >> g >> k;
		
		ll a= min(r,g), b = max(r,g);
		
		ll li = __gcd(a, b);
		
		a /= li;
		b /= li;
		
		if((k-1) * a + 1  <  b) cout << "REBEL" << '\n';
		else cout << "OBEY" << '\n';
		
		
	}
	
	
	return 0;
}
