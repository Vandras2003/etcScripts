#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	queue<pair<int, int>> frontier;
	frontier.push({n, 0});
	int moves;
	
	while(!frontier.empty())
	{
		auto i = frontier.front();
		frontier.pop();
		
		if(i.first - 1 == m || i.first*2 == m)
		{	
			moves = i.second+1;
			break;
		}
		//cout << i.second << endl;
		frontier.push({i.first-1, i.second+1});
		if(i.first*2 >  m*2) continue; 
		
		
		frontier.push({i.first*2, i.second+1});
	}
	
	cout << moves << '\n';
	
	
	return 0;
}
