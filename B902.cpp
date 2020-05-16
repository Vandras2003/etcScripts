#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

map<int, vector<int>> children;
map<int, int> color;
map<int, int> curColor;
int moves = 0;

void colorTree(int node, int col)
{
	curColor[node] = col;
	vector<int> frontier = {node};
	while(!frontier.empty())
	{
		vector<int> next = {};
		for( int u : frontier)
		{
			for(int v : children[u])
			{
				curColor[v] = col;
				if(color[v] != col)
				{
					continue;
				} 
				next.pb(v);
			}
		}
		frontier = next;
	}
	moves++;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	
	
	for(int i = 2; i < n+1; i++)
	{
		int t; cin >>t; //t--;
		children[t].pb(i);
	}
	
	for(int i = 1; i< n+1; i++)
	{
		int t; cin >> t;
		color[i] = t;
		curColor[i] = 0;
	}
	
	vector<int> frontier = {1};
	
	if(curColor[1] != color[1])
	{
		colorTree(1, color[1]);
	}
	
	frontier = {1};
	while(!frontier.empty())
	{
		vector<int> next = {};
		for( int u : frontier)
		{
			for(int v : children[u])
			{
				if(curColor[v] != color[v])
				{
					colorTree(v, color[v]);
				}
				next.pb(v);
			}
		}
		frontier = next;
	}
	
	cout << moves << '\n';
	
	return 0;
}
