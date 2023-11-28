#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int mod = 1e9 + 7;

void solve() {
	// Let's do it
	int n;
	cin >> n;

	vector<vector<char>> grid(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
		cout << 0 << endl;
		return;
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[n-1][n-1] = 1;

	for (int j = n - 2; j >= 0; j--) {
		if (grid[n-1][j] == '.') dp[n-1][j] = dp[n-1][j+1];
	}
	

	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (grid[i][j] == '*') continue;
			dp[i][j] = ((j + 1 < n ? dp[i][j + 1] : 0) + dp[i + 1][j] % mod) % mod;
		}
	}

	cout << dp[0][0] % mod << endl;
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
