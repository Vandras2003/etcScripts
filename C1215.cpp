#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	vector<char> a(n), b(n);
	
	int cnta = 0, cntb = 0;
	
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
		
		if(a[i] == 'a') cnta++;
		else cntb++;
	}
	
	for(int i = 0;i < n; i++)
	{
		cin >> b[i];
		
		if(b[i] == 'a') cnta++;
		else cntb++;
	}
	
	
	
	if(cnta %2== 0 && cntb%2 == 0)
	{
		
			
		vector<int> ab, ba;
		
		for(int i = 0; i < n; i++)
		{
			if(a[i] == 'a' && b[i] == 'b') ab.pb(i);
			else if(a[i] == 'b' && b[i] == 'a') ba.pb(i);
		}
		
		
		cout << ab.size()/2 + ba.size()/2 + (ab.size()%2==1 && ba.size()%2 == 1?2 :0) << '\n';
		
		if(ab.size() %2==1 && ba.size() %2==1)
		{
			cout << ab[ab.size()-1]+1 << ' ' << ab[ab.size() - 1] + 1 << '\n';
			ba.pb(ab[ab.size()-1]);
			ab.pop_back();
		}
		
		for(int i = 0; i < (int)ab.size(); i+=2)
		{
			cout << ab[i]+1 << ' ' << ab[i+1]+1  << '\n';
		}
		
		for(int i = 0 ; i < (int)ba.size(); i+=2)
		{
			cout << ba[i]+1 << ' ' << ba[i+1]+1 << '\n';
		}
		
		
		
	}
	else
	{
		cout << -1 << '\n';
	}
		
	
	return 0;
}
