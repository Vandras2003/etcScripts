#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

using namespace std;

int n, m , k;
bool ok = true;

void traverse(vector<vector<int>> grid, int x, int y, int dir, int seen)
{
	if(seen == m*n-k)
	{
		return;
	}
	
	if(dir == 1) 
	{
		while(y < m-1)
		{
			if(grid[x][y+1] == 1)
			{
				seen++;
				grid[x][y+1] = 0;
				y++;
			} else break;
		}
		
		if(seen == m*n-k) return;
		
		if(x < n-1 && grid[x+1][y] == 1)
		{
			grid[x+1][y] = 0;
			x++;
			seen++;
			traverse(grid, x, y, 2, seen);
		}
		 else
		{
			 ok = 0;
			 return;
		 }
	}
	
	if(dir == 2) 
	{
		while(x < n-1)
		{
			if(grid[x+1][y] == 1)
			{
				seen++;
				grid[x+1][y] = 0;
				x++;
			} else break;
		}
		
		if(seen == m*n-k) return;
		
		if(y > 0 && grid[x][y-1] == 1)
		{
			grid[x][y-1] = 0;
			y--;
			seen++;
			traverse(grid, x, y, 3, seen);
		}
		 else
		{
			 ok = 0;
			 return;
		 }
	}
	
	if(dir == 3) 
	{
		while(y > 0)
		{
			if(grid[x][y-1] == 1)
			{
				seen++;
				grid[x][y-1] = 0;
				y--;
			} else break;
		}
		if(seen == m*n-k) return;
		
		if(x > 0 && grid[x-1][y] == 1)
		{
			grid[x-1][y] = 0;
			x--;
			seen++;
			traverse(grid, x, y, 4, seen);
		} else
		{
			 ok = 0;
			 return;
		 }
	}
	
	if(dir == 4) 
	{
		while(x > 0)
		{
			if(grid[x-1][y] == 1)
			{
				seen++;
				grid[x-1][y] = 0;
				x--;
			} else break;
		}
		
		if(seen == m*n-k) return;
		
		if(y < n-1 && grid[x][y+1] == 1)
		{
			grid[x][y +1] = 0;
			y++;
			seen++;
			traverse(grid, x, y, 4, seen);
		}
		 else
		{
			 ok = 0;
			 return;
		 }
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	 cin >> n >> m >> k;
	
	vector<vector<int>> grid(n, vector<int>(m, 1));
	
	for(int i = 0; i < k; i++)
	{
		int x, y; cin >> x >> y;
		x--; y--;
		grid[x][y]  = 0;
	}
	
	grid[0][0] = 0;
	traverse(grid, 0,0,1,1);
	cout << ( ok ? "Yes" : "No") << '\n';
	
	return 0;
}
