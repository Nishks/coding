#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

void solve() {
	int n;
	cin >> n;

	vector<int> a;

	for (int i = 0; i < n; i++) {
		int A;
		cin >> A;
		a.push_back(A);
	}

	int dp[n][2];
	dp[0][0] = !(a[0] & 1) ? 1 : 0; // dp[i][0] == dp[i][even]
	dp[0][1] = (a[0] & 1) ? 1 : 0; // dp[i][1] == dp[i][odd]

	dp[1][0] = (a[1] & 1) ? dp[0][1] : dp[0][0];
	dp[1][1] = (a[1] & 1) ? dp[0][0] : dp[0][1];

	for (int i = 2; i < n; i++) {
		if (a[i] & 1) {
			// odd number
			dp[i][0] = dp[i - 1][1] + dp[i - 2][1];
			dp[i][1] = dp[i - 1][0] + dp[i - 2][0];
		}
		else {
			// even number
			dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
			dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		}
	}

	cout << dp[n - 1][1] << endl;
}

int32_t main() {

// #ifndef ONLINE_JUDGE
// 	freopen('input.txt', 'r', stdin);
// 	freopen('output.txt', 'w', stdout);
// #endif

	int t = 1;
	while (t--) {
		solve();
	}
}