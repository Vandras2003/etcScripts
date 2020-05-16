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
		
		string s; cin >> s;
		
		int mx = INT_MIN;
		
		int i = 0;
		while(i < n)
		{
			if(s[i] == '1')
			{
				mx = max(n-i, mx);
				break;
			}
			i++;
		}
		
		i = n-1;
		while(i > 0)
		{
			if(s[i] == '1')
			{
				mx = max(i+1, mx);
				break;
			}
			i--;
		}
		
		cout << (mx==INT_MIN?n:mx*2) << '\n';
		
	}
	
	
	return 0;
}
