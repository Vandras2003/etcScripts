#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll n, m; cin>> n >> m;
	
	vector<ll> a(n);
	
	for(ll &t: a) cin >> t;
	
	sort(a.begin(), a.end());
	
	vector<ll> sum(n);


	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		sum[i%m] += a[i];
		ans += sum[i%m];
		cout << ans << ' ';
	}

	return 0;
}
