#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

#define float long double

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	map<float, int> m;
	
	vector<float> a(n);
	for(float &t: a) cin >> t;
	
	int mx = 0;
	int plus = 0;
	
	for(int i = 0; i < n; i++)
	{	
		float x; cin >> x;

		if(x == 0)
		{
			if(a[i] == 0) plus++;
			else
			{
				m[0]++;
				mx = max(mx, m[0]);
			}
		} else {
			if(a[i] != 0) m[(a[i]/x)*100]++;
			mx = max(mx, m[(a[i]/x)*100]);
		}
	}
	
	cout << mx+plus << '\n';
	
	return 0;
}
