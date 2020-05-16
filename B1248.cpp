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
	
	int nu = n/2;
	
	vector<int> a(n);
	for(int &t: a) cin >> t;
	
	sort(a.begin(), a.end());
	
	ll u = 0, r = 0;
	
	for(int i = 0; i<nu; i++)
	{
		u+=a[i];
	}
	for(int i = nu; i < n; i++)
	{
		r+=a[i];
	}
	
	cout << u*u+r*r << '\n';
	
	
	return 0;
}
