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
		int n; cin >> n;
		vector<int> changes;
		for(int i = 1; i <= n; i*=2)
		{
			changes.pb(i);
			n-=i;
		}
		
		if(n>0)
		{
			changes.pb(n);
			sort(changes.begin(), changes.end());
		}
		
		cout << changes.size() -1 << '\n';
		for(int i= 1; i < changes.size(); i++)
		{
			cout << changes[i] - changes[i-1] << ' ';
		}
		 
		cout << '\n';
	}
	
	return 0;
}
