#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int n;
int ans = INT_MAX;

void search(vector<int> bulbs, int pos, int even, int odd)
{
	if(pos == n)
	{	
		int x = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(bulbs[i] != bulbs[i+1]) x++;
		}
		ans= min(x, ans);
		return;
	}
	
	if(bulbs[pos] == 1 || bulbs[pos] == 0) search(bulbs, pos+1, even, odd);
	
	if(bulbs[pos] == -1)
	{
		if(odd > 0)
		{
			bulbs[pos] = 1;
			search(bulbs, pos+1, even, odd-1);
		}
		
		if(even > 0)
		{
			bulbs[pos] = 0;
			search(bulbs, pos+1, even-1, odd);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	int odd = (n%2==1 ? (n/2 + 1) : n/2);
	int even = n/2;
	
	//cout << even << ' ' << odd << endl;
	
	vector<int> bulbs(n);
	
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if(x==0) 
		{
			bulbs[i] = -1; continue;
		}
		
		if(x%2==0)
		{
			even--;
			bulbs[i] = 0;
		} else {
			odd--;
			bulbs[i] = 1;
		}
	}

	//cout << even << ' ' << odd << endl;

	search(bulbs, 0, even, odd);
	
	cout << ans << '\n';
	
	return 0;
}
