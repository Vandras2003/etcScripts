#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

bool pathFound = false;

// 1 = up
// 2 = down
// 3 = right
// 4 = left

void findPath(vector<vector<int>> grid, int sy, int sx, int vy, int vx, int last, int turns, map<pair<int,int>, bool> visited)
{
	//cout << sy << " " << sx << endl;
	
	if(sy == vy && sx == vx)
	{
		if(!pathFound) cout << "YES" << '\n';
		exit(0);
	}

	if(turns > 2) return;
	
	if(sy > 0 && grid[sy-1][sx] != 1 && !visited[{sy-1, sx}])
	{
		visited[{sy-1, sx}] = true;
		if(last != 1) findPath(grid, sy-1, sx, vy, vx, 1, turns+1, visited);
		else findPath(grid, sy-1, sx, vy, vx, 1, turns, visited);
	}

	if(sy < grid.size()-1 && grid[sy+1][sx] != 1 && !visited[{sy+1, sx}])
	{
		visited[{sy+1, sx}] = true;
		if(last != 2) findPath(grid, sy+1, sx, vy, vx, 2, turns+1, visited);
		else findPath(grid, sy+1, sx, vy, vx, 2, turns, visited);
		
	}
	
	if(sx > 0 && grid[sy][sx-1] != 1 && !visited[{sy, sx-1}])
	{	
		visited[{sy, sx-1}] = true;
		if(last != 4) findPath(grid, sy, sx-1, vy, vx, 4, turns+1, visited);
		else findPath(grid, sy, sx-1, vy, vx, 4, turns, visited);
	}
	
	if(sx < grid[0].size()-1 && grid[sy][sx+1] != 1 && !visited[{sy, sx+1}])
	{
		visited[{sy, sx+1}] = true;
		if(last != 3) findPath(grid, sy, sx+1, vy, vx, 3, turns+1, visited);
		else findPath(grid, sy, sx+1, vy, vx, 3, turns, visited);
	}
	
	//return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	vector<vector<int>> grid;
	grid.resize(n, vector<int>(m, 0));
	
	int sx, sy, vx, vy;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char c; cin>>c;
			//cout << c << " ";
			if(c == '.') continue;
			if(c == '*') grid[i][j] = 1;
			if(c == 'S')
			{
				sx = j;
				sy = i;
			}
			if(c == 'T')
			{
				vx = j;
				vy = i;
			}
		}
	}
	
	
	
	/*
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	*/
	//cout << sy << " " << sx << endl;
	//cout << vy << " " << vx << endl;
	map<pair<int,int>, bool> visited;

	findPath(grid, sy, sx, vy, vx, 0, -1, visited);
	
	if(!pathFound) cout << "NO" << '\n';
	
	return 0;
}
