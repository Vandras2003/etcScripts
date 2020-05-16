#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;
	
	string s; cin >> s;
	
	cout << n << '\n';
	
	string ss = s;
	for(int i = 0 ; i < n-k; i++)
	{
		ss[i+k] = ss[i];
	}

	if(ss >= s)
	{;
		cout << ss << '\n';
		return 0;
	}
	
	for(int i = k-1; i >= 0; i--)
	{
		if(ss[i] != '9')
		{
			ss[i]++;
			int j = i + k;
			while(j < n)
			{
				ss[j] = ss[i];
				j+=k;
			}
			break;
		}else if(ss[i] == '9')
		{
			ss[i] = '0';
			int j = i + k;
			while(j < n)
			{
				ss[j] = ss[i];
				j+=k;
			}
		}
	}
	
	cout << ss << '\n';
	
	return 0;
}
