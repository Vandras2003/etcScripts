#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_backs

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &t : a) {
		cin >> t;
		t*=-1;
	}
	
	sort(a.rbegin(), a.rend());
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		if(sum+a[i] < sum) break;
		else sum += a[i];
	}
	
	cout << sum << "\n";
	
	return 0;
}
