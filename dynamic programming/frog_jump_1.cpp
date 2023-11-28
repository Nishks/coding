#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

int solve() {
	int n;
	cin >> n;
	if(n == 0) return 0;
	vector<int> arr;
	for (auto i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}

	// dp array
	vector<int> dp(n);
	dp[0] = 0;
	dp[1] = dp[0] + abs(arr[1] - arr[0]);

	for (auto i = 2; i < dp.size(); i++) {
		dp[i] = min(dp[i - 1] + abs(arr[i - 1] - arr[i]), dp[i - 2] + abs(arr[i - 2] - arr[i]));
	}

	// cout << dp[n - 1] << endl;
	return dp[n-1];
}

int32_t main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int T = 1;
	while (T--) {
		cout << solve() << endl;
	}
}