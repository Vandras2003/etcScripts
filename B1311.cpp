#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_backs

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	{
		int n, m; cin >> n >> m;
		
		vector<int> a(n);
		set<int> p;
		
		for(auto &t: a) cin >> t;
		for(int i = 0; i<m; i++)
		{
			int t; cin >> t;
			p.insert(t);
		}
		
		bool no = false;
		
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<n-1; j++)
			{
				if( a[j] > a[j+1] )
				{
					if(p.count(j+1	) == 0)
					{
						no = true;
						break;
					}
						
					int temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
			if(no) break;
		}
		
		cout << (no ? "NO" : "YES") << '\n';
	}	
	
	return 0;
}
