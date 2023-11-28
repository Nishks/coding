#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int mod = 1e9+7;

void solve() {
	// Let's do it
	int n;
	cin >> n;

	vector<vector<char>> grid(n, vector<char>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n,0));

	
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--) {
		solve();
	}
}
