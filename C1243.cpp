#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

bool isPrime(ll n)
{
	for(ll i = 2; i*i <= n; i++)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll n; cin >> n;
	
	if(n==1) cout << 1 << '\n';
	else if(__builtin_popcount(n) == 1) cout << 2 << '\n';
	else if (isPrime(n)) cout << n << '\n';
	else
	{
		for(ll i = 2; i*i <= n; i++)
		{
			if(n % i == 0)
			{
				while( n % i == 0) n/=i;		
				if(n>1) cout << 1 << '\n';
				else cout << i << '\n';
				return 0;
			}
		}
	}
		
	
	return 0;
}
