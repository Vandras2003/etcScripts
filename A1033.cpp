#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_backs

using namespace std;



int main()
{
	//ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	vector<vector<int>> grid;
	grid.resize(n, vector<int>(n, 0));
	
	int ax, ay, bx, by, cx, cy;
	scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
	bool win = false;
	
	if(bx < ax && cx < ax && by > ay && cy > ay)
	{
		win = true;
	}
	
	if(bx > ax && cx > ax && by > ay && cy > ay)
	{
		win = true;
	}
	
	if(bx < ax && cx < ax && by < ay && cy < ay)
	{
		win = true;
	}
	
	if(bx > ax && cx > ax && by < ay && cy < ay)
	{
		win = true;
	}
	
	cout << (win ? "YES" : "NO") << '\n';
	
	return 0;
}
