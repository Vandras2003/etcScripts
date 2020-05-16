#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, p; cin >> n >> p;
	
	unsigned int ans = 0, res = 0;

	unsigned int x = 1;
	for(unsigned int i = 31; i > 0; i--)
	{

		while(ans + (x*1<<i) + p <= n)
		{
			ans += (x*1<<i) + p;
			res++;
		}
		
		//if(ans == n)break;
	}
	
	while(ans + 1 + p <= n)
	{
		ans += 1 + p;
		res++;
	}
	
	if(ans == n) cout << res << '\n';
	else cout << -1 << '\n';
	
	return 0;
}
