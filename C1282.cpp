#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back

#define pii pair<int, int>

using namespace std;

const int INF = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int m; cin >> m;
	while(m--)
	{
		ll n, t, a, b; cin >> n >> t >> a >> b;
        
        vector<pair<ll, ll>> v;
        
        vector<int> hard(n);
        
        int cntA = 0, cntB = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> hard[i];
            if (hard[i]) {
                cntB++;
            } else {
                cntA++;
            }
        }
     
        
        
	}
	
	return 0;
}
