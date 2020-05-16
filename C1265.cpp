#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin>>t; 
	while(t--)
	{
		int n; cin >> n;
		map<int, int> p;
		
		int x;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			p[-x]++;
		}
		
		vector<int> pp;
		for (auto c: p)
		{
            pp.push_back(c.second);
		}
		
		bool ok = false;
		int g, s=0, b=0;
		
		g = pp[0];
		int i = 1;
		
		while(s <= g && i < pp.size())
		{
			s += pp[i++];
		}
		
		if(g < s)
		{
			while (b <= g && i < pp.size()){
				b += pp[i++];
			}
			while (i < pp.size() && g + s + b + pp[i] <= n / 2){
				b += pp[i++];
			}
			
			if(g < b && g + s + b <= n/2)
			{
				ok = true;
			}
			
		}
		
		if(!ok) cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
		else cout << g << ' ' << s << ' ' << b << '\n';
	}
	
	return 0;
}
