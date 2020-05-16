#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		int x; cin >> x;
		string a; cin >> a;
		ll len = a.length();
		
		vector<int> s;
		
		if((int)a.length() < x)
		{
			for(char c: a)
			{
				s.pb(c-'0');
			}
			
			int l = 0;
		
			while((int)s.size() < x)
			{
				l++;
				int llen = s.size();
				
				for(int i = 0; i < s[l-1]-1; i++)
				{
					for(int j=l; j < llen; j++)
					{
						s.pb(s[j]);
					}
				}
			}
			
		}else
		{
			for(int i = 0; i < x; i++)
			{
				s.pb(a[i]-'0');
			}
		}

		for(ll i = 1; i <= x; i++)
		{
			if(s[i-1] == 1)
			{
				continue;
			}
			
			if(s[i-1] == 2)
			{
				len = i + 2*(len-i);
				len+=MOD;
				len %= MOD;
			}
			
			if(s[i-1] == 3)
			{
				len = i + 3*(len-i);
				len+=MOD;
				len %= MOD;
			}
		}

		cout << len << '\n';
		
	}	
	return 0;
}
