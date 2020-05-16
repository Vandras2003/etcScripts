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
		
		set<int> k;
		
		int s = (int)sqrtl(n);
		
		k.insert(0);
		
		for(int i = 1; i <= s; i++ )
		{
			k.insert(i);
			k.insert(n/i);
		}
		
		cout << k.size() << '\n';
		for(int i : k) cout << i << ' ';
		cout << '\n';
		
	}
	
	return 0;
}
