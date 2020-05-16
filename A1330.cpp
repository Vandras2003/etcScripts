#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; cin>> t;
	while(t--)
	{
		int n, x; cin >> n >> x;
		vector<int> a(305, 1);
		
		for(int i = 0; i < n; i++)
		{
			int num; cin >> num;
			a[num] = 0;
		}
		
		int p2 = 1;
		int sum = a[p2];

		while(p2 < 305 && sum <= x)
		{
			p2++;
			sum += a[p2];
		}
		
		cout << p2-1 << endl;
	}
	
	return 0;
}
