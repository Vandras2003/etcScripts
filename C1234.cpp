#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int q; cin>>q;
	
	while(q--)
	{
		int n; cin >> n;
		vector<int> pipes[2];
		
		for(int m = 0; m < 2; m++)
		{
			string s; cin >> s;
			for(char x: s)
			{
				pipes[m].pb((x - '0' <= 2 ? 0 : 1));
			}
		}
		

		bool ok = true;
		int i = 0, j = 0;
		
		while(j < n)
		{

			if(pipes[i][j] == 0)
			{
				j++; continue;
			}
			
			if(pipes[i][j] == 1)
			{
				if(pipes[1-i][j] != 1) 
				{
					ok = 0; break;
				}else if(j < n)
				{
					i = 1 - i;
					j++;
				}else
				{
					break;
				}
			}
		}
		
		if(i==0) ok = 0;
		
		cout << (ok ? "YES" : "NO") << '\n';
		
	}
			
	
	return 0;
}
